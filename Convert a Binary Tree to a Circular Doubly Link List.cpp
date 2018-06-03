
#include <iostream>
using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
};
node* newNode(int data)
{
    node* new_node = new node;
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return (new_node);
}
void BinaryTree2CircularDoubleLinkedList(node *root, node **head)
{
    if(!root)
        return;
    static node *prev=NULL;
    BinaryTree2CircularDoubleLinkedList(root->left,head);

    if(*head==NULL)
        *head=root;
    else
    {
        root->left=prev;
        prev->right=root;
    }
    prev=root;
    BinaryTree2CircularDoubleLinkedList(root->right,head);
}

void displayCList(node *head)
{
    cout << "Circular Linked List is :\n";
    node *itr = head;
    do
    {
        cout << itr->data <<" ";
        itr = itr->right;
    } while (head!=itr);
    cout << "\n";
}
void makeListCircular(node *head)
{
    node *temp=head;
    while(temp->right)
        temp=temp->right;
    head->left=temp;
    temp->right=head;
}
int main()
{
    node *root        = newNode(10);
    root->left        = newNode(12);
    root->right       = newNode(15);
    root->left->left  = newNode(25);
    root->left->right = newNode(30);
    root->right->left = newNode(36);

    node *head = NULL;
    BinaryTree2CircularDoubleLinkedList(root, &head);
    makeListCircular(head);
    displayCList(head);
    return 0;
}
