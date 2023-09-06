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

// we use inorder traversal to print left side
void printLeft(Node *root, vector<int> &ans)
{
    // if we reach end or leaf node then don't print it
    if(!root || (!root->left && !root->right) )
        return;
        
    // left root always be printed of left side    
    ans.push_back(root->data);
    
    // call for left side
    if(root->left)
        printLeft(root->left, ans);
        
    // if current node doesn't have left node but have right node then go to 
    // right node coz this also comes in left side of tree coz there is no left child for root
    else
        printLeft(root->right, ans);
}

// we have to print leaf node from left to right so we use inorder traversal
void printLeaf(Node *root, vector<int> &ans)
{
    if(!root)
        return;
        
    // print only leaf nodes
    if(!root->left && !root->right)
        ans.push_back(root->data);

    // call for left and right subrees
    printLeaf(root->left, ans);
    printLeaf(root->right, ans);
}

// we add root data while returning from the the call so we can add it in reversed order
void printRight(Node *root, vector<int> &ans)
{
    if(!root || (!root->left && !root->right) )
        return;
        
    // call for right side
    if(root->right)
        printRight(root->right, ans);
        
    // if current node doesn't have right node but have left node then go to 
    // left node coz this also comes in right side of tree coz there is no right child for root
    else
        printRight(root->left, ans);
    
    // store ansewr while returning from current node(reverse order)
    ans.push_back(root->data);
}
    
vector <int> boundary(Node *root, vector<int> &ans)
{
    // we break this problem in 3 parts
    // 1. print left side of tree (exclude leaf coz it comes in 2nd part)
    // 2. print all leaf nodes 
    // 3. print right part *in reverse order (exclude leaf node) 
    
    if(!root)
        return ans;     
    
    // root of tree always be printed
    ans.push_back(root->data);
    
    // 1. call for left 
    printLeft(root->left, ans);
    
    // 2. call for adding leaf nodes
    // root already print, we don't pass it
    // so collect leaf nodes from left and right subtree
    printLeaf(root->left, ans);
    printLeaf(root->right, ans);
    
    // 3. call for right part of tree
    printRight(root->right, ans);
    
    return ans;
}

int main()
{
    // https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

    // Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order: 
    // Left boundary nodes:          path from the root to the left-most node
    // Leaf nodes:                   All the leaf nodes except for the ones that are part of left or right boundary.
    // Reverse right boundary nodes: path from the right-most node to the root. 

    // Tree looks like:            o/p: 10 20 40 60 50 30       this is left view of every level 
    //             10
    //           /  \
    //         20    30
    //              /  \
    //            40    50
    //                /
    //              60

    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);
    root->right->right->left = new Node(60);

    vector<int> ans;
    boundary(root, ans);

    cout << "Boundry Nodes are: ";
    for(int i: ans)
        cout << i << " ";
}