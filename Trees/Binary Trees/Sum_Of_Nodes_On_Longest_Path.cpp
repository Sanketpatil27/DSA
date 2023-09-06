#include<iostream>
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

void sumOfLongRootToLeafPath(Node *root, int len, int &mxlen, int sum, int &mxSum)
{
    // base case
    if(!root)
        return;       
        
    // first we add current node in sum, so that for leaf node it calculate correctly sum & mxsum
    sum += root->data;
    
    // if current node is leaf node,  then we compare len of current path with len of max path till now
    // if both paths equal then we consider path which have maximum sum
    if(!root->left && !root->right)
    {
        if(len >= mxlen)
        {
            // is len same but current sum less than mxSum then change nothing, (both lens are same)
            if(len == mxlen && mxSum > sum)
                mxlen = len;
            
            // if len > mxlen then we don't have to compare sum & mxsum
            else 
            {
                mxlen = len;
                mxSum = sum;
            }
        }
        
        // cout << "len: " << len << " mxlen: " << mxlen << " mxsm: " << mxSum << " sum: " << sum << endl;
    }
    
    
    // if current node not leaf then add data of current node in sum & increment len and 
    // call for left & right
    sumOfLongRootToLeafPath(root->left, len+1, mxlen, sum, mxSum);
    sumOfLongRootToLeafPath(root->right, len+1, mxlen, sum, mxSum);
}

int main()
{
    // https://practice.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1

    // Q. count nodes on longest path from root to leaf, if 2 path compete for longest path then 
    // path which have max sum of nodes should  be considered

    // Tree looks like:            o/p: 15   (path = 1 3 5 6)    
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
    // root->right->right->left = new Node(6);          
    // if node 6 we don't consider then ans would be 9, this is max from path: (1 3 4) (1 3 5)


    int len = 0;        // to track curr path length
    int mxlen = 0;      // longest path len till now
    int sum = 0;        // track sum of current path 
    int mxSum = 0;      // store maximum sum of current maxlen path  
    
    // we use preorder traversal
    // mxlen & mxSum should not change for every call so passing it as by reference
    // we compare len mxlen only if we are on leaf node 
    sumOfLongRootToLeafPath(root, len, mxlen, sum, mxSum);
    
    cout << "Maximum Sum Of Longest Path: " << mxSum;  
}