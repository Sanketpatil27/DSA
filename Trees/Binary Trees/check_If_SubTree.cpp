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

void findPreorder(Node *root, string &r)
{
    if(!root)
    {
        // null also be added, 
        //root = [4,-9,5,null,-1,null,8,-6,0,7,null,null,-2,null,null,null,null,-3]
        // subRoot = [5]
        // here 5 is not subtree in root, there is childs null & null but not same 
        // in main tree T 
        r += "N ";
        return;
    }

    findPreorder(root->left, r);
    findPreorder(root->right, r);

    //  we should also add space after adding values: in case root = [12]  
    //  subRoot = [1] it return true
    //  without comma , it reutrns tree as 1 is part of  12 in string
    r += to_string(root->data) + " ";
}

bool isSubTree(Node* root, Node* subRoot) 
{
    // time complexity is O(N^2) due to the find function's worst-case complexity, 
    // and the space complexity is O(N) due to the recursive call stack
    
    // find preorder of both root & subRoot & check if subRoot values occur in root
    // we put values in string for simplicity checking
    string r1 = "";
    string r2 = "";

    findPreorder(root, r1);
    findPreorder(subRoot, r2);

    // if string r2 of subRoot find in r1 then true, fun take O(N) time in worst case
    return r1.find(r2) != string::npos;
}

int main()
{
    // https://leetcode.com/problems/subtree-of-another-tree/description/

    // Q. given root & subRoot check if subRoot tree is subTree of root tree

    // Tree looks like:            o/p: 
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

    Node *subRoot = root->right;        // assume that this is new tree

    cout << "IS SUbTree?: " << isSubTree(root, subRoot);
}