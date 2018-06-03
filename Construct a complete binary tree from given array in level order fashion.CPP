#include <bits/stdc++.h>
#include <queue>
using namespace std;
struct Node
{
    int data;
    Node* left, * right;
};
Node* newNode(int data)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}

Node* insertLevelOrder(int arr[], Node* root,int k, int n)
{
    queue<Node*>q;
    root=newNode(arr[0]);
    q.push(root);
    int i=1;
    while(i<n)
    {
        q.front()->left=newNode(arr[i]);
        q.push(q.front()->left);
        i++;
        if(i<n)
        {
            q.front()->right=newNode(arr[i]);
            q.push(q.front()->right);
            i++;
            q.pop();
        }
    }
    return root;
}
void inOrder(Node* root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        cout << root->data <<" ";
        inOrder(root->right);
    }
}

int main()
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 6, 6, 6 };
    int n = sizeof(arr)/sizeof(arr[0]);
    Node* root = insertLevelOrder(arr, root, 0, n);
    inOrder(root);
}
