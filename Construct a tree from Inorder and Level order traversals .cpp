#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

struct node
{
    int key;
    struct node* left, *right;
};
node* newNode(int key)
{
    node *t = new node;
    t->key = key;
    t->left = t->right = NULL;
    return (t);
}

int search(int arr[], int strt, int end, int value)
{
    for (int i = strt; i <= end; i++)
        if (arr[i] == value)
            return i;
    return -1;
}
int* extractKeys(int inorder[],int level[],int last,int n)
{
    int *arr=new int[last];
    int  t=0;
    for(int i=0;i<n;i++)
        if(search(inorder,0,last-1,level[i])!=-1)
            arr[t++]=level[i];
    return arr;
}
node* buildTree(int inorder[],int level[],int start,int last,int n)
{

    if(start>last)
        return NULL;

    node *root=newNode(level[0]);

    if(start==last)
        return root;

    int l=search(inorder,start,last,level[0]);

    int *levl=extractKeys(inorder,level,l,n);
    int *levr=extractKeys(inorder+l+1,level,n-l-1,n);

    root->left=buildTree(inorder,levl,start,l-1,n);
    root->right=buildTree(inorder,levr,l+1,last,n);

    delete []levl;
    delete []levr;


    return root;
}

void printInorder(node* node)
{
    if (node == NULL)
       return;
    printInorder(node->left);
    cout << node->key << " ";
    printInorder(node->right);
}

/* Driver program to test above functions */
int main()
{
    int in[]    = {4, 8, 10, 12, 14, 20, 22};
    int level[] = {20, 8, 22, 4, 12, 10, 14};
    int n = sizeof(in)/sizeof(in[0]);
    node *root = buildTree(in, level, 0, n - 1, n);

    cout << "Inorder traversal of the constructed tree is \n";
    printInorder(root);

    return 0;
}
