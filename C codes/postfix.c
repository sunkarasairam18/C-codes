#include <stdio.h>
#include<string.h>
void push(char *a,int *top,int size,char item){
    if(*top != size -1){
        a[++*top] = item;
    }
}
int is_character(char c){
    int i;
    char list[6] = {'(',')','+','-','*','/'};
    for(i = 0;i<6;i++){
        if(c == list[i]) return 1;
    }
    return 0;
}
int higher_precedence(char c,char d){
    char list[5] = {'(','+','-','*','/'};
    int i,j,ind;
    for(i = 0;i<4;i++)
        if(c == list[i]) break;
    for(j = 0;j<4;j++)
        if(d == list[j]) break;
    if(j>i) ind = 1;
    else ind = 0;
    return ind;
}
int main()
{
    char current_symbol[20];
    printf("Enter String ");
    scanf("%s",current_symbol);
    int i,j,top_operator = -1,top_postfix = -1;
    i = strlen(current_symbol);
    char operator_stack[i];
    char postfix_string[i];
    for(j = 0;j<i;j++)
    {
        if(is_character(current_symbol[j])){
            if(current_symbol[j] == '(') push(operator_stack,&top_operator,i,'(');
            else if(current_symbol[j] == ')'){
                while(operator_stack[top_operator] != '('){
                    postfix_string[++top_postfix] = operator_stack[top_operator--];
                }
                top_operator--;
            }
            else{
                if(top_operator != -1){
                    if(higher_precedence(operator_stack[top_operator],current_symbol[j]) && top_operator != -1) push(operator_stack,&top_operator,i,current_symbol[j]);
                    else{
                        while(!higher_precedence(operator_stack[top_operator],current_symbol[j])){
                            push(postfix_string,&top_postfix,i,operator_stack[top_operator--]);
                            if(top_operator == -1) break;
                        }
                        push(operator_stack,&top_operator,i,current_symbol[j]);
                    }
                }
                else push(operator_stack,&top_operator,i,current_symbol[j]);
            }
        }
        else push(postfix_string,&top_postfix,i,current_symbol[j]);
    }
    while(top_operator != -1){
        postfix_string[++top_postfix] = operator_stack[top_operator--];
    }
    printf("\n");
    printf("Post fix %s",postfix_string);
    
    return 0;
}
