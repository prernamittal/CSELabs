#include <stdio.h>
#include <stdlib.h>
struct node 
{
    int data;
    struct node *lchild;
    struct node *rchild;
};
struct node* create(int val)
{
    struct node* new=malloc(sizeof(struct node));
    new->data=val;
    new->lchild=NULL;
    new->rchild=NULL;
    return new;
}
void inorder(struct node* root)
{
    if(root!=NULL)
    {
        inorder(root->lchild);
        printf("%d ",root->data);
        inorder(root->rchild);
    }
}
void postorder(struct node* root)
{
    if(root!=NULL)
    {
        postorder(root->lchild);
        postorder(root->rchild);
        printf("%d ",root->data);
    }
}
void preorder(struct node* root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preorder(root->lchild);
        preorder(root->rchild);
    }
}
int main()
{
    int val,choice;
    printf("Enter root: ");
    scanf("%d",&val);
    struct node* root=create(val);
    do
    {
        printf("\n1.Insert Left\n2.Insert Right\n3.Traversal\n4.Exit\nEnter choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("\nEnter val to insert left: ");
            scanf("%d", &val);
            root->lchild=create(val);
            break;
            case 2:
            printf("\nEnter val to insert right: ");
            scanf("%d", &val);
            root->rchild=create(val);
            break;
            case 3:
            printf("\nInorder traversal: ");
            inorder(root);
            printf("\nPreorder traversal: ");
            preorder(root);
            printf("\nPostorder traversal: ");
            postorder(root);
            break;
        }
    }while(choice!=4);
}