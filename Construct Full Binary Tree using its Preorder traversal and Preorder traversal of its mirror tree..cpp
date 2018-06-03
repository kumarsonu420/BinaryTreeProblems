#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
};

Node* newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void printInorder(Node* node)
{
    if (node == NULL)
        return;

    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}
Node* constructBinaryTreeUtil(int preOrder[],int preOrderMirror[],int *prevIndex,int first,int last,int size)
{
    if(*prevIndex>size || first>last)
        return NULL;
    Node *root=newNode(preOrder[*prevIndex]);
    ++*prevIndex;
    if(first==last)
        return root;
    int i;
    for(i=first;i<=last;i++)
        if(preOrderMirror[i]==preOrder[*prevIndex])
            break;
    if(i<=last)
    {
        root->left=constructBinaryTreeUtil(preOrder, preOrderMirror,prevIndex,i,last,size);
        root->right=constructBinaryTreeUtil(preOrder, preOrderMirror,prevIndex,first,i-1,size);
    }

    return root;
}
Node* constructBinaryTree(int preOrder[],int preOrderMirror[],int size)
{
    if(size<0)
        return NULL;
    int prevIndex=0;
    return constructBinaryTreeUtil(preOrder, preOrderMirror,&prevIndex,0,size-1,size);
}
int main()
{
    int preOrder[] = {1,2,4,5,3,6,7};
    int preOrderMirror[] = {1,3,7,6,2,5,4};

    int size = sizeof(preOrder)/sizeof(preOrder[0]);

    Node* root = new Node;

    root=constructBinaryTree(preOrder,preOrderMirror,size);
    printInorder(root);
    return 0;
}
