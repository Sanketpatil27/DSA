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

// neive approach:
int height(Node *root)
{
    if(!root)
        return 0;
        
    return max(height(root->left), height(root->right)) + 1;
}

bool isBalanced(Node *root)
{
    // time: O(N * N) (N for current fun & O(N) for height)  space: O(Height)
    // we take height of both left & right child and compare if follows the property
    // then go to left & right call
    
    // if tree empty then return true
    if(!root)
        return true;
    
    // get height of left & right child
    int lh = height(root->left);
    int rh = height(root->right);
    
    // check if difference between left & right  subtree height follows rule
    return (abs(lh - rh) <= 1) && (isBalanced(root->left) && isBalanced(root->right));
}

// efficient: what is our height function not only tell height but also tell if current subtree is balanced or not?
int getHeight(Node* root)
{
    if(!root)
        return 0;

    // we return -1 if current tree is unbalanced(returned -1)
    int lh = getHeight(root->left);
    int rh = getHeight(root->right);
    
    if(lh == -1 || rh == -1)
        return -1;

    // check if balanced then only return height of current node
    if(abs(lh - rh) <= 1)
        return max(lh, rh) + 1;
    else 
        return -1;
}

bool checkBalanced(Node* root)
{
    if(getHeight(root) == -1)
        return false;
    
    return true;
}

int main()
{
    // https://practice.geeksforgeeks.org/batch/dsa-4/track/DSASP-Tree/problem/check-for-balanced-tree

    // Q. Given a binary tree, find if it is height balanced or not. A tree is height balanced 
    // if difference between heights of left and right subtrees is not more than one for all nodes of tree. 

    // A height balanced tree
    //        1
    //      /  \
    //    10    39
    //   /
    // 5

    // An unbalanced tree
    //        1
    //      /    
    //    10   
    //   /
    // 5

    // Ex. Tree looks like:            o/p: false
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
    root->right->right->left = new Node(6);      // removing this will make tree balanced

    // time: O(N*N) space: O(height)
    cout << "IS Given Tree Balanced?: " << isBalanced(root);
    
    // time: O(N) space: O(height)
    cout << "\nIS Given Tree Balanced?: " << checkBalanced(root);
}