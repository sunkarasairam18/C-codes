#include <stdio.h>
#include<stdlib.h>
typedef struct Node
{
  int data;
  struct Node *next_node;
} node;
void Insert_begin (node ** head, int item)
{
  node *new_node = (node *) malloc (sizeof (node));
  new_node->data = item;
  if (*head == NULL)
    new_node->next_node = NULL;
  else
    new_node->next_node = *head;
  *head = new_node;
}

void Insert_end (node ** head, int item)
{
  node *new_node = (node *) malloc (sizeof (node));
  new_node->data = item;
  new_node->next_node = NULL;
  if (*head == NULL)
    *head = new_node;
  else
    {
      node *record = (node *) malloc (sizeof (node));
      record = *head;
      while (record->next_node != NULL)
	{
	  record = record->next_node;
	}
      record->next_node = new_node;
    }
}

void Display (node ** head)
{
  node *new_node = (node *) malloc (sizeof (node));
  new_node = *head;
  if (*head == NULL)
    {
      printf ("\nList is empty");
    }
  else
    {
      while (new_node != NULL)
	{
	  printf ("%d -> ", new_node->data);
	  new_node = new_node->next_node;
	}
	printf ("NULL");
    }
}

void concate (node ** head_one, node ** head_two)
{
  node *record = (node *) malloc (sizeof (node));
  record = *head_one;
  if (record != NULL)
    {
      while (record->next_node != NULL)
	{
	  record = record->next_node;
	}
      record->next_node = *head_two;
    }
  else
    *head_one = *head_two;
}
void Merge(node **head_one,node **head_two){
    node *one;
    one = *head_one;
    node *two;
    two = *head_two;
    node *head,*trace,*new;
    trace = NULL;
    while(one!=NULL || two!=NULL){
        new = (node*)malloc(sizeof(node));
        if(one == NULL){
            new -> data = two->data;
            new -> next_node = NULL;
            if(trace == NULL){
                head = new;
                trace = head;
            }
            else{
                trace -> next_node = new;   
                trace = trace -> next_node;
            }
            two = two->next_node;
        }
        else if(two == NULL){
            new -> data = one->data;
            new -> next_node = NULL;
            if(trace == NULL){
                head = new;
                trace = head;
            }
            else{
                trace -> next_node = new;   
                trace = trace -> next_node;
            }
            one = one->next_node;
        }
        else if(one->data < two->data){
            new -> data = one->data;
            new -> next_node = NULL;
            if(trace == NULL){
                head = new;
                trace = head;
            }
            else{
                trace -> next_node = new;   
                trace = trace -> next_node;
            }
            one = one->next_node;
        }
        else{
            new -> data = two->data;
            new -> next_node = NULL;
            if(trace == NULL){
                head = new;
                trace = head;
            }
            else{
                trace -> next_node = new;   
                trace = trace -> next_node;
            }
            two = two->next_node;
        }
    }
    Display(&head);
}
int main ()
{
  node *head_one;
  head_one = NULL;
  node *head_two;
  head_two = NULL;
  int item, i;
  printf ("\nEnter 11 to add element at head of first list ");
  printf ("\nEnter 12 to add element at end of first list ");
  printf ("\nEnter 21 to add element at head of second list ");
  printf ("\nEnter 22 to add element at end of second list ");
  printf("\nEnter 3 to Merge second Node to first Node ");
  printf ("\nEnter 4 to concate both ");
  printf("\nEnter 5 Exit ");
  while (1)
    {
      printf ("\nChoose = ");
      scanf ("%d", &i);
      switch (i)
	{
	case 11:
	  printf ("\nEnter item to insert at head first list ");
	  scanf ("%d", &item);
	  Insert_begin (&head_one, item);
	  printf ("\nFirst list ");
	  Display (&head_one);
	  break;
	case 12:
	  printf ("\nEnter item to insert at end of first list ");
	  scanf ("%d", &item);
	  Insert_end (&head_one, item);
	  printf ("\nFirst list ");
	  Display (&head_one);
	  break;
	case 21:
	  printf ("\nEnter item to insert at head of second list ");
	  scanf ("%d", &item);
	  Insert_begin (&head_two, item);
	  printf ("\nSecond list ");
	  Display (&head_two);
	  break;
	case 22:
	  printf ("\nEnter item to insert at end of secondlist ");
	  scanf ("%d", &item);
	  Insert_end (&head_two, item);
	  printf ("\nSecond list ");
	  Display (&head_two);
	  break;
	case 3: Merge(&head_one,&head_two);
	        break;
	case 4:
	  printf ("\nSecond Node Concated with first Node");
	  concate (&head_one, &head_two);
	  printf ("\nFirst list ");
	  Display (&head_one);
	  break;
	case 5:exit (0);
	}
    }
  return 0;
}

