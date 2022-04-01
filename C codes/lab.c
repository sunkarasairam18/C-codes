#include <stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node* next_node;
}node;
void Insert_begin(node **head,int item){
    node *new_node = (node*)malloc(sizeof(node));
    new_node->data = item;
    if(*head == NULL) new_node->next_node = NULL;
    else new_node->next_node = *head; 
    *head = new_node;
}
void Display(node **head){
    node *new_node = (node*)malloc(sizeof(node));
    new_node = *head;
    if(*head == NULL) {
        printf("\nList is empty");
    }
    else{
    printf("\n");
    while(new_node != NULL){
        printf("%d -> ",new_node->data);
        new_node = new_node -> next_node;
    }
    printf("NULL");
    }
}
void deletion_givennumber(node **head){
    node *curr_node = (node*)malloc(sizeof(node));
    node *prev_node = (node*)malloc(sizeof(node));
    node *use = (node*)malloc(sizeof(node));
    node *reply = (node*)malloc(sizeof(node));
    curr_node = *head;
    reply = *head;
    while(curr_node -> next_node != NULL){
        if(reply -> data % 2){
            use = reply;
            reply = reply -> next_node;
            *head = reply;
            free(use);
        }
        else if(curr_node -> data%2){
            use = curr_node;
            curr_node = curr_node -> next_node;
            prev_node -> next_node = curr_node;
            free(use);
        }
        else{
            prev_node = curr_node;
            curr_node = curr_node -> next_node;
        }
    }
    if(curr_node -> data%2){
        use = curr_node;
        curr_node = curr_node -> next_node;
        prev_node -> next_node = curr_node; 
        free(use);
    }
}
int main()
{
    node *head;
    head = NULL;
    int i,item;
    printf("Enter 1 to insert at beginning ");
    printf("\nEnter 2 to delete odd numbers  ");
    while(1){
        printf("\nChoose = ");
        scanf("%d",&i);
        switch(i){
            case 1: printf("\nEnter element to Insert at first ");
                    scanf("%d",&item);
                    Insert_begin(&head,item);
                    Display(&head);
                    break;
            case 2:if(head == NULL){
                        printf("List is empty cant delete anything ");
                    }
                    else {
                        deletion_givennumber(&head);
                    }
                    Display(&head);
                    exit(0);
            default: printf("\nChoose correct Option");
        }
    }
    return 0;
}




