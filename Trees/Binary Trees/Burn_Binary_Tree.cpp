#include<iostream>
#include<unordered_map>
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

// we need to return target Node 
Node* parentMapping(Node *root, unordered_map<Node*, Node*> &nodeToParent, int target)
{
    // we use level order traverse to traverse tree 
    Node *res = NULL;
    queue<Node*> q;
    q.push(root); 
    nodeToParent[root] = NULL;          // there is no Parent for root node

    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();

        if(curr->data == target)
            res = curr;

        // map current root as parent of it's left & right child
        if(curr->left)
        {
            q.push(curr->left);
            nodeToParent[curr->left] = curr;
        }

        if(curr->right)
        {
            q.push(curr->right);
            nodeToParent[curr->right] = curr;
        }
    }

    return res;
}

int BurnTree(Node *target, unordered_map<Node*, Node*> &nodeToParent) 
{
    // now while burning Nodes we need to keep track of which nodes has been burned, so increment time only for unburned nodes
    unordered_set<Node*> visited;
    queue<Node*> q;
    
    q.push(target);             // first push the target Node
    visited.insert(target);     // mark target node as visited

    int time = 0;

    // we want to burn childs & parent which are in queue at same time so we use level-order-traversal approach-3
    while (!q.empty())
    {
        int count = q.size();
        bool addition = false;      // to check if any new addition in queue then we increment time 

        for(int i = 0; i < count; i++)
        {
            Node *curr = q.front();
            q.pop();

            // mark as burned for left, right & parent Node, if already not burned
            if(curr->left && visited.find(curr->left) == visited.end())
            {
                visited.insert(curr->left);
                q.push(curr->left);
                addition = true;
            }

            if(curr->right && visited.find(curr->right) == visited.end())    
            {
                visited.insert(curr->right);
                q.push(curr->right);
                addition = true;
            }

            // check if it has parent(only root node doesn't have parent) or if it is not burned
            if(nodeToParent[curr] && visited.find(nodeToParent[curr]) == visited.end())
            {
                visited.insert(nodeToParent[curr]);
                q.push(nodeToParent[curr]);
                addition = true;
            }
        }

        if(addition)
            time++;                     // only increment 1 time for each traversal coz childs & parent got burned at same time
    }

    return time;
}

int main()
{
    // https://practice.geeksforgeeks.org/problems/burning-tree/1

    // Q. Given target find Minimum time to Burn Binary Tree from target, time to burn target node is 0 second & 
    // in 1 second all nodes connected to a given node get burned. 

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


    // time: O(N)  (O(N) + (N)   for maping + burning)
    // space: O(N) (O(N) + O(N) for mapping + visited)
    // // we have to burn neighbours so, we can get left & right neighbours by left & right pointer 
    // but can't get parent so for this:
    // 1. we make map for child->parent mapping, using level order traversal
    // 2. for burning tree from given node we have to find target node, get this  with step1
    // 3. need 2 data structures: i. visited set for checking node to be burn is already burned
    //    ii. queue for level order traversal
    // 4. check if there any addition in queue Yes-> time++;  No-> nothing
    //    means we only add in queue if its not burned already, thats why time++, as we burn 
    //    new nodes

    int target = 3;
    unordered_map<Node*, Node*> nodeToParent;
    Node *targetNode = parentMapping(root, nodeToParent, target);

    int time = BurnTree(targetNode, nodeToParent);
    cout << "Time to Burn Tree From target: " << time;
}