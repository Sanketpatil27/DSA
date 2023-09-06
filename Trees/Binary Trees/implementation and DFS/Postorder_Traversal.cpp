#include<iostream>
#include<stack>
using namespace std;
 
struct Node
{
    int key;
    Node *left;
    Node *right;

    Node (int data)
    {
        key = data;
        left = NULL;
        right = NULL;
    }
};

// structure of postorder Traversal: (Left Root Right) 
void postorder(Node *root)
{
    if(root == NULL)    
        return;

    // call for left sub-tree
    postorder(root->left);

    // call for right sub-tree
    postorder(root->right);
    
    // printing leftmost node of current subtree
    cout << root->key << " ";
}

// iterative approach
void postIterative(Node *root)
{
    // this approach like level order traversal 
    stack<Node*> st;
    st.push(root);

    while (!st.empty())
    {
        // first push left & right of top in stack,

    }
    
}

int main()
{
    // Tree looks like this:            postorder of this: 20 40 50 30 10 
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

    cout << "postorder Traversal: ";
    postorder(root);

    // this is not correct!!!
    // cout << "\nIterative PostOrder: ";
    // postIterative(root);
}