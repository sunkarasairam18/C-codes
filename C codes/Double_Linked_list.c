#include <stdio.h>
#include<stdlib.h>
typedef struct Double_link{
    int data;
    struct Double_link *prev;
    struct Double_link *next;
}double_link;
void Enque(double_link **head,double_link **tail,int item){
    double_link *new = (double_link*)malloc(sizeof(double_link));
    new->data = item;
    if(*head == NULL && *tail == NULL){
        new->prev = NULL;
        new->next = NULL;
        *head = new;
        *tail = new;
    }
    else{
        double_link *trace;
        trace = *head;
        while(trace->next!=NULL){
            trace=trace->next;
        }
        new -> prev = trace;
        trace->next = new;
        new->next = NULL;
        *tail = new;
    }
}
void Deque(double_link **head,double_link **tail){
    if(*head == NULL) printf("QUEUE IS EMPTY");
    else{
        double_link *new;
        new = *head;
        if(new->next != NULL){
            *head = new->next;
            free(new);
            new = *head;
            new->prev = NULL;
        } 
        else{
            free(new);
            *head = NULL;
            *tail = NULL;
        }
        
    }
}
void Display(double_link **head){
    if(*head==NULL) printf("QUEUE IS EMPTY NOW");
    else{
        double_link *trace;
        trace = *head;
        printf("<- ");
        while(trace!=NULL){
            printf("%d <- ",trace->data);
            trace = trace->next;
        }
    }
}
void Reverse_Display(double_link **tail){
    if(*tail==NULL) printf("QUEUE is empty");
    else{
        double_link *trace;
        trace = *tail;
        printf("-> ");
        while(trace!=NULL){
            printf("%d -> ",trace->data);
            trace = trace->prev;
        }
    }
}
int main()
{
    double_link *head;
    double_link *tail;
    head = NULL;
    tail = NULL;
    int item,choose;
    while(1){
        printf("\nChoose = ");
        scanf("%d",&choose);
        if(choose == 1){
            printf("Enter item to Enque ");
            scanf("%d",&item);
            Enque(&head,&tail,item);
            Display(&head);
        }
        if(choose == 2){
            Deque(&head,&tail);
            Display(&head);
        } 
        if(choose == 4) Reverse_Display(&tail);
        if(choose == 5) break;
    }
    return 0;
}

