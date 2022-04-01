#include <stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node* next_node;
}node;
int recursive_count(node *head){
    if(head != NULL) return 1 + recursive_count(head->next_node);
    else return 0;
}
void List_count(node **head){
    node *new_node = (node*)malloc(sizeof(node));
    new_node = *head;
    int count = 0;
    while(new_node != NULL){
        count++;
        new_node = new_node -> next_node;
    }
    printf("\nLenght of list = %d",count);
}
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
void Link_search(node **head,int item){
    node *new_node = (node*)malloc(sizeof(int));
    new_node = *head;
    while(new_node != NULL){
        if(new_node->data == item){
            printf("\n%d is present in list ",item);
            return;
        }
        new_node = new_node -> next_node;
    }
    printf("\n%d not in list ",item);
}
void Insert_end(node **head,int item){
    node *new_node = (node*)malloc(sizeof(node));
    new_node->data = item;
    new_node->next_node = NULL;
    if(*head == NULL) *head = new_node;
    else{
        node *record = (node*)malloc(sizeof(node));
        record = *head;
        while(record->next_node != NULL){
            record = record->next_node;
        }
        record->next_node = new_node;
    }
}
void insert_into_sort(node **head,int item){
    node *prev_node = (node*)malloc(sizeof(node));
    prev_node = NULL;
    node *curr_node = (node*)malloc(sizeof(node));
    node *new = (node*)malloc(sizeof(node));
    curr_node = *head;
    while(curr_node -> data < item){
        prev_node = curr_node;
        curr_node = curr_node -> next_node;
        if(curr_node == NULL) break;
    }
    new -> data = item;
    new -> next_node = curr_node;
    if(prev_node !=NULL) prev_node -> next_node = new;
    else *head = new;
}
void Insert_after(node **head,int item,int after){
    node *curr_node = (node*)malloc(sizeof(node));
    node *prev_node = (node*)malloc(sizeof(node));
    curr_node = *head;
    while(curr_node -> data != after){
        curr_node = curr_node -> next_node;
    }
    if(curr_node !=NULL){
        prev_node -> data = item;
        prev_node->next_node = curr_node -> next_node;
        curr_node -> next_node = prev_node;
    }
    else printf("\nnumber %d is not present to insert %d ",after,item);
}
void Insert_before(node **head,int item,int before){
    node *prev_node = (node*)malloc(sizeof(node));
    prev_node = NULL;
    node *curr_node = (node*)malloc(sizeof(node));
    node *temp = (node*)malloc(sizeof(node));
    curr_node = *head;
    while(curr_node -> data != before){
        prev_node = curr_node;
        curr_node = curr_node -> next_node;
    }
    temp -> data = item;
    temp -> next_node = curr_node;
    if(prev_node !=NULL) prev_node -> next_node = temp;
    else *head = temp;
}
void delete_start(node **head){
    node *new = (node*)malloc(sizeof(node));
    new = *head;
    *head = new -> next_node;
    free(new);
}
void delete_end(node **head){
    if(*head!=NULL){
        node *record = (node*)malloc(sizeof(node));
        record = *head;
        int i;
        if(record->next_node!=NULL){
            node *new = (node*)malloc(sizeof(node));
            while(record -> next_node != NULL){
                new = record;
                record = record -> next_node;
            }
            i = record->data;
            new -> next_node = NULL;
            free(record);
        }
        else{
            i = record->data;
            free(record);
            *head = NULL;
        }
    }
}
void delete_list(node **head)
{
    node *prev_node = (node*)malloc(sizeof(node));
    node *use = (node*)malloc(sizeof(node));
    prev_node = *head;
    while(prev_node -> next_node != NULL){
        use = prev_node;
        prev_node = prev_node -> next_node;
        free(use);
    }
    free(prev_node);
    *head = NULL ;
}
void deletion_givennumber(node **head,int item){
    node *curr_node = (node*)malloc(sizeof(node));
    node *prev_node = (node*)malloc(sizeof(node));
    node *use = (node*)malloc(sizeof(node));
    node *reply = (node*)malloc(sizeof(node));
    curr_node = *head;
    reply = *head;
    while(curr_node -> next_node != NULL){
        if(reply -> data == item){
            use = reply;
            reply = reply -> next_node;
            *head = reply;
            free(use);
        }
        else if(curr_node -> data == item){
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
    if(curr_node -> data == item){
        use = curr_node;
        curr_node = curr_node -> next_node;
        prev_node -> next_node = curr_node; 
        free(use);
    }
}
void reverse_list(node **head){
    node *prev_node = (node*)malloc(sizeof(node)); 
    prev_node = NULL;
    node *curr_node = (node*)malloc(sizeof(node)); 
    curr_node = *head;
    node *next = (node*)malloc(sizeof(node));
    next = curr_node -> next_node;
    int i = 0;
    while(next != NULL){
        prev_node = curr_node;
        curr_node = next;
        next = curr_node -> next_node;
        curr_node -> next_node = prev_node;
        while(!i){
            prev_node -> next_node = NULL;
            i += 1;
        }
    }
    *head = curr_node;
}
int main()
{
    node *head;
    head = NULL;
    int i,item;
    printf("Enter 1 to insert at beginning ");
    printf("\nEnter 2 to display list ");
    printf("\nEnter 3 to append ");
    printf("\nEnter 4 to know length ");
    printf("\nEnter 5 to recursive length");
    printf("\nEnter 6 to search an element ");
    printf("\nEnter 7 to Insert after a number");
    printf("\nEnter 8 to Insert before a number");
    printf("\nEnter 9 to Insert into sorted List ");
    printf("\nEnter 10 to delelte at start ");
    printf("\nEnter 11 to delete at end ");
    printf("\nEnter 12 to delete list ");
    printf("\nEnter 13 to delete a number ");
    printf("\nEnter 14 to reverse the list ");
    printf("\nEnter 15 to end ");
    while(1){
        printf("\nChoose = ");
        scanf("%d",&i);
        switch(i){
            case 1: printf("\nEnter element to Insert at first ");
                    scanf("%d",&item);
                    Insert_begin(&head,item);
                    break;
            case 2: Display(&head);
                    break;
            case 3: printf("\nEnter element to Append ");
                    scanf("%d",&item);
                    Insert_end(&head,item);
                    break;
            case 4: List_count(&head);
                    break;
            case 5: printf("\nList lenght = %d",recursive_count(head));
                    break;
            case 6: if(head != NULL){
                    printf("\nEnter element to search ");
                    scanf("%d",&item);
                    Link_search(&head,item);
                    }
                    else{printf("List is empty cant search");}
                    break;
            case 7: if(head == NULL){
                        printf("\nList is empty");
                    }
                    else{
                        printf("\nEnter number to insert ");
                        scanf("%d",&item);
                        printf("\nEnter number After which number to add ");
                        int after;
                        scanf("%d",&after);
                        Insert_after(&head,item,after);
                    }
                    break;
            case 8:if(head == NULL){
                        printf("\nList is empty");
                    }
                    else{
                        printf("\nEnter number to insert ");
                        scanf("%d",&item);
                        printf("\nEnter number Before which number to add ");
                        int before;
                        scanf("%d",&before);
                        Insert_before(&head,item,before);
                    }
                    break;
            case 9:if(head == NULL){
                        printf("\nEnter number to insert into sorted list ");
                        scanf("%d",&item);
                        Insert_begin(&head,item);
                    }
                    else{
                        printf("\nEnter number to insert into sorted list ");
                        scanf("%d",&item);
                        insert_into_sort(&head,item);
                    }
                    break;
            case 10:if(head ==  NULL){
                        printf("\nCan't delete no elements are there ");
                    }
                    else delete_start(&head);
                    break;
            case 11: if(head ==  NULL){
                        printf("\nCan't delete no elements are there ");
                     }
                     else delete_end(&head);
                     break;
            case 12:if(head == NULL){
                        printf("List is already empty ");
                    }
                    else delete_list(&head);
                    break;
            case 13:if(head == NULL){
                        printf("List is empty cant delete anything ");
                    }
                    else {
                        printf("\nEnter number to delete ");
                        scanf("%d",&item);
                        deletion_givennumber(&head,item);
                    }
                    break;
            case 14:reverse_list(&head);
                    break;
            case 15: exit(0);
            default: printf("\nChoose correct Option");
        }
    }
    return 0;
}




