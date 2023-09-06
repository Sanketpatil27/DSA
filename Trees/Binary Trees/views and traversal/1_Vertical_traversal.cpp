#include<iostream>
#include<vector>
#include<map>
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

vector<int> verticalOrder(Node *root)
{
    // not using unordered map coz we need key(horizontal disance) in sorted order so we easily add their nodes in answer
    // we use map for storing horizontal distance of nodes from root & map of level and its corrosponding nodes
    map<int, map<int, vector<int>>> nodes;
    
    // use queue for level-order-traversal & also store 
    // pair of i. horizontal dist. & ii. level in that
    queue<pair<Node*, pair<int, int>>> q;
    vector<int> ans;
    
    if(!root)
        return ans;

    // first we push root node in queue with his pair of  dorizontal distnace and level no.
    // for root horizontal distance & level is always 0
    q.push(make_pair(root, make_pair(0, 0)));
    
    // BFS
    while(!q.empty())
    {
        // first we get front pair(contains node, hr dist, lvl)  from queue
        pair<Node*, pair<int, int>> curr = q.front();
        q.pop();
        
        // now we get front node from that pair & also get horizontal dist & level of node
        Node *front = curr.first;  
        int hd = curr.second.first; 
        int lvl = curr.second.second;

        // make entry of currosponding node in map
        nodes[hd][lvl].push_back(front->data);

        // normal BFS code
        // left nodes horizontal always -1 from curr node & level is +1 increased
        if(front->left)
            q.push(make_pair(front->left, make_pair(hd-1, lvl+1)));

        // for right node hd always +1 and level also +1
        if(front->right)
            q.push(make_pair(front->right, make_pair(hd+1, lvl+1)));
    }
    
    // now we get answers from map
    for(auto i: nodes)
    {
        // i.first is horizontal distance & i.second contains nodes & levels so we want 2nd
        for(auto j: i.second)
        {
            // j.first contains level;  j.second contains nodes  so we want to push nodes in answer
            for(auto k: j.second)
                ans.push_back(k);
        }
    }
    
    return ans;
}

int main()
{
    // https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
    
    // Tree looks like:            o/p: 20 10 40 30 60 50
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

    vector<int> ans = verticalOrder(root);

    cout << "Vertical traversal of Binary tree: ";
    for(int i: ans)
        cout << i << " ";
}