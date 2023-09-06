#include<iostream>
#include<unordered_set>
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


// time: O(N) space: O(Height)
// traverse till leaf node, store path in array, after comming at leaf node get kth node from path using formula
void count(Node *root, unordered_set<Node*> &s, int k, vector<Node*> &path)
{
    if(!root)
        return;

    path.push_back(root);

    if(!root->left && !root->right)
    {
        // -1 coz leaf also added in path leaf node
        int ind = path.size() - k - 1;  // get index of node that is distance  k away from leaf

        // negative  means k greater than height of node
        if(ind >= 0)
            s.insert(path[ind]); 
    }

    // call for left & right with increased count, count for leaf not incremented coz we return
    count(root->left, s, k, path);
    count(root->right, s, k, path);

    // Remove the current node's data from the path before returning
    path.pop_back();
}


int main()
{
    // https://practice.geeksforgeeks.org/batch/dsa-4/track/DSASP-Tree/problem/node-at-distance

    // Q. Given a Binary Tree and a positive integer k. The task is to count all distinct nodes that are distance k from 
    // a leaf node. A node is at k distance from a leaf if it is present k levels above the leaf and also, is a **direct 
    // ancestor of this leaf node. If k is more than the height of Binary Tree, then nothing should be counted.
    // (**direct ancestor means it must be parent of leaf)

    // Tree looks like:            o/p: 2 (1 for 4 & 3 for 6)
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

	int k = 2;
	unordered_set<Node*> s;
    vector<Node*> path;       // it will double its size if required

	count(root, s, k, path);
	cout << "Unique Nodes at distance k from all leaves: " << s.size();

    // cout << "\nThat nodes are: ";
    // for(auto i: s)
    //     cout << i->data << " ";
}