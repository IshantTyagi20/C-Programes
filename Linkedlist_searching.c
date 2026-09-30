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



int search(struct node *head, int target){
    struct node *temp;
    temp = head;
    int pos = 1;
    while(temp!=NULL){
        if(temp->data==target){
            return pos;
        }
        temp = temp->link;
        pos++;
    }
    return -1;
}

int main(){
    int n = 4;
    struct node *create = create_list(n);
    print_node(create);
    int target = 78;
    

    int found_node = search(create,target);
    printf("%d",found_node);
    return 0;
}