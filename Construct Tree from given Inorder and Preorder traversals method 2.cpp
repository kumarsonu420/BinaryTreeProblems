
                                    //NOT PRODUCING THE CORRECT OUTPUT
#include<bits/stdc++.h>
#include<stdio.h>
#include<stdlib.h>
#include<stack>
#include<set>

using namespace std;
struct node
{
  char data;
  struct node* left;
  struct node* right;
};

struct node* newNode(char data)
{
  struct node* node = (struct node*)malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;

  return(node);
}
node* buildTree(char inorder[], char preorder[],int n)
{
    node* root=NULL,*temp;
    stack<node*>stk;
    set<node*>s;
    for(int pre=0,in=0;pre<n;pre++)
    {
        temp=NULL;
        do
        {
            temp=newNode(preorder[pre]);
            if(root==NULL)
                root=temp;
            if(!stk.empty())
            {
                if(s.find(stk.top())!=s.end())
                {
                    stk.top()->right=temp;
                    s.erase(stk.top());
                    stk.pop();
                }
                else
                    stk.top()->left=temp;
            }
            stk.push(temp);
        }while(preorder[pre++]!=inorder[in] && pre < n);

        temp=NULL;
        while(!stk.empty() && stk.top()->data==inorder[in] && in < n)
        {
            temp=stk.top();
            stk.pop();
            in++;
        }
        if(temp!=NULL)
        {
            stk.push(temp);
            s.insert(temp);
        }
    }
    return root;
}
void printInorder(struct node* node)
{
  if (node == NULL)
     return;
  printInorder(node->left);
  printf("%c ", node->data);
  printInorder(node->right);
}

int main()
{
  char in[] = {'D', 'B', 'E', 'A', 'F', 'C'};
  char pre[] = {'A', 'B', 'D', 'E', 'C', 'F'};
  int len = sizeof(in)/sizeof(in[0]);
  //method 1
  struct node *root = buildTree(in, pre,len);
  printf("Inorder traversal of the constructed tree is \n");
  printInorder(root);

}
