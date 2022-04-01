#include <stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node* next_node;
}node;
struct Hash_Table{
    node *index[10];
};
void Hash_Insert(node **head,int item){
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
void CreateHashtable(struct Hash_Table *Table){
    for(int i = 0;i<10;i++){
        Table->index[i] = NULL;
    }
}
void Display(node **head){
    node *new_node = (node*)malloc(sizeof(node));
    new_node = *head;
    
    while(new_node != NULL){
        printf("-> %d ",new_node->data);
        new_node = new_node -> next_node;
    }
}

void DisplayHashTable(struct Hash_Table *Table){
    for(int i = 0;i<10;i++){
        printf("[%d] ",i);
        Display(&Table->index[i]);
        printf("\n");
    }
}
int main()
{
    struct Hash_Table Table;
    CreateHashtable(&Table);
    int choose,collisions = 0,item,hash_index;
    printf("Enter 1 to Insert");
    printf("\nEnter 2 to view hash table");
    printf("\nEnter 3 to terminate");
    while(1){
        printf("\nChoose = ");
        scanf("%d",&choose);
        if(choose == 1){
            printf("Enter Number to insert = ");
            scanf("%d",&item);
            hash_index = item%9;
            if(Table.index[hash_index]!=NULL) collisions++;
            Hash_Insert(&Table.index[hash_index],item);
        }
        else if(choose == 2) DisplayHashTable(&Table);
        else
            if(choose == 3){
                printf("\nNumber of collisions are %d",collisions);
                break;
            } 
    }
    return 0;
}
