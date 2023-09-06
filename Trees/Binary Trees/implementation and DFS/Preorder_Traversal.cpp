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

// structure of preorder Traversal: (Left Root Right) 
void preorder(Node *root)
{
    if(root == NULL)    
        return;

    // printing leftmost node of current subtree
    cout << root->key << " ";
    
    // call for left sub-tree
    preorder(root->left);

    // call for right sub-tree
    preorder(root->right);
}

// iterative approach
void preIterative(Node *root)
{
    stack<Node*> s;
    Node *curr = root;

    // keep process until any 1 of these true
    while(curr || !s.empty())
    {
        // in preorder we first print then go left, then go right
        while (curr)
        {
            cout << curr->key << " ";
            s.push(curr);
            curr = curr->left;
        }
        // now we are on NULL 

        // pick top of the stack and pop it print it & go on its right child
        curr = s.top();
        s.pop();

        curr = curr->right;
    } 
}

// another approach is like level-order-traversal, here we use LIFO data structure (stack) so we go on left side first 
void sovle(Node *root)
{
    if(!root)
        return;

    stack<Node*> s;
    s.push(root);

    while (!s.empty())
    {
        Node *curr = s.top();
        s.pop();

        // first print top item
        cout << curr->key << ' ';

        // then push its right & left childs in LIFO Order, (right first coz we want to print left side first, so left will be on top)
        if(curr->right)
            s.push(curr->right);

        if(curr->left)
            s.push(curr->left);
    }
}


int main()
{
    // Tree looks like this:            preorder of this: 10 20 30 40 50
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

    cout << "preorder Traversal: ";
    preorder(root);

    // time: O(N)  space: O(N) 
    cout << "\nIterative Preorder: ";
    preIterative(root);

    // similar approach like level order traversal but using stack so we first print last item pushed
    // time: O(N)    space: O(N)
    cout << "\nlevelOrder Preorder: ";
    sovle(root);
}