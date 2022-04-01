#include <stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data,balance;
    struct Node *left;
    struct Node *right;
}tree_node;
void Display_Binary_tree(tree_node *root){
    if(root!=NULL){
        Display_Binary_tree(root->left);
        printf("\n      %d     %d",root->data,root->balance);
        Display_Binary_tree(root->right);
    }
}
int Height_Node(tree_node *node){
    if(node == NULL) return 0;
    int left = Height_Node(node->left);
    int right = Height_Node(node->right);
    return (right>left)?(right+1):(left+1);
}
void Check(tree_node *root,int *item){
    if(root!=NULL){
        if(*item == root->data) printf("\n%d is presnt in tree ",*item);
        else if(*item < root->data) Check(root->left,item);
        else Check(root->right,item);
    }
    else printf("\n%d is not present in tree ",*item);
}
tree_node* Return_Node(tree_node *node,int item){
    while(node != NULL){
        if(node->data == item) return node;
        else if(node->data > item) node = node->left;
        else node = node -> right;
    }
    return NULL;
}
void Calculate_Balance(tree_node *root){
    if(root != NULL){
        root->balance = Height_Node(root->left) - Height_Node(root->right);
        Calculate_Balance(root->left);
        Calculate_Balance(root->right);
    }
}
void Left_Rotate(tree_node **root,tree_node *prev_unbalance,tree_node *recent_unbalance){
    if(prev_unbalance != recent_unbalance){
        tree_node *Right = recent_unbalance->right;
        prev_unbalance->right = Right;
        recent_unbalance->right = Right -> left;
        Right -> left = recent_unbalance;   
    }else{
        *root = recent_unbalance->right;
        tree_node *new;
        new = *root;
        recent_unbalance->right = new -> left;
        new -> left = recent_unbalance;   
    }
}
void Right_Rotate(tree_node **root,tree_node *prev_unbalance,tree_node *recent_unbalance){
    if(prev_unbalance != recent_unbalance){
        tree_node *Left = recent_unbalance->left;
        prev_unbalance->left = Left;
        recent_unbalance->left = Left -> right;
        Left -> right = recent_unbalance;   
    }else{
        *root = recent_unbalance->left;
        tree_node *new;
        new = *root;
        recent_unbalance->left = new -> right;
        new -> right = recent_unbalance;   
    }
}
void Left_Right_Rotate(tree_node **root,tree_node *prev_unbalance,tree_node *recent_unbalance){
    tree_node *new = recent_unbalance->left;
    recent_unbalance->left = new->right;
    new->right = recent_unbalance->left->left;
    recent_unbalance->left->left = new;
    Right_Rotate(root,prev_unbalance,recent_unbalance);
}
void Right_Left_Rotate(tree_node **root,tree_node *prev_unbalance,tree_node *recent_unbalance){
    tree_node *new = recent_unbalance->right;
    recent_unbalance->right = new->left;
    new->left = recent_unbalance->right->right;
    recent_unbalance->right->right = new;
    Left_Rotate(root,prev_unbalance,recent_unbalance);
}
void AVL_Balance(tree_node **root,int item){
    if(*root == NULL) return;
    tree_node *prev,*prev_unbalance,*recent_unbalance;
    prev = *root;
    tree_node *tracer = prev;
    prev_unbalance = prev;
    recent_unbalance = prev;
    while(tracer!=NULL){
        if(tracer->balance > 1 || tracer->balance <-1){
            prev_unbalance = prev;
            recent_unbalance = tracer;
        }
        if(tracer->data == item) break; 
        else if(tracer->data < item){
            prev = tracer;
            tracer = tracer->right;
        }
        else{
            prev = tracer;
            tracer = tracer->left;
        } 
    }
    if(recent_unbalance->balance > 1 || recent_unbalance->balance <-1){
        if(Height_Node(recent_unbalance->right)>Height_Node(recent_unbalance->left) && Height_Node(recent_unbalance->right->right)>=Height_Node(recent_unbalance->right->left)){
            Left_Rotate(root,prev_unbalance,recent_unbalance);   //right right case 
        }
        else if(Height_Node(recent_unbalance->left)>Height_Node(recent_unbalance->right) && Height_Node(recent_unbalance->left->left)>=Height_Node(recent_unbalance->left->right)){
            Right_Rotate(root,prev_unbalance,recent_unbalance);  //left left case 
        }else if(Height_Node(recent_unbalance->left)>Height_Node(recent_unbalance->right) && Height_Node(recent_unbalance->left->right)>Height_Node(recent_unbalance->left->left)){
            Left_Right_Rotate(root,prev_unbalance,recent_unbalance);  //left right case 
        }else{
            if(Height_Node(recent_unbalance->right)>Height_Node(recent_unbalance->left) && Height_Node(recent_unbalance->right->left)>Height_Node(recent_unbalance->right->right)){
                Right_Left_Rotate(root,prev_unbalance,recent_unbalance); //right left case   
            }
        }
        Calculate_Balance(*root);
    }
}
void insert(tree_node **root,int item){
    tree_node *new = (tree_node*)malloc(sizeof(tree_node));
    new->data = item;
    new->left = NULL;
    new->right = NULL;
    if(*root == NULL){
        new->balance = 0;
        *root = new;
    } 
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
            Calculate_Balance(*root);
            AVL_Balance(root,*item);
        }
        else printf("\nItem is not present in tree to delete");
    }
}
int main()
{
   printf("Enter 1 to insert ");
    printf("\nEnter 2 to Display tree");
    printf("\nEnter 3 to Search ");
    printf("\nEnter 4 to Delete ");
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
            Calculate_Balance(root);
            AVL_Balance(&root,item);
        }
        else if(choose == 2){
            if(root == NULL) printf("\nBINARY SEARCH TREE IS EMPTY");
            else{
                printf("\n  Value   Balance_Factor ");
                Display_Binary_tree(root);
            } 
        }
        else if(choose == 3){
            if(root == NULL) printf("\nBINARY SEARCH TREE IS EMPTY");
            else{
                printf("\nEnter item to Search in tree  ");
                scanf("%d",&item);
                Check(root,&item);
            }
        }
        else if(choose == 4){
            if(root == NULL) printf("\nBINARY SEARCH TREE IS EMPTY");
            else{
                printf("\nEnter item to Delete ");
                scanf("%d",&item);
                Delete(&root,&item);
            }
        }
        else
            if(choose == 5) break;
    }
    return 0;
}
