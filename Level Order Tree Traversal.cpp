#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left, *right;
};

Node** createQueue(int *front,int *rear)
{
    *front=0;
    *rear=0;
    Node** queue=(Node**)malloc(sizeof(Node*)*1000);
    return queue;
}
void enQueue(Node** queue,int* rear,Node* temp_node)
{
     queue[*rear]=temp_node;
    (*rear)++;
}
Node* deQueue(Node** queue,int *front,int *rear)
{
    if(*front==*rear)
        return NULL;
    return queue[(*front)++];
}
void levelOrder(Node* node)
{
    if(node==NULL)return;

    int front,rear;
    Node** queue=createQueue(&front,&rear);
    Node* temp_node=node;
    while(temp_node!=NULL)
    {
        cout<<temp_node->data<<" ";
        if(temp_node->left)
            enQueue(queue,&rear,temp_node->left);
        if(temp_node->right)
            enQueue(queue,&rear,temp_node->right);
        temp_node=deQueue(queue,&front,&rear);
    }
}
struct Node* newNode(int data)
{
    struct Node* node = (struct Node*)
                        malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return(node);
}

int main()
{
    struct Node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(5);
    root->left->left  = newNode(4);
    root->left->right = newNode(3);

    printf("Level Order traversal of binary tree is \n");
    levelOrder(root);
    return 0;
}
