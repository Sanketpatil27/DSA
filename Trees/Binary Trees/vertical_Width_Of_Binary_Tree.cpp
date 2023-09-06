#include<iostream>
#include<unordered_set>
#include<queue>
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

// time: O(N)  space: O(N) (in worst case there can be N no.of columns in Tree)
int verticalWidth(Node* root)
{
    if(!root)
        return 0;
        
    // this will follow same logic as vertical traversal of Tree
    // here we just want size of unique horizontal distnace with their nodes
    
    // in this problem we only need count on unique horizontal distances, so use set for 'hd'
    // coz we don't want node values we just want horizontal width
    unordered_set<int> s;
    
    // queue of node & hr distnace
    queue<pair<Node*, int>> q;
    q.push(make_pair(root, 0));
    
    while(!q.empty())
    {
        pair<Node*, int> curr = q.front();
        q.pop();
        
        Node* front = curr.first;
        int hd = curr.second;
        
        s.insert(hd);
        
        if(front->left)
            q.push(make_pair(front->left, hd-1));
        
        if(front->right)
            q.push(make_pair(front->right, hd+1));    
    }
    
    // return size of set of horizontal distances
    return s.size();
}

int main()
{
    //  https://practice.geeksforgeeks.org/batch/dsa-4/track/DSASP-Tree/problem/vertical-width-of-a-binary-tree

    // Q. imagine 'horizontal line scale top of tree' & count unique distances

    // Tree looks like:            o/p: 4
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

    cout << "Vertical Width Of Binary Tree: " << verticalWidth(root);
}