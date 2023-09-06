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

// 3nd parameter(default) is shows current level of binary tree, output (k distance) always on (k + 1)'th node
void nodesAtDistK(Node *root, int k, int lvl = 0)
{
    if (root == NULL)
        return;
    
    if(lvl == k)
    {
        cout << root->key << " ";
        return;                                  // there is no point to go further coz, it will increase dist. k
    }

    nodesAtDistK(root->left, k, lvl+1);         // level will increase as we go deeper inside tree nodes
    nodesAtDistK(root->right, k, lvl+1);
}


// here we only decrease k till 0 and print node when k becomes 0
void kDist(Node *root, int k)
{
    if (root == NULL)
        return;
    
    if(k == 0)
        cout << root->key << " ";
        
    kDist(root->left, k-1);
    kDist(root->right, k-1);
}


int main()
{
    // Tree looks like this:            o/p: 90 40 50  (these nodes are on k+1' th level of tree, where k = 2)
    //             10
    //           /  \
    //         20    30
    //        /     /  \
    //      90    40    50

    Node *root = new Node(10);
    root->left = new Node(20);
    root->left->left = new Node(90);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);

    int k = 2;
    
    // finding using level of trees
    cout << "Height of Binary Tree: ";
    nodesAtDistK(root, k);              

    cout << endl;

    // without using level just decreasing k to 0
    cout << "Height of Binary Tree: ";
    kDist(root, k);
}