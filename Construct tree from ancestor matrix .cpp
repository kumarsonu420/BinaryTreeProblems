#include <bits/stdc++.h>
#include<unordered_set>
using namespace std;
# define N 6

struct Node
{
    int data;
    Node *left, *right;
};

Node* newNode(int data)
{
    Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}

Node* ancestorTree(int mat[N][N])
{
    Node *root;
    multimap<int,int>s;
    for(int i=0;i<N;i++)
    {
        int sum=0;
        for(int j=0;j<N;j++)
            sum+=mat[i][j];
        s.insert(pair<int,int>(sum,i));
    }
    Node *node[N];
    bool parent[N]={false};

    for(auto it=s.begin();it!=s.end();it++)
    {
        node[it->second]=newNode(it->second);
        root = node[it->second];
        if(it->first > 0)
        {
            for(int i=0;i<N;i++)
            {
                if(!parent[i] && mat[it->second][i])
                {
                    parent[i]=true;
                    if(node[it->second]->left==NULL)
                        node[it->second]->left=node[i];
                    else
                        node[it->second]->right=node[i];
                }
            }
        }
    }

    return root;
}
void printInorder(Node* node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}

int main()
{
    int mat[N][N] = {{ 0, 0, 0, 0, 0, 0 },
                    { 1, 0, 0, 0, 1, 0 },
                    { 0, 0, 0, 1, 0, 0 },
                    { 0, 0, 0, 0, 0, 0 },
                    { 0, 0, 0, 0, 0, 0 },
                    { 1, 1, 1, 1, 1, 0 }
                    };

    Node* root = ancestorTree(mat);
    cout << "Inorder traversal of tree is \n";
    printInorder(root);
    return 0;
}
