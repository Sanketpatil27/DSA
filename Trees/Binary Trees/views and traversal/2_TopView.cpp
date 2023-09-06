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

vector<int> topView(Node *root)
{
    // using same logic as vertical view of binary tree
    // we use mapping of horizontal distance as key & their value is currosponding *first node
    // we print only first node coz other  nodes with same distance will hide by first same distance node
    // from top view of binary tree
    
    vector<int> ans;
    if(!root)
        return ans;
        
    // we need key(horizontal dist) in sorted order
    // 1st for horizontal dist. 2nd for currosponding node 
    map<int, int> topNode;
    
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
        
        // push in map only if current node is first in that horizontal distance
        if(topNode.find(hd) == topNode.end())
            topNode[hd] = front->data;
        
        // horizontal dist. for left side node always -1 from current
        if(front->left)
            q.push(make_pair(front->left, hd-1));

        // horizontal dist. for left side node always +1 from current    
        if(front->right)
            q.push(make_pair(front->right, hd+1));
    }
    
    // now get answers from the map
    for(auto i: topNode)
        // i.first = hd and i.second = node->data
        ans.push_back(i.second);
    
    return ans;
}

int main()
{
    // https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1
    
    // Tree looks like:            o/p: 20 10 30 50
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

    vector<int> ans = topView(root);

    cout << "top View of Binary tree: ";
    for(int i: ans)
        cout << i << " ";
}