#include <bits/stdc++.h>
using namespace std;

// Structure of a node of an n-ary tree
struct Node {
    int key;
    vector<Node*> child;
};

// Utility function to create a new tree
// node with k children
Node* newNode(int value)
{
    Node* nNode = new Node;
    nNode->key = value;
    return nNode;
}

// Function to build full k-ary tree
Node* BuildKaryTree(int A[], int n, int k, int h, int& ind)
{
    // For null tree
    if (n <= 0)
        return NULL;

    Node* nNode = newNode(A[ind]);
    if (nNode == NULL) {
        cout << "Memory error" << endl;
        return NULL;
    }

    // For adding k children to a node
    for (int i = 0; i < k; i++) {

        // Check if ind is in range of array
        // Check if height of the tree is greater than 1
        if (ind < n - 1 && h > 1) {
            ind++;

            // Recursively add each child
            nNode->child.push_back(BuildKaryTree(A, n, k, h - 1, ind));
        } else {
            nNode->child.push_back(NULL);
        }
    }
    return nNode;
}

// Function to find the height of the tree
Node* BuildKaryTree(int* A, int n, int k, int ind)
{
    int height = (int)ceil(log((double)n * (k - 1) + 1)
                 / log((double)k));
    return BuildKaryTree(A, n, k, height, ind);
}

// Function to print postorder traversal of the tree
void postord(Node* root, int k)
{
    if (root == NULL)
        return;
    for (int i = 0; i < k; i++)
        postord(root->child[i], k);
    cout << root->key << " ";
}

// Driver program to implement full k-ary tree
int main()
{
    int ind = 0;
    int k = 3, n = 10;
    int preorder[] = { 1, 2, 5, 6, 7, 3, 8, 9, 10, 4 };
    Node* root = BuildKaryTree(preorder, n, k, ind);
    cout << "Postorder traversal of constructed"
             " full k-ary tree is: ";
    postord(root, k);
    cout << endl;
    return 0;
}

