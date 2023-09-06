#include<iostream>
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


int main()
{
    // Final tree looks like this
    //             4
    //           /  \
    //          1    6
    //        /  
    //       5   
    
    Node *root = new Node(4);
    root->left = new Node(1);
    root->right = new Node(6);
    root->left->left = new Node(5);
}