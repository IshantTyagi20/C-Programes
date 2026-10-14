#include<stdio.h>
#include<stdlib.h>



struct node{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *create_node(int n){
    struct node *temp, *new_node, *head;
    int data;
    if(n<=0){
        printf("This is invalid number...\n");
        return NULL;
    }
    head = (struct node*)malloc(sizeof(struct node));
    if(head == NULL){
        printf("Memory allocation failed...\n");
        return NULL;
    }
    printf("Enter the data of the 1 node: ");
    scanf("%d", &data);
    head->prev = NULL;
    head->data = data;
    head->next = NULL;

    temp = head;
    for(int i=2;i<=n;i++){
        new_node = (struct node*)malloc(sizeof(struct node));
        printf("Enter the data of the %d node: ",i);
        scanf("%d", &data);
        new_node->data = data;
        new_node->next = NULL;
        temp->next = new_node;
        new_node->prev = temp;
        temp = temp->next;
    }
    return head;

};

void print(struct node *head){
    struct node *temp;
    temp = head;
    while(temp!=NULL){
        printf("The data of the node is: %d\n",temp->data);
        temp = temp->next;
    }
    
}

void insert_at_beg(struct node **head){
    struct node *new_node;
    int data;
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the data to be inserted at beggining: ");
    scanf("%d",&data);
    new_node->prev = NULL;
    new_node->data = data;
    new_node->next = *head;

    if(*head!=NULL){
        (*head)->prev = new_node;
    }
    *head = new_node;

}

void insertion_at_end(struct node **head){
    struct node *temp, *new_node;
    int data;
    new_node = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter the data to be inserted at the end: ");
    scanf("%d",&data);

    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;
    temp = *head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->prev = temp;
}

void insert_at_pos(struct node **head){
    struct node *temp, *new_node;
    int data;
    int pos;
    printf("Enter the position you want to insert node: ");
    scanf("%d",&pos);
    if(pos<1){
        printf("Invalid number..\n");
        return;
    }
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data to be inserted at the position %d: ",pos);
    scanf("%d",&data);
    printf("\n...After inserting at the position...\n");

    new_node->data = data;
    temp = *head;
    if(*head==NULL){
        new_node->next = NULL;
        new_node->prev = NULL;
        *head = new_node;
        return;
    }
    if(pos==1){
        new_node->next = *head;
        new_node->prev = NULL;
        if(*head!=NULL){
            (*head)->prev = new_node;
        }
        *head = new_node;
        return;
    }
    
    for(int i=1;i<pos-1 && temp!=NULL ;i++){
        temp = temp->next;
    }
    new_node->next = temp->next;
    new_node->prev = temp;
    if(temp->next!=NULL){
        temp->next->prev = new_node;
    }
    temp->next = new_node;

}


int main(){
    int n=5;
    int pos;
    struct node *create = create_node(n);
    printf("\n...Original list...\n");
    print(create);
    printf("\n...After insertion...\n");
    insert_at_beg(&create);
    print(create);
    printf("\n...After insertion at the end...\n");
    insertion_at_end(&create);
    print(create);
    insert_at_pos(&create);
    print(create);
}