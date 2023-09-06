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

bool IsFoldableUtil(Node *n1, Node *n2) 
{
    //if both left and right subtrees are NULL then we return true.
    if (n1 == NULL && n2 == NULL) 
        return true;

    //if one of the trees is NULL and other is not then we return false.
    if (n1 == NULL || n2 == NULL) 
        return false;

    //else we check recursively if left and right subtrees are 
    //mirrors of their counterparts.
    return IsFoldableUtil(n1->left,n2->right)&&IsFoldableUtil(n1->right,n2->left);
}

// time: O(N)  space: O(height), (for skewed tree: s/c = O(N) for balanced tree: s/c = O(logN))
bool IsFoldable(Node *root) 
{
    if (root == NULL)
        return true;
    
    return IsFoldableUtil(root->left, root->right);
}

int main()
{
    // https://practice.geeksforgeeks.org/batch/dsa-4/track/DSASP-Tree/problem/foldable-binary-tree

    // Q. 

    // Tree looks like:            o/p: false
    //             1
    //           /  \
    //         2     3
    //              /  \
    //            4     5
    //                /
    //              6

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(5);
    root->right->right->left = new Node(6);   

    cout << "IS tree Foldable?: " << IsFoldable(root);
}