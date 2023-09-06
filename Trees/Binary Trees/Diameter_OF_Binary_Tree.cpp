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


int height(Node *root)
{
    if(!root)
        return 0;
    
    return max(height(root->left), height(root->right)) + 1;
}

// neive approach: time: O(N^2) (O(N) for height & O(N) findDiameter)      space: O(height)
// we can get diameter using height of both left & right sides, we get max from 
// height of [leftSubtree + rightSubtree + 1] (+1 for counting root of that tree)
int findDiameter(Node *root)
{
    if(!root)
        return 0;

    // get left & right subtree height
    int lh = height(root->left);
    int rh = height(root->right);

    // now return maximum from current root diameter & from left & right subtrees
    return max(lh + rh + 1, max(findDiameter(root->left), findDiameter(root->right)));
}

// time: O(N)  space: O(height)
// while calculating height we also calculate diameter for that root & get max from all nodes diameter
int modifiedHeight(Node *root, int &diameter)
{
    if(root == NULL)
        return 0;
        
    // taking left subtree and right subtree heights
    int lh = modifiedHeight(root->left, diameter);
    int rh = modifiedHeight(root->right, diameter);

    // update diameter if diameter of current node is max 
    diameter = max(diameter, (lh + rh + 1));

    // return height for each node as normally we do
    return max(lh, rh) + 1;     
}

int main()
{
    // https:

    // Q. Diameter is defined as the no. of nodes on longest path between 2 end (leaf) Nodes

    // Tree looks like:            o/p: 5 (path = [2, 1, 3, 5, 6])
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

    // time: O(N^2)   space: O(height)
    cout << "Diameter Of Binary Tree: " << findDiameter(root);

    // time: O(N)     space: O(height)
    int diameter = 0;
    modifiedHeight(root, diameter);
    cout << "\nDiameter Of Binary Tree: " << diameter;
}