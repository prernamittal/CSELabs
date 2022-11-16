#include <stdio.h>
#include <stdlib.h>
struct node
{
    int coeff;
    int exp;
    struct node *link;
};
typedef struct node *node;
node create()
{
    node x;
    x = (node) malloc(sizeof(struct node));
    return x;
}
node attach(int coeff, int exp, node head)
{
    node temp, curr;
    temp = create();
    temp->coeff = coeff;
    temp->exp = exp;
    curr = head->link;
    while(curr->link != head)
    {
        curr = curr->link;
    }
    curr->link = temp;
    temp->link = head;
    return head;
}
node input(node head)
{
    int i,coeff,exp;
    printf("\nEnter 101 to end");
    while(i)
    {
        printf("\nEnter coeff = ");
        scanf("%d", &coeff);
        if(coeff == 101)
            break;
        printf("\nEnter exp = ");
        scanf("%d", &exp);
        head = attach(coeff, exp, head);
    }
        return head;
}

node add(node node1, node node2, node node3)
{
    node x,y;
    int coeff;
    x = node1->link;
    y = node2->link;
    while((x != node1)&&(y != node2))
    {
        if(x->exp == y->exp)
        {
            coeff = x->coeff + y->coeff;
            if(coeff != 0)
                        node3 = attach(coeff, x->exp, node3);
            x = x->link;
            y = y->link;
        }
        else if(x->exp > y->exp)
        {
            node3 = attach(x->coeff, x->exp, node3);
            x = x->link;
        }
        else
        {
            node3 = attach(y->coeff, y->exp, node3);
            y = y->link;
        }
    }
    while(x != node1)
    {
        node3 = attach(x->coeff, x->exp, node3);
        x = x->link;
    }
    while(y != node2)
    {
        node3 = attach(y->coeff, y->exp, node3);
        y = y->link;
    }
    return node3;
}

void display(node head)
{
    node temp;
    if(head->link == head)
    {
        printf("\nInvalid poly");
        return;
    }
    temp = head->link;
    while(temp != head)
    {
        printf("%dx^%d",temp->coeff, temp->exp);
        temp = temp->link;
        if(temp != head)
            printf(" + ");
    }
}

void main()
{
        node node1, node2, node3;
        node1 = create();
        node2 = create();
        node3 = create();
        node1->link=node1;
        node2->link=node2;
        node3->link=node3;
        printf("\nEnter first poly: ");
        node1 = input(node1);
        printf("\nEnter second poly");
        node2 = input(node2);
        node3 = add(node1, node2, node3);
        printf("\npoly 1:\t");
        display(node1);
        printf("\npoly 2:\t");
        display(node2);
        printf("\npoly result:\t");
        display(node3);
}