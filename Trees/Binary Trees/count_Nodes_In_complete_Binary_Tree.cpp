#include<iostream>
#include<math.h>        // for pow() function
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

// neive approach: time: O(n)   space: O(h)   work for any tree not-only for complete binary Tree
// we simply nodes from left + nodes from right + 1 (current Node)
int countNodes(Node* root)
{
    if(!root)
        return 0;

    return countNodes(root->left) + countNodes(root->right) + 1;
}

// time: best case: O(height)  *deeply analyze it
// efficient approach using fact that given bianry tree is 'complete binary tree'
// we know that nodes in complete binary Tree are formula = (2^height - 1)
// so if any root's height of left == right then it is complete binary tree so we directly calculate nodes using *formula
// doesn't need to calculate middle nodes in tree
// else we follow our neive approach for counting (left + right + 1)
int countNodesModified(Node *root)
{
    // left & right height;
    int lh = 0;
    int rh = 0;         

    // go straight left for getting left height
    Node *curr = root;
    while (curr)
    {
        lh++; 
        curr = curr->left;
    }

    // go straight right for getting right height
    curr = root;
    while (curr)
    {
        rh++; 
        curr = curr->right;
    }
    
    // if current node subtree is complete binary tree
    if(lh == rh)
        return pow(2, lh) - 1;

    // else count using neive approach
    return countNodesModified(root->left) + countNodesModified(root->right) + 1;
}


int main()
{
    // https://practice.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1

    // Q. count Node in Complete Binary Tree, complete binary tree has all levels completely filled except possibly 
    // the last level it has to be filled from left to right

    // Tree looks like:            o/p: 6
    //             1
    //           /  \
    //         2     3
    //       /  \   /
    //     4     5 6


    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);            

    cout << "Nodes in given Complete Binary Tree: "  << countNodes(root);
    cout << "\nNodes in given Complete Binary Tree: "  << countNodesModified(root);
}