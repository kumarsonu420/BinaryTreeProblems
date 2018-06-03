#include<stdio.h>
#include<stack>

using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node* newNode (int data)
{
    struct node *temp = new struct node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
node* constructTree (int pre[], char preLN[],int n)
{
    stack<node*>stk;
    node* root=NULL;
    for(int i=0;i<n;i++)
    {
        if(root==NULL)
        {
            root=newNode(pre[i]);
            if(preLN[i]=='N')
                stk.push(root);
        }
        else
        {
            node *t=newNode(pre[i]);
            if(!stk.empty())
            {
                if(stk.top()->left==NULL)
                    stk.top()->left=t;
                else
                {
                    stk.top()->right=t;
                    stk.pop();
                }
                if(preLN[i]=='N')
                        stk.push(t);
            }
        }
    }
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
struct node *constructTreeUtil(int pre[], char preLN[], int *index_ptr, int n)
{
    int index = *index_ptr;

    if (index == n)
        return NULL;

    struct node *temp = newNode ( pre[index] );
    (*index_ptr)++;

    if (preLN[index] == 'N')
    {
      temp->left  = constructTreeUtil(pre, preLN, index_ptr, n);
      temp->right = constructTreeUtil(pre, preLN, index_ptr, n);
    }


    return temp;
}

struct node *constructsTree(int pre[], char preLN[], int n)
{

    int index = 0;

    return constructTreeUtil (pre, preLN, &index, n);
}
int main()
{
    struct node *root = NULL;

    int pre[] = {10, 30, 20, 5, 15};
    char preLN[] = {'N', 'N', 'L', 'L', 'L'};
    int n = sizeof(pre)/sizeof(pre[0]);

    root = constructTree (pre, preLN, n);
    //method 2
    node* root1=constructsTree(pre,preLN,n);
    // Test the constructed tree
    printf("Following is Inorder Traversal of the Constructed Binary Tree: \n");
    printInorder (root);
    printf("\n methdo 2: \n");
    printInorder (root1);
    return 0;
}
