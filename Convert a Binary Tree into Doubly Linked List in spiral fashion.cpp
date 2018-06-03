#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
};

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->right;
    }
}

Node* newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;

    return temp;
}
void spiralLevelOrder(Node *root)
{
    stack<Node*>s1,s2;
    s1.push(root->right);
    s1.push(root->left);
    root->left=root->right=NULL;
    while(!s1.empty() || !s2.empty())
    {
        while(!s1.empty())
        {
            Node *t=s1.top();
            s1.pop();
            if(t->left)
                s2.push(t->left);
            if(t->right)
                s2.push(t->right);
            t->left=t->right=NULL;
            root->right=t;
            t->left=root;
            root=t;
        }

        while(!s2.empty())
        {
            Node *t=s2.top();
            s2.pop();
            if(t->right)
                s1.push(t->right);
            if(t->left)
                s1.push(t->left);
            t->left=t->right=NULL;
            root->right=t;
            t->left=root;
            root=t;
        }
    }
}
int main()
{
    Node *root =  newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->left->left->left  = newNode(8);
    root->left->left->right  = newNode(9);
    root->left->right->left  = newNode(10);
    root->left->right->right  = newNode(11);
    root->right->left->right  = newNode(13);
    root->right->right->left  = newNode(14);

    spiralLevelOrder(root);
    printList(root);
    return 0;
}
