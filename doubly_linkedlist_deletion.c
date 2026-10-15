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

void deletion_at_pos(struct node **head){
    struct node *temp = *head;
    int pos;
    printf("\nEnter the position you want to delete: ");
    scanf("%d",&pos);
    if(pos<=0){
        printf("Invalid number...\n");
        return;
    }
    if(*head==NULL){
        printf("List is empty...\n");
        return;
    }
    if(pos==1){
        *head = temp->next;
        if(*head!=NULL){
            (*head)->prev = NULL;
        }
        free(temp);
        return;
    }

    for(int i=1;i<pos && temp!=NULL;i++){
        temp = temp->next;
    }
    if(temp==NULL){
        printf("Node not available...\n");
        return;
    }
    if(temp->next!=NULL){
        temp->next->prev = temp->prev;

    }
    if(temp->prev!=NULL){
        temp->prev->next = temp->next;
    }
    free(temp);
    return;

}


int main(){
    int n=5;
    int pos;
    struct node *create = create_node(n);
    printf("\n...Original list...\n");
    print(create);
    printf("\n...After deleting the node...\n");
    deletion_at_pos(&create);
    print(create);
    return 0;
}