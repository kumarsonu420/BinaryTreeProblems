#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

int max(int inorder[], int strt, int end);

struct node* newNode(int data);

int max (int arr[], int strt, int end)
{
    int i, max = arr[strt], maxind = strt;
    for(i = strt+1; i <= end; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
            maxind = i;
        }
    }
    return maxind;
}

struct node* newNode (int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

node*  buildTree(int inorder[], int start, int end)
{
    if(start > end)
        return NULL;

    int index=max(inorder,start,end);

    node *root=newNode(inorder[index]);
    if(start==end)
        return root;

    root->left=buildTree(inorder,start,index-1);
    root->right=buildTree(inorder,index+1,end);

    return root;
}
void printInorder (struct node* node)
{
    if (node == NULL)
        return;

    printInorder (node->left);
    printf("%d ", node->data);
    printInorder (node->right);
}

int main()
{
    int inorder[] = {5, 10, 40, 30, 28};
    int len = sizeof(inorder)/sizeof(inorder[0]);
    struct node *root = buildTree(inorder, 0, len - 1);

    printf("\n Inorder traversal of the constructed tree is \n");
    printInorder(root);
    return 0;
}

