#include <stdio.h>
#include<stdlib.h>
typedef struct double_node{
    int data;
    struct double_node *left;
    struct double_node *right;
}tree_node;
void insert(tree_node **root,int item){
    tree_node *new = (tree_node*)malloc(sizeof(tree_node));
    new->data = item;
    new->left = NULL;
    new->right = NULL;
    if(*root == NULL) *root = new;
    else{
        tree_node *tracer;
        tracer = *root;
        tree_node *prev = tracer;
        while(tracer != NULL){
            while(tracer != NULL){
                if(item >= tracer->data) break;
                prev = tracer;
                tracer = tracer->left;
            }
            while(tracer != NULL){
                if(item <= tracer->data) break;
                prev = tracer;
                tracer = tracer->right;
            } 
        }
        if(item < prev -> data) prev->left = new;
        else 
            if(item > prev -> data) prev->right = new;
    }
}
void Display_Binary_tree(tree_node *root){
    if(root!=NULL){
        Display_Binary_tree(root->left);
        printf("%d -> ",root->data);
        Display_Binary_tree(root->right);
    }
}
void Check(tree_node *root,int *item){
    if(root!=NULL){
        if(*item == root->data) printf("\n%d is presnt in tree ",*item);
        else if(*item < root->data) Check(root->left,item);
        else Check(root->right,item);
    }
    else printf("\n%d is not present in tree ",*item);
}
int main()
{
    printf("Enter 1 to insert ");
    printf("\nEnter 2 to Display tree");
    printf("\nEnter 3 to Search ");
    printf("\nEnter 4 to Terminate program");
    tree_node *root;
    root = NULL;
    int item,choose,check;
    while(1){
        printf("\nChoose = ");
        scanf("%d",&choose);
        if(choose == 1){
            printf("\nEnter item to insert ");
            scanf("%d",&item);
            insert(&root,item);
        }
        if(choose == 2){
            if(root == NULL) printf("\nEmpty Binary Tree");
            else Display_Binary_tree(root);

        }
        if(choose == 3){
            printf("\nEnter item to Search in tree  ");
            scanf("%d",&item);
            Check(root,&item);
        }
        if(choose == 4) break;
    }
    return 0;
}

