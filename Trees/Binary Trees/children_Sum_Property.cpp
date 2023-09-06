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

int isSumProperty(Node *root)
{
    // leaves follows property, return 0 for them
    if(!root)
        return 0;

    if(!root->left && !root->right)
        return true;

    int sum = 0;
    if(root->left)
        sum += root->left->data;

    if(root->right)
        sum += root->right->data;

    // else return true if child sum == parent
    return (sum == root->data && (isSumProperty(root->left) && isSumProperty(root->right)));
}

int main()
{
    // Q. Given a Binary Tree. Check whether all of its nodes have the value equal to the sum of their child nodes.
    //    returns 1 if all the nodes in the tree satisfy the following properties. Else, it returns 0.
    //    Consider data value as 0 for NULL child.  Also, leaves are considered to follow the property.

    // Tree looks like:            o/p: 12  (chosen nodes- [2, 4, 6])
    //             5
    //           /  \
    //         2     3
    //             /  \
    //           1     2

    Node *root = new Node(5);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(1);
    root->right->right = new Node(2);

    cout << "Follows child summ property? " << isSumProperty(root);
}