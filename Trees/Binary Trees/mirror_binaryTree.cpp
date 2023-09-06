#include<iostream>
using namespace std;
 
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void printTree(Node *root)
{
    if(!root)
        return;

    cout << root->data << " ";

    printTree(root->left);
    printTree(root->right);
}

Node* invertTree(Node* root) {
    // 1. swap left & right sides of tree, using preorder traversal
    if(!root)
        return NULL;

    Node *temp = root->left;
    root->left = root->right;
    root->right = temp;

    invertTree(root->left);
    invertTree(root->right);
        
    // return root of tree as it is
    return root;
}

int main()
{
    // https://leetcode.com/problems/invert-binary-tree/description/

    // Q. mirror means left side becomes right side & right side becomes left side

    // Tree looks like:            o/p: 1 3 5 6 4 2
    //             1
    //           /  \
    //         2     3
    //              /  \
    //            4     5
    //                /
    //              6

    // mirrored Tree: 
    //             1
    //           /  \
    //         3    2
    //        / \
    //      5    4
    //       \
    //        6


    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(5);
    root->right->right->left = new Node(6);         

    root = invertTree(root);

    printTree(root);
}