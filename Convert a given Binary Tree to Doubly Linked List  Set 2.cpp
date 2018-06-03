#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct node
{
    int data;
    struct node *left, *right;
};

struct node *newNode(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = node->right = NULL;
    return(node);
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("\t%d",root->data);
        inorder(root->right);
    }
}
void fixleftptr(node *root)
{
    if(root==NULL)
        return;
    static node *prev=NULL;

    fixleftptr(root->left);
    root->left=prev;
    prev=root;
    fixleftptr(root->right);
}
node* fixrightptr(node* root)
{
    node *next=NULL;
    while(root->left)
    {
        root->right=next;
        next=root;
        root=root->left;
    }
    root->right=next;
    return root;
}
node* BTToDLL(node *root)
{
    if(!root)
        return root;
    fixleftptr(root);
    while(root->right)
        root=root->right;
    return fixrightptr(root);
}
void printList(struct node *root)
{
    while (root != NULL)
    {
        printf("\t%d", root->data);
        root = root->right;
    }
}

int main(void)
{
    struct node *root = newNode(10);
    root->left        = newNode(12);
    root->right       = newNode(15);
    root->left->left  = newNode(25);
    root->left->right = newNode(30);
    root->right->left = newNode(36);

    printf("\n\t\tInorder Tree Traversal\n\n");
    inorder(root);

    struct node *head = BTToDLL(root);

    printf("\n\n\t\tDLL Traversal\n\n");
    printList(head);
    return 0;
}
