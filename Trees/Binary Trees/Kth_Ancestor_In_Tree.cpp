#include<iostream>
#include<vector>
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

// neive approach:
void solve(Node* root, int node, int k, vector<int> path, int &ans)
{
    if(!root)
        return; 
        
    // push current root in path
    path.push_back(root->data);
    
    // if found the node then return & store ans
    if(root->data == node)
    {
        // traverse from back of path & return kth node
        // if only 1 size means root itself is node so it doesn't have ancestors 
        if(path.size() <= 1)
            return;
            
        for(int i = path.size() - 1; i >= 0; i--)        
        {
            // cout << path[i] << " ";
            if(k == 0)
            {
                ans = path[i];
                return;
            }
            k--;
        }
    }
        
    // call left & right
    solve(root->left, node, k, path, ans);
    solve(root->right, node, k, path, ans);
}

// k pass by reference coz it will change throughout the code not only change for some function calls
Node* kthAncestor(Node* root, int &k, int node)
{
    if(!root)
        return NULL;
        
    // here if we found the node then we return the root
    if(root->data == node)
        return root;
    
    // call for left & right, and store them in Node 
    Node *leftAns = kthAncestor(root->left, k, node);
    Node *rightAns = kthAncestor(root->right, k, node);
    
    // if any of of left & right call return not NULL means we found the node in non-null side
    // and we return it to parent call & keep minusing k till it becomes 0
    if(leftAns != NULL && rightAns == NULL)
    {
        k--;
        
        // if k becomes 0 means currnet  node is the kth Ancestor of given node 
        if(k == 0)
            return root;        // means current node is kth ancestor
        
        return leftAns;            // return founded node as it is if k != 0
    }
    
    // same for if we found node in right call
    if(rightAns != NULL && leftAns == NULL)
    {
        k--;
        
        if(k == 0)      
            return root;
        
        return rightAns;
    }
    
    // if we don't found node in both calls then return NULL
    return NULL;
}

int main()
{
    // https://practice.geeksforgeeks.org/problems/kth-ancestor-in-a-tree/1

    // Q. find k ancestor of given node if doesn't exist then return -1

    // Tree looks like:            I/p: k = 2 node = 4    o/p: 1   
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
    int node = 4;

    // neive approach: 
    // time: O(N * path.size) space: O(N)
    // approach 2: neive approach store path from root to node  & traverse from last of it and 
    // return kth node from last
    vector<int> path;
    int res = -1;
    solve(root, node, k, path, res);
    cout << "Kth Ancestor of " << node << " is: " << res << endl;



    // efficient approach
    // time: O(N) space: O(height)
    Node* ans = kthAncestor(root, k, node);
    
    // if ans->data == node then it means first Node itself is the node so it doesn't have ancestors
    // so in this case return -1  (1 <= k <= 100)
    if(!ans || ans->data == node)
        cout << "Kth Ancestor doesn't exist" << endl;
        
    cout << "Kth Ancestor of " << node << " is: " << ans->data << endl;
}