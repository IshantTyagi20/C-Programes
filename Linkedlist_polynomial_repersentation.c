#include<stdio.h>
#include<stdlib.h>
struct poly {
    int coef;
    int expo;
    struct poly *link;
};

struct poly *insert(struct poly *head, int coef, int expo){
    struct poly *temp, *new_node;
    new_node = (struct poly *)malloc(sizeof(struct poly));
    new_node->coef = coef;
    new_node->expo = expo;
    new_node->link = NULL;
    if(head==NULL){
        head=new_node;
    }else{
        temp = head;
        while(temp->link!=NULL){
            temp = temp->link;
        }
        temp->link = new_node;
    }
    return head;
}

void print_poly(struct poly *head){
    struct poly *temp;
    temp = head;
    while(temp!=NULL){
        printf("%dx^%d",temp->coef, temp->expo);

        temp = temp->link;
        if(temp!=0 && temp->coef>=0){
            printf("+");
        }
    }
    printf("\n");
}

int main(){
    int n = 4;
    int pos = 2;
    struct poly *head = NULL;
    head = insert(head,4,2);
    head = insert(head,-9,1);
    head = insert(head,6,0);

    print_poly(head);

    return 0;

}
