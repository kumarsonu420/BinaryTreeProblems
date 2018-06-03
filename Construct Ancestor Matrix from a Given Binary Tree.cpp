#include<bits/stdc++.h>
using namespace std;
#define MAX 100

struct Node
{
    int data;
    Node *left, *right;
};

bool mat[MAX][MAX];

int  ancestorMatrixRec(Node *root,vector<int>anc)
{
    if(root==NULL)
        return 0;
    for(int i=0;i<anc.size();i++)
    {
        mat[anc[i]][root->data]=1;
    }
    anc.push_back(root->data);
    int l = ancestorMatrixRec(root->left, anc);
    int r = ancestorMatrixRec(root->right, anc);
    anc.pop_back();
    return l+r+1;
};
void ancestorMatrix(Node *root)
{
    vector<int> anc;
    int n = ancestorMatrixRec(root, anc);

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}

Node* newnode(int data)
{
    Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}

int main()
{
    Node *root        = newnode(5);
    root->left        = newnode(1);
    root->right       = newnode(2);
    root->left->left  = newnode(0);
    root->left->right = newnode(4);
    root->right->left = newnode(3);

    ancestorMatrix(root);
    return 0;
}
