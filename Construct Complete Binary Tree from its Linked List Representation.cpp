#include <iostream>
#include <string>
#include <queue>
#include <stdlib.h>
using namespace std;

// Linked list node
struct ListNode
{
    int data;
    ListNode* next;
};

// Binary tree node structure
struct BinaryTreeNode
{
    int data;
    BinaryTreeNode *left, *right;
};

void push(ListNode **head,int data)
{
    ListNode *temp=(ListNode*)malloc(sizeof(ListNode));
    temp->data=data;
    temp->next=*head;
    *head=temp;
}
BinaryTreeNode* newnode(int data)
{
    BinaryTreeNode *temp=(BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
    temp->data=data;
    temp->left=temp->right=NULL;
    return temp;
}
void convertList2Binary(ListNode *head, BinaryTreeNode **root)
{
    queue<BinaryTreeNode*>q;
    *root=newnode(head->data);
    q.push(*root);
    head=head->next;
    while(head)
    {
        q.front()->left=newnode(head->data);
        q.push(q.front()->left);
        head=head->next;
        if(head)
        {
            q.front()->right=newnode(head->data);
            q.push(q.front()->right);
            head=head->next;
            q.pop();
        }
    }
}
void inorderTra versal(BinaryTreeNode* root)
{
    if (root)
    {
        inorderTraversal( root->left );
        cout << root->data << " ";
        inorderTraversal( root->right );
    }
}

int main()
{
    // create a linked list shown in above diagram
    struct ListNode* head = NULL;
    push(&head, 36);  /* Last node of Linked List */
    push(&head, 30);
    push(&head, 25);
    push(&head, 15);
    push(&head, 12);
    push(&head, 10); /* First node of Linked List */

    BinaryTreeNode *root;
    convertList2Binary(head, &root);

    cout << "Inorder Traversal of the constructed Binary Tree is: \n";
    inorderTraversal(root);
    return 0;
}
