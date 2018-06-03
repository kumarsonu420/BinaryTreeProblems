#include <iostream>
#include <queue>
#include <stack>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
};
Node *newNode(int data)
{
    Node *node = new Node;
    node->data = data;
    node->right = node->left = NULL;
    return node;
}
int height(Node* root)
{
    if(!root)
        return 0;
    int lh=height(root->left);
    int rh=height(root->right);

    if(lh>rh)
        return(lh+1);
    return(rh+1);
}
void print(Node* root,int level)
{
    if(level==1)
    {
        cout<<root->data<<" ";
        return;
    }
    if(root->left)
        print(root->left,level-1);
    if(root->right)
        print(root->right,level-1);
}
void printReverseLevelOrder(Node* root)
{
    if(!root)return;
    int h=height(root);
    for(int i=h;i>=1;i--)
    {
        print(root,i);
    }

}
int main()
{
    Node* root = newNode(1);

    root->left = newNode(2);
    root->right = newNode(3);

    root->left->left  = newNode(4);
    root->left->right = newNode(5);
    root->right->left  = newNode(6);
    root->right->right = newNode(7);

    cout << "Specific Level Order traversal of binary tree is \n";
    printReverseLevelOrder(root);
    return 0;
}
