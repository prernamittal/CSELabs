#include <stdio.h>
#include <stdlib.h>
struct node{
    int val;
    struct node *left, *right;
};
typedef struct node* Node;
Node createnode(int key){
    Node root = (Node)malloc(sizeof(struct node));
    root->val = key;
    root->left = NULL;
    root->right = NULL;
    return(root);
}
int search(Node head, int key){
    while (head != NULL){
        if (key > head->val)
            return search(head->right, key);
        else if (key < head->val)
            return search(head->left, key);
        else
            return 1;
    }
    return 0;
}
Node insert(Node node, int val){
    if (node == NULL)
    return createnode(val);
    if (val < node->val)
    node->left = insert(node->left, val);
    else if (val > node->val)
    node->right = insert(node->right, val);
    return node;
}
void preorder(Node node){
    if(node == NULL)
    return;
    else{
        printf("%d ", node->val);
        preorder(node->left);
        preorder(node->right);
    }
}
void postorder(Node node){
    if(node == NULL)
    return;
    else{
        postorder(node->left);
        postorder(node->right);
        printf("%d ", node->val);
    }
}
void inorder(Node node){
    if(node == NULL)
    return;
    else{
        inorder(node->left);
        printf("%d ", node->val);
        inorder(node->right);
    }
}
int main(){
    int flag = 0, inputnode;
    Node root = createnode(25);
    root->left = createnode(17);
    root->right = createnode(35);
    root->left->left = createnode(13);
    root->left->right = createnode(19);
    root->right->left = createnode(27);
    root->right->right = createnode(55);
    printf("Enter key to be searched: ");
    scanf("%d",&inputnode);
    flag = search(root,inputnode);
    if (flag)
        printf("Key %d found in tree\n",inputnode);
    else{
        printf("Key %d not found in tree\nInserting new val in tree...\n",inputnode);
        insert(root, inputnode);
    }
    printf("\nInorder traversal is: ");
    inorder(root);
    printf("\nPreorder traversal is: ");
    preorder(root);
    printf("\nPostorder traversal is: ");
    postorder(root);
}