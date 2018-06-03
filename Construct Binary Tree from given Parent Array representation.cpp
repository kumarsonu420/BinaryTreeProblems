#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    struct Node *left, *right;
};

Node *newNode(int key)
{
    Node *temp = new Node;
    temp->key  = key;
    temp->left  = temp->right = NULL;
    return (temp);
}

Node *createTree(int parent[], int n)
{
    Node *node[n],*root;

    for(int i=0;i<n;i++)
        node[i]=newNode(i);

    for(int i=0;i<n;i++)
    {
        if(parent[i]==-1)
            root=node[i];
        else
            if(node[parent[i]]->left==NULL)
                node[parent[i]]->left=node[i];
            else
                node[parent[i]]->right=node[i];
    }
    return root;
}

inline void newLine(){
    cout << "\n";
}

void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

int main()
{
    int parent[] =  {-1, 0, 0, 1, 1, 3, 5};
    int n = sizeof parent / sizeof parent[0];
    Node *root = createTree(parent, n);
    cout << "Inorder Traversal of constructed tree\n";
    inorder(root);
    newLine();
}

