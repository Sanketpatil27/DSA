#include<iostream>
#include<vector>
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


// take reference from ancestors finding program
// we find path from root to the n1 & n2 and get last common elem from both path's
bool findPath(Node *root, int target, vector<int> &path)
{
    if(!root)
        return false;
        
    // we also push target in path
    path.push_back(root->data);

    if(root->data == target)
        return true;
    
    bool left = findPath(root->left, target, path);
    bool right = findPath(root->right, target, path);
    
    // only push the node which is on valid path (means it's any of the left of right path is correct so put it)
    if(left || right)
        return true;
    
    // if no found target in any of left & right then pop currently pushed root from path
    path.pop_back();
}

// this  is efficient solution: (check NoteBook for explanation)
// we have following cases for every node:
// 1. if it is same as n1 || n2
// 2. if one of its subtree contiain n1 & other contain n2
// 3. if one of subtree contain both n1 & n2
// 4. if none of its subtree contain any of n1 & n2
Node* lowestCommonAncestor(Node* root, int n1, int n2) 
{
    if(!root)   
        return NULL;

    if(root->data == n1 || root->data == n2)
        return root;

    // get LCA from left & right subtrees
    Node *lca1 = lowestCommonAncestor(root->left, n1, n2);
    Node *lca2 = lowestCommonAncestor(root->right, n1, n2);

    // if both of them are not null means one subtree contin both p & q on left and right sides
    if(lca1 && lca2)
        return root;

    // if not falls in upper case means left side contain both p & q nodes
    if(lca1)
        return lca1;

    // else right side contain either both nodes or null
    else
        return lca2;
}

int main()
{
    // https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1

    // Q. 

    // Tree looks like:            o/p: 3 (lowest means from top to bottom)
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

    int n1 = 4;
    int n2 = 6;

    vector<int> path1;
    vector<int> path2;
    findPath(root, n1, path1);
    findPath(root, n2, path2);

    // time: O(N) but required 3 traversal space: O(N)
    // now our both paths are fill from bottom to root node in their ancestors path 
    // path filled from root to the n1 or n2 (ex: 1, 3, 4) so, in path our last common elem will be the lowest common ancestor in tree
    int i;
    for(i = 0; i < path1.size()-1 && i < path2.size()-1; i++)
        if(path1[i+1] != path2[i+1])        // stop when next elem is not same
            break;
    
    cout << "Lowest Common Ancestor: " << path1[i];

    // time: O(N) require 1 traversal space: O(height)
    cout << "\nLowest common Ancestor: " << lowestCommonAncestor(root, n1, n2)->data;
}