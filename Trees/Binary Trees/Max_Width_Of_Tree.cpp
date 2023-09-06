#include<iostream>
#include<queue>
#include<climits>
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

int getMaxWidth(Node* root) {
    // time: O(N)  space: O(Width)
    // we simply use level order Traversal Method 3 using queue
    // we store maximum q.size() for every level
    // queue always contain every level nodes at every level so, number of nodes 
    // in that level is the width of that level
    int mxWidth = INT_MIN;
    queue<Node *> q;
    q.push(root);
    
    while(!q.empty())
    {
        int cnt = q.size();
        mxWidth = max(mxWidth, cnt);
        for(int i = 0; i < cnt; i++)
        {
            Node *curr = q.front();
            q.pop();
            
            // push next level of current level
            if(curr->left)
                q.push(curr->left);
            
            if(curr->right)
                q.push(curr->right);
        }
    }
    
    return mxWidth;
}

int main()
{
    // 

    // Q. 

    // Tree looks like:            o/p: 2
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

    cout << "Maximum width of Binary Tree: " << getMaxWidth(root);
}