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

// if any of root's left or right side return true means we find target there so store its ancestors
// we doesn't print another side at which target not present coz that side's root will don't push in ans coz its left & right will not be tree
bool Ancestors(Node *root, int target, vector<int> &ans)
{
    if(!root)
        return false;
        
    if(root->data == target)
        return true;
        
    
    bool left = Ancestors(root->left, target, ans);
    bool right = Ancestors(root->right, target, ans);
    
    if(left || right)
        ans.push_back(root->data);
}

int main()
{
    // https://practice.geeksforgeeks.org/problems/ancestors-in-binary-tree/1

    // Q. print ancestors of given target

    // Tree looks like:            o/p: 5 3 1
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

    int target = 6;

    // time: O(N)  space: O(height)
    cout << "Ancestors of target are: ";
    vector<int> ancestors;
    Ancestors(root, target, ancestors);
    for(auto i: ancestors)
        cout << i << " ";
}