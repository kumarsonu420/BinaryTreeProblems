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
void printReverseLevelOrder(Node* root)
{
    if(!root)
        return;
    stack<Node*>s;
    queue<Node*>q;
    q.push(root);
    while(!q.empty())
    {
        Node* temp=q.front();
        q.pop();
        s.push(temp);
         if(temp->right)
            q.push(temp->right);
         if(temp->left)
            q.push(temp->left);

    }
    while(!s.empty())
    {
        cout<<s.top()->data<<" ";
        s.pop();
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
//4 5 6 7 2 3 1
