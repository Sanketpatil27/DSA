#include<iostream>
#include<map>
#include<queue>
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

vector<int> bottomView(Node *root)
{
    // exact same code as bottomview, but here we don't check while inserting in map that its first node 
    // or not coz, we seeing from bottom, so we need to store bottom node of same horizontal dist.
    // so store all nodes at last it will contain bottom node from same hr dist. of nodes

    vector<int> ans;
    if(!root)
        return ans;

    // we need key(horizontal dist) in sorted order
    // 1st for horizontal dist. 2nd for currosponding node 
    map<int, int> bottomNode;
    
    // queue for level order traversal of tree and additional pair of horizontal dist
    queue<pair<Node*, int>> q;
    q.push(make_pair(root, 0));     // for root hr dist. always 0
        
    while(!q.empty())
    {
        // get front pair front queue
        pair<Node*, int> curr = q.front();
        q.pop();
        
        // get front node, hr distance from pair
        Node *front = curr.first;
        int hd = curr.second;
        
        // store even for same hr dist. coz we want last node of same hr distance (it will override)
        bottomNode[hd] = front->data;
        
        // horizontal dist. for left side node always -1 from current
        if(front->left)
            q.push(make_pair(front->left, hd-1));

        // horizontal dist. for left side node always +1 from current    
        if(front->right)
            q.push(make_pair(front->right, hd+1));
    }
    
    // now get answers from the map
    for(auto i: bottomNode)
        // i.first = hd and i.second = node->data
        ans.push_back(i.second);
    
    return ans;
}

int main()
{
    // https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1
    
    // Tree looks like:            o/p: 20 40 60 50
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

    vector<int> ans = bottomView(root);

    cout << "Bottom View of Binary tree: ";
    for(int i: ans)
        cout << i << " ";
}