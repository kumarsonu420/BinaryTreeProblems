#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
struct node
{
    int data;
    node* left;
    node* right;
};

node* newNode(int data)
{
    node* new_node = new node;
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return (new_node);
}
node* Bt2Dll(node *root)
{
    if(root==NULL)
        return root;
    if(root->left)
    {
        node *left=Bt2Dll(root->left);

        while(left->right)
            left=left->right;
        root->left=left;
        left->right=root;
    }
    if(root->right)
    {
        node *right=Bt2Dll(root->right);
        while(right->left)
            right=right->left;
        root->right=right;
        right->left=root;
    }
    return root;
}
node* bintree2list(node *root)
{
    if(root==NULL)
        return root;
    root= Bt2Dll(root);
    while(root->left)
        root=root->left;
    return root;
}
void printList(node *node)
{
    while (node!=NULL)
    {
        printf("%d ", node->data);
        node = node->right;
    }
}
int main()
{
    node *root        = newNode(10);
    root->left        = newNode(12);
    root->right       = newNode(15);
    root->left->left  = newNode(25);
    root->left->right = newNode(30);
    root->right->left = newNode(36);

    node *head = bintree2list(root);
    printList(head);

    return 0;
}
