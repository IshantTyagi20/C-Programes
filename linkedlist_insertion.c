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



void add_ele_at_end(struct node *head , int data){
    struct node *temp, *ptr;
    ptr = head;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;
    while(ptr->link!=NULL){
        ptr = ptr->link;
    }
    ptr->link = temp;
}



int main(){
    int n = 4;
    int pos = 2;
    struct node *create = create_list(n);
    print_node(create);
    int data;
    printf("Enter data you want to store at the end : ");
    scanf("%d",&data);
    add_ele_at_end(create,data);
    print_node(create);
    return 0;
}