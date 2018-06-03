#include <stdio.h>
#include <bits/stdc++.h>
#include <stack>
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
node* bintree2list(node *root)
{
    node *head=NULL,*tail=NULL;
    stack<node*>stk;
    stk.push(root);
    while(!stk.empty())
    {
        node *t=stk.top();
        if(t->left)
        {
            stk.push(t->left);
            t->left=NULL;
        }
        else
        {
            stk.pop();
            if(t->right)
                stk.push(t->right);
            t->left = t->right=NULL;

            if(head==NULL)
            {
                head=t;
                tail=t;
            }
            else
            {
                tail->right=t;
                t->left=tail;
                tail=t;
            }
        }
    }
    return head;
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
