#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

struct Node* newNode(int data)
{
    struct Node *temp = new struct Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void printLevelOrder(Node *root)
{
    if (root == NULL)  return;
    queue<Node *> q;
    q.push(root);
    while (1)
    {
        int nodeCount = q.size();
        if (nodeCount == 0)
            break;
        while (nodeCount > 0)
        {
            Node *node = q.front();
            cout << node->data << " ";
            q.pop();
            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);
            nodeCount--;
        }
        cout << endl;
    }
}
Node* flipBinaryTree(Node *root)
{
    if(!root || !root->left && !root->right)
        return root;
    Node *flippedroot=flipBinaryTree(root->left);
    if(root->left)
    {
        root->left->left=root->right;
        root->left->right=root;
    }
    root->left=root->right=NULL;
    return flippedroot;
}
int main()
{
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->right->left = newNode(4);
    root->right->right = newNode(5);

    cout << "Level order traversal of given tree\n";
    printLevelOrder(root);

    root = flipBinaryTree(root);

    cout << "\nLevel order traversal of the flipped"
            " tree\n";
    printLevelOrder(root);
    return 0;
}
