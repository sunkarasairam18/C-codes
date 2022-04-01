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
int Check_For_Delete(tree_node *root,int *item){
    if(root!=NULL){
        if(*item == root->data) return 1;
        else if(*item < root->data) return Check_For_Delete(root->left,item);
        else return Check_For_Delete(root->right,item);
    }
    else return 0;
}
void Delete(tree_node **root,int *item){
    if(*root == NULL) printf("\nBINARY SEARCH TREE IS EMPTY ");
    else{
        if(Check_For_Delete(*root,item)){
            tree_node *new_root;
            new_root = *root;
            tree_node *prev_new_root;
            if(new_root->left != NULL || new_root->right != NULL){
                if(new_root->data != *item){
                    while(new_root!=NULL){
                        if(*item < new_root->data){
                            prev_new_root = new_root;
                            new_root = new_root->left; 
                        }
                        else if(*item == new_root->data){
                            if(new_root->left == NULL && new_root->right == NULL){
                                if(*item < prev_new_root->data) prev_new_root->left = NULL;
                                else prev_new_root->right = NULL;
                                free(new_root);
                                new_root = NULL;
                            }
                            else if(new_root->left == NULL && new_root->right != NULL){
                                if(*item < prev_new_root->data) prev_new_root->left = new_root->right;
                                else prev_new_root->right = new_root->right;
                                free(new_root);
                                new_root = NULL;
                            }
                            else if(new_root->left != NULL && new_root->right == NULL){
                                if(*item < prev_new_root->data) prev_new_root->left = new_root->left;
                                else prev_new_root->right = new_root->left;
                                free(new_root);
                                new_root = NULL;
                            }
                            else{
                                tree_node *temporary = new_root->left;
                                tree_node *sec_temporary = new_root;
                                while(temporary->right!= NULL){
                                    sec_temporary = temporary;
                                    temporary = temporary->right;
                                }
                                new_root->data = temporary->data;
                                if(sec_temporary != new_root) sec_temporary->right = temporary->left;
                                else sec_temporary->left = temporary->left;
                                temporary->left = NULL;
                                free(temporary);   
                                temporary = NULL;
                            }
                        }
                        else{
                            prev_new_root = new_root;
                            new_root = new_root->right;
                        }
                    }
                }
                else{
                    if(new_root->left == NULL && new_root->right != NULL){
                        *root = new_root->right;
                        free(new_root);
                        new_root = NULL;
                    }
                    else if(new_root->left != NULL && new_root->right == NULL){
                        *root = new_root->left;
                        free(new_root);
                        new_root = NULL;
                    }
                    else{
                        tree_node *temporary = new_root->left;
                        tree_node *sec_temporary = new_root;
                        while(temporary->right!= NULL){
                            sec_temporary = temporary;
                            temporary = temporary->right;
                        }
                        new_root->data = temporary->data;
                        if(sec_temporary != new_root) sec_temporary->right = temporary->left;
                        else sec_temporary->left = temporary->left;
                        temporary->left = NULL;
                        free(temporary);   
                        temporary = NULL;
                    }
                }
            }
            else{
                *root = NULL;
                free(new_root);
                new_root = NULL;
            }
        }
        else printf("\nItem is not present in tree to delete");
    }
}
int main()
{
    printf("Enter 1 to insert ");
    printf("\nEnter 2 to Display tree");
    printf("\nEnter 3 to Search ");
    printf("\nEnter 4 to delete item ");
    printf("\nEnter 5 to Terminate program");
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
        if(choose == 3){
            if(root == NULL) printf("\nBINARY SEARCH TREE IS EMPTY");
            else{
                printf("\nEnter item to Search in tree  ");
                scanf("%d",&item);
                Check(root,&item);
            }
        }
        if(choose == 4){
            printf("\nEnter item to Delete ");
            scanf("%d",&item);
            Delete(&root,&item);
        }
        if(choose == 5) break;
    }
    return 0;
}
