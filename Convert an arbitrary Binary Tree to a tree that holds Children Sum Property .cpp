#include <stdio.h>
#include <stdlib.h>
using namespace std;
struct node
{
  int data;
  struct node* left;
  struct node* right;
};
void printInorder(struct node* node)
{
  if (node == NULL)
    return;
  printInorder(node->left);
  printf("%d ", node->data);
  printInorder(node->right);
}

struct node* newNode(int data)
{
  struct node* node =
      (struct node*)malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}
void increament(int data,node *root)
{
    if(root->left)
    {
        root->left->data +=data;
        increament(data,root->left);
    }
    else if(root->right)
    {
        root->right->data +=data;
        increament(data,root->right);
    }
}
void convert(node* root)
{
    if(!root || !root->left && !root->right)
        return ;
    int ldata=0,rdata=0,diff;

    convert(root->left);
    convert(root->right);

    if(root->left)
        ldata=root->left->data;
    if(root->right)
        rdata=root->right->data;

    diff=(root->data)-(ldata+rdata);

    if(diff<0)
        root->data =ldata+rdata;
    else
        increament(diff,root);
}
int main()
{
  struct node *root = newNode(50);
  root->left        = newNode(7);
  root->right       = newNode(2);
  root->left->left  = newNode(3);
  root->left->right = newNode(5);
  root->right->left  = newNode(1);
  root->right->right = newNode(30);

  printf("\n Inorder traversal before conversion ");
  printInorder(root);

  convert(root);

  printf("\n Inorder traversal after conversion ");
  printInorder(root);
  return 0;
}
