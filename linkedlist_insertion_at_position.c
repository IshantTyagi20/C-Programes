#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *link;
};

struct node *create_list(int n){
    struct node *temp, *new_node, *head;
    int newdata;

    head = (struct node*)malloc(sizeof(struct node));

    printf("Enter the data of the first node : ");
    scanf("%d",&newdata);

    head->data = newdata;
    head->link = NULL;

    temp = head;

    for(int i=2;i<=n;i++){
        new_node = (struct node*)malloc(sizeof(struct node));

        printf("Enter the data of the %d node: ",i);
        scanf("%d",&newdata);

        new_node->data = newdata;
        new_node->link = NULL;

        temp->link = new_node;
        temp = temp->link;
        
    }
    return head;
}

void print_node(struct node *head){
    struct node *temp = head;
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
}


struct node *add_btwn(struct node *head, int data , int pos){
    struct node *temp, *new_node;
    new_node = (struct node*)malloc(sizeof(struct node));

    new_node->data = data;
    new_node->link = NULL;

    if(pos == 1){
        new_node->link = head;
        return new_node;
    }

    temp = head;

    for(int i=1;i<pos-1 && temp!=NULL;i++){
        temp = temp->link;
    }

    new_node->link=temp->link;
    temp->link=new_node;

    return head;


}

int main(){
    int n = 4;
    int pos = 2;
    struct node *create = create_list(n);
    print_node(create);
    
    int data = 99;

    create = add_btwn(create,data,pos);
    print_node(create);
    return 0;

    

}