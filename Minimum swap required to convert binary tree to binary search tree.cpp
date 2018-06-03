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

void fillVector(Node *root,vector<int>&vec)
{
    if(!root)
        return;
    fillVector(root->left,vec);
    vec.push_back(root->data);
    fillVector(root->right,vec);
}
int countMinimumSwap(Node *root)
{
    vector<int>vec;
    fillVector(root,vec);
    int cnt=0,index,mn;
    for(int j=0;j<vec.size();j++)
    {
        index=j;
        mn=vec[j];
        for(int i=j+1;i<vec.size();i++)
        {
            if(mn > vec[i])
            {
                index=i;
                mn=vec[i];
            }
        }
        if(index!=j)
        {
            swap(vec[index],vec[j]);
            cnt++;
        }
    }
    return cnt;
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
    Node *root =  newNode(5);
    root->left = newNode(6);
    root->right = newNode(7);
    root->left->left = newNode(8);
    root->left->right = newNode(9);
    root->right->left = newNode(10);
    root->right->right = newNode(11);
    cout<<countMinimumSwap(root);
    return 0;
}

