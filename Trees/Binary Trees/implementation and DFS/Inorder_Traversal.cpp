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

// structure of inorder Traversal: (Left Root Right) 
void inorder(Node *root)
{
    if(root == NULL)    
        return;

    // call for left sub-tree
    inorder(root->left);
    
    // printing leftmost node of current subtree
    cout << root->key << " ";

    // call for right sub-tree
    inorder(root->right);
}

// iterative
void inorderTraversal(Node* root) {
    // using iterative approach, time: O(N)   space: O(height) for stack

    stack<Node*> s;
    Node *curr = root;

    while(curr || !s.empty())
    {
        // go left left left,.... till reach NULL
        while(curr)
        {
            s.push(curr);
            curr = curr->left;
        }
        // now curr becomes NULL

        curr = s.top();             // go parent node
        s.pop();                    // pop parent after accessing
        cout << curr->key << " ";   // print root

        // go on right side of current tree
        curr = curr->right;
    }
}

int main()
{
    // Tree looks like this:            inorder of this: 20 10 40 30 50 
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

    cout << "Inorder Traversal: ";
    inorder(root);

    cout << "\nIterative Traverse: ";
    inorderTraversal(root);
}