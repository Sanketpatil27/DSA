#include <iostream>
using namespace std;

struct Node
{
    int key;
    Node *left;
    Node *right;

    Node(int data)
    {
        key = data;
        left = NULL;
        right = NULL;
    }
};

int height(Node *root)
{
    if (root == NULL)
        return 0;

    return max(height(root->left), height(root->right)) + 1;
}

int main()
{
    // Tree looks like this:            o/p: 3
    //             10
    //           /  \
    //         20    30
    //              /  \
    //            40    50

    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);

    cout << "Height of Binary Tree: " << height(root) << endl;
}