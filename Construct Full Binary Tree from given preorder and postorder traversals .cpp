#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node* newNode (int data)
{
    struct node* temp = (struct node *) malloc( sizeof(struct node) );

    temp->data = data;
    temp->left = temp->right = NULL;

    return temp;
}

node* constructTreeUtil(int pre[],int post[],int *prevIndex,int first,int last,int n)
{
    if(*prevIndex>n || first>last)
        return NULL;

    node *root=newNode(pre[*prevIndex]);
    ++*prevIndex;
    if(first==last)
        return root;
        int i;
    for(i=first;i<=last;i++)
        if(pre[*prevIndex]==post[i])
            break;
    if(i<=last)
    {
        root->left=constructTreeUtil(pre,post,prevIndex,first,i,n);
        root->right=constructTreeUtil(pre,post,prevIndex,i+1,last,n);
    }
    return root;
}
node*  constructTree(int pre[], int post[],int sz)
{
    if(sz<0)
        return NULL;
    if(sz==1)
        return newNode(post[0]);
    int i=0;
        return constructTreeUtil(pre,post,&i,0,sz-1,sz);
}
void printInorder (struct node* node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}

int main ()
{
    int pre[] = {1, 2, 4, 8, 9, 5, 3, 6, 7};
    int post[] = {8, 9, 4, 5, 2, 6, 7, 3, 1};
    int sz = sizeof( pre ) / sizeof( pre[0] );

    struct node *root = constructTree(pre, post, sz);

    printf("Inorder traversal of the constructed tree: \n");
    printInorder(root);

    return 0;
}

