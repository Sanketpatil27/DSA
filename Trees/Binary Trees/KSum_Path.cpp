#include<iostream>
#include<unordered_map>
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

// neive
void solve(Node *root, int &count, int k, vector<int> path)
{
    if(!root)    
        return;
        
    path.push_back(root->data);
    
    // call left & right
    solve(root->left, count, k, path);
    solve(root->right, count, k, path);
    
    
    // don't clear to me that how  is this working correctly for multiple case like k = 3 path = 3 3 3 
    // so ans should be 3
    // now after all call over for a subtree we will if the path contain k sum of nodes or not
    // we start loop from back of paths
    int sum = 0;
    int size = path.size();
    for(int i = size-1; i >= 0; i--)
    {
        sum += path[i];
        // cout << sum << " ";
        if(sum == k)
            count++;
    }
    
    // now backtrack that pushed node value coz for next subtree we don't want it in next path
    path.pop_back();
}

// efficient:
void sumK(Node *root, int &count, int k, unordered_map<long long, int> &path, long long currSm)
{
   if(!root)    
        return;
    
    currSm += root->data;
    
    // means in the path there is sum which can make up to k with currSm
    if(path.find(currSm - k) != path.end())
        count += path[currSm-k];            // add no of count path contains with [currSm - k]
    
    // if curr sum itself same as k then also increment count
    if(currSm == k)           
        count++;

    path[currSm]++;         // insert current sum in path

    // call left & right childs
    sumK(root->left, count, k, path, currSm);
    sumK(root->right, count, k, path, currSm);
    
    // modify path first then modify current sum
    path[currSm]--;         // decrement one count as we returning from that path 
    currSm -= root->data;   // remove current node from current path sum 
}

int main()
{
    // https://practice.geeksforgeeks.org/problems/k-sum-paths/1
    // Q. Find the number of paths in the tree which have their sum equal to K.
    // A path may start from any node and end at any node in the downward direction.

    // Tree looks like:            i/p: k = 3   o/p: 2 (paths = [1,2], [3])
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

    int k = 3;

    // in this approach we using O(N^2) time, giving TLE!!!
    // we will find all paths and for every path we increment count if path contain k sum
    vector<int> path;
    int count = 0;          // pass conunt by reference
    solve(root, count, k, path);
    
    cout << "Path count: " << count << endl;

    // we modify the function that we use map to track sum if o(1) time
    // similar logic as presSum = target with maps
    // T/C: O(N)  S/C: O(N)   (max O(heigh) + O(height) current sum in map)
    unordered_map<long long, int> path1;
    long long currSum = 0;
    count = 0;
    sumK(root, count, k, path1, currSum);
    cout << "Path count: " << count << endl;
}