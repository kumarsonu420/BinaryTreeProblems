#include<bits/stdc++.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
struct tNode
{
   int data;
   struct tNode* left;
   struct tNode* right;
};

void inOrder(struct tNode *root)
{
    if(root==NULL)
        return;
    tNode* curr=root;
    bool done =false;
    stack<tNode*>st;
    while(!done)
    {
        if(curr)
        {
            st.push(curr);
            curr=curr->left;
        }
        else
        {
            if(!st.empty())
            {
                tNode* t=st.top();
                st.pop();
                cout<<t->data;
                curr=t->right;
            }
            else
                done=true;
        }
    }
}

struct tNode* newtNode(int data)
{
  struct tNode* tNode = (struct tNode*)
                       malloc(sizeof(struct tNode));
  tNode->data = data;
  tNode->left = NULL;
  tNode->right = NULL;

  return(tNode);
}
int main()
{

  /* Constructed binary tree is
            1
          /   \
        2      3
      /  \
    4     5
  */
  struct tNode *root = newtNode(1);
  root->left        = newtNode(2);
  root->right       = newtNode(3);
  root->left->left  = newtNode(4);
  root->left->right = newtNode(5);

  inOrder(root);
  return 0;
}
