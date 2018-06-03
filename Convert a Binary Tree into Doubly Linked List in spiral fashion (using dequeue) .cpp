#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
};

void push(Node* node)
{
    node->left=node->right=NULL;

    static Node *tail=NULL;

    if(tail!=NULL)
    {
        tail->right=node;
        node->left=tail;
    }
    tail=node;
}

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->right;
    }
}

void spiralLevelOrder(Node *root)
{
    if(!root)
        return;
    deque<Node*>d;
    d.push_back(root);
    int level=1;
    while(1)
    {
        int nodecount=d.size();
        if(nodecount==0)
            return;
        if(level&1)
        {
            while(nodecount--)
            {
                Node *t=d.front();
                d.pop_front();
                push(t);
                if(t->right)
                    d.push_back(root->right);
                if(t->left)
                    d.push_back(root->left);
                }
        }
        else
        {
            while(nodecount--)
            {
                Node *t=d.back();
                d.pop_back();
                push(t);
                if(t->left)
                    d.push_front(t->left);
                if(t->right)
                    d.push_front(t->right);
            }
        }
        level++;
    }
}

Node* newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;

    return temp;
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
