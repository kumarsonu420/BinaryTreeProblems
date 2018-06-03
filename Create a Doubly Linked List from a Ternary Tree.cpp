#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *middle, *right;
};

Node* newNode(int data)
{
    Node* node = new Node;
    node->data = data;
    node->left = node->middle = node->right = NULL;
    return node;
}
void push(Node *root,Node **tail)
{
    root->left = root->middle = root->right = NULL;
    if(*tail!=NULL)
    {
        (*tail)->right=root;
        root->left=*tail;
    }
    *tail=root;
}
void TernaryTreeToList(Node *root,Node **head)
{
    if(root==NULL)
        return;

    Node *left=root->left;
    Node *middle=root->middle;
    Node *right=root->right;

    static Node *tail=NULL;
    if(*head==NULL)
        *head=root;
    push(root,&tail);

    TernaryTreeToList(left,head);
    TernaryTreeToList(middle,head);
    TernaryTreeToList(right,head);
}
void printList(Node* head)
{
    printf("Created Double Linked list is:\n");
    while (head)
    {
        printf("%d ", head->data);
        head = head->right;
    }
}

int main()
{
    Node* root = newNode(30);

    root->left = newNode(5);
    root->middle = newNode(11);
    root->right = newNode(63);

    root->left->left = newNode(1);
    root->left->middle = newNode(4);
    root->left->right = newNode(8);

    root->middle->left = newNode(6);
    root->middle->middle = newNode(7);
    root->middle->right = newNode(15);

    root->right->left = newNode(31);
    root->right->middle = newNode(55);
    root->right->right = newNode(65);

    Node* head = NULL;
    TernaryTreeToList(root, &head);
    printList(head);
    return 0;
}
