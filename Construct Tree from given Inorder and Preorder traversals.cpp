#include<stdio.h>
#include<stdlib.h>

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
int finds(char in[],char x,int s,int e)
{
    for(int i=s;i<=e;i++)
        if(in[i]==x)
            return i;
    return -1;
}
node* buildTree(char in[], char pre[],int start,int last)
{
    if(start>last)
        return NULL;
    static int previndex=0;
    node *root=newNode(pre[previndex]);

    int loc=finds(in,pre[previndex++],start,last);
    if(start==last)
        return root;

    root->left=buildTree(in,pre,start,loc-1);
    root->right=buildTree(in,pre,loc+1,last);

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
  struct node *root = buildTree(in, pre, 0, len - 1);
  printf("Inorder traversal of the constructed tree is \n");
  printInorder(root);

}
