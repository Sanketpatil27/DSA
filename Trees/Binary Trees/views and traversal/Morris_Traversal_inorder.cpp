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

void inorder(Node *root)
{
    if(root == NULL)    
        return;

    // call for left sub-tree
    inorder(root->left);
    
    // printing leftmost node of current subtree
    cout << root->data << " ";

    // call for right sub-tree
    inorder(root->right);
}

// inorder: left root right
void MorrisTraversal(Node *root)
{
    Node *curr = root;          // for traversing

    // keep on moving till curr does not reach NULL
    while (curr)
    {
        // case 1: if curr doesn't have left child
        if(!curr->left)
        {
            // so this is itself is the root so print it
            cout << curr->data << ' ';

            // then we move on its right child
            curr = curr->right;
        }

        // case 2: if there exists left, we go to the last NOde that will be visited in inorder of the left subtree, 
        // which will be the rightmost node
        else 
        {
            Node *prev = curr->left;
            // go to rightmost node  && it rightmost should not point to curr Node (this is case when we already precess left side)
            while (prev->right && prev->right != curr) 
            {
                prev = prev->right;
            }
            
            // case1: if our right reach NULL, then make a thread with pointing to parent node rooot
            if(!prev->right)
            {
                prev->right = curr;
                curr = curr->left;          // now start the traversal
            }

            // case 2: we already make thread of rightmost with curr node
            else {
                // so remove the thread as we must be traversed the left side, and go for traversing right side of curr
                prev->right = NULL;
                cout << curr->data << " ";        // since its right is nulll it's the root now so we print it
                curr = curr->right;
            }
        }
    }
}

int main()
{
    // Tree looks like:            
    //             1
    //           /  \
    //         2     3
    //       /  \
    //     4     5
    //            \ 
    //             6

    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    root->right = new Node(3);
    
    cout << "Inorder Traversal: ";
    inorder(root);

    cout << "\nMorris inorder:    ";
    MorrisTraversal(root);
}