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

// we make pair for each node:
// 1st value of pair will contain sum after including the current node
// 2nd value of pair will contain sum after excluding the current node

// note: for second value we can take adjecent or not take adjecent, so we will take which gives benifit to us, means
// take from left & right pairs ==> max (left adjecent) + max (right adjecent)
pair<int, int> getMaxSum(Node *root)
{
    if(!root)    
        return make_pair(0, 0);      // for null there is including & excluding both values are 0
        
    pair<int, int> left  = getMaxSum(root->left);
    pair<int, int> right = getMaxSum(root->right);
    
    // if include current node then can't include first value of pair which is current 
    // node's adjecents so add sum excluding them which stays on second value of pair
    int includeCurr = root->data + left.second + right.second;
    
    // if we exclude current then we can take its adjecent's or not take adjecent 
    // so take which gives benifit means take maximum from pairs values of left & right
    // and add them
    int excludeCurr = max(left.first, left.second) + max(right.first, right.second);
    
    return make_pair(includeCurr, excludeCurr);
}

int main()
{
    // https://practice.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1
    // Q. 

    // Tree looks like:            o/p: 1
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
    
    
    // time: O(N)  space: O(height)
    pair<int, int> ans = getMaxSum(root);
    cout << "Maximum Sum of non-adjecent nodes: " << max(ans.first, ans.second);
}