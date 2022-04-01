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
void Big_in_BT(tree_node *root){
    if(root == NULL) printf("\nBINARY SEARCH TREE IS EMPTY");
    else{
        while(root->right!=NULL){
            root = root->right;
        }
        printf("\nBIGGEST ELEMENT IN TREE IS %d",root->data);
    }
}
int main()
{
    printf("Enter 1 to insert ");
    printf("\nEnter 2 to Display tree");
    printf("\nEnter 3 to Find Biggest element in Tree");
   printf("\nEnter 4 to Terminate ");
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
            if(root == NULL) printf("\nBINARY SEARCH TREE IS EMPTY");
            else Display_Binary_tree(root);
        }
        else if(choose == 3){
            Big_in_BT(root);
        }
        else 
            if(choose == 4) break;
    }
    return 0;
}


