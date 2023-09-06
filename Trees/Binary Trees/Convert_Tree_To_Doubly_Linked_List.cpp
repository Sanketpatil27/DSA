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

void traverseList(Node* head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->right;             // right is the next node
    }
}

// we use inorder traversal & make some changes after left call over
// our head will be the left-most node of tree
// T/C: O(N)   S/C: O(height)
Node *previous = NULL;      // initially prev is null so we can set leftmost as head
Node* convertBinaryToDoublyList(Node* root)
{
    if(!root)
        return root;

    // set head with left-most node
    Node *head = convertBinaryToDoublyList(root->left);      

    // set head to the leftmost node
    if(!previous)
        head = root;
    else
    {
        // link left child as prev node of doubly linked list  
        root->left = previous;
        previous->right = root;         // connect previous nodes next(right) as current node
    }

    // make current node as prev and call for right child
    previous = root;
    convertBinaryToDoublyList(root->right);

    return head;
}

int main()
{
    // https://practice.geeksforgeeks.org/problems/binary-tree-to-dll/1

    // Q. convert binary tree to a Doubly Linked List(DLL) In-Place. The left and right pointers in nodes 
    // are to be used as previous and next pointers respectively DLL. The order of nodes in DLL must be same 
    // as Inorder of the given Binary Tree. The first node of Inorder traversal (leftmost node in BT) must be the head node of the DLL.

    // Tree looks like:            o/p: 2 <=> 1 <=> 4 <=> 3 <=> 6 <=> 5 <=> NULL
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

    root = convertBinaryToDoublyList(root);

    cout << "Doubly Linked List: ";
    traverseList(root);
}