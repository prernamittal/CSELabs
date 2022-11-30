#include <stdio.h>
#include <stdlib.h> 
struct node {
    char data;
    struct node *lchild;
    struct node *rchild;
};
int top=-1;
struct node *stack[20];
struct node *node; 
void push(struct node* node) {
    stack[++top] = node;
}
struct node * pop() {
    return (stack[top--]);
}
int op(struct node *node) {
    int choice;
    choice = check(node->data);
    if (choice == 1)
        return node->data - 48;
    else if (choice == 2) {
        if (node->data == '+')
            return op(node->lchild) + op(node->rchild);
        if (node->data == '-')
            return op(node->lchild) - op(node->rchild);
        if (node->data == '*')
            return op(node->lchild) * op(node->rchild);
        if (node->data == '/')
            return op(node->lchild) / op(node->rchild);
    }
}
int check(char choice) {
    if (choice=='+'||choice=='-'||choice=='/'||choice=='*')
        return 1;
    else
        return 2;
}
void operand(char c) {
    node = (struct node*) malloc(sizeof(struct node));
    node->data = c;
    node->lchild = NULL;
    node->rchild = NULL;
    push(node);
}
void operator(char a) {
    node = (struct node*) malloc(sizeof(struct node));
    node->data = a;
    node->rchild = pop();
    node->lchild = pop();
    push(node);
}
int main() {
    char exp[20];
    printf("\nEnter postfix exp: ");
    scanf("%d[^\n]", exp);
    for (int i=0; exp[i]!='\0';i++) {
        int flag=check(exp[i]);
        if(flag==2)
            operand(exp[i]);
        else if(flag==1)
            operator(exp[i]);
    }
    int result = op(stack[top]);
    printf("\nResult: ", result);
    return 0;
}