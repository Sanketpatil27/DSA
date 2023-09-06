#include <iostream>
#include <queue>
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

int getSize(Node* root)
{
    // iterative: time: O(N) space: O(width)
    
    queue<Node *> q;
    int cnt = 0;
    
    q.push(root);
    
    while(!q.empty())
    {
        Node *curr = q.front();
        q.pop(); 
        
        cnt++;
        
        if(curr->left)
            q.push(curr->left);
            
        if(curr->right)
            q.push(curr->right);
    }
    
    return cnt;
}

// recursive
int recGetSize(Node* root)
{
    if(root == NULL)
        return 0;

    return (getSize(root->left)) + (getSize(root->right)) + 1;
}

int main()
{
    // Tree looks like this:            o/p: size == nodes = 5
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

    // Iterative:  apporach of level order traversal using queue T/C: O(N)  S/C: (width)
    // at max there can be width no. of nodes in queue (width of current level)
    cout << "Size of Binary Tree: " << getSize(root) << endl;
    
    // Recursive:  T/C: O(N)  S/C: (height)   at max height+1 (+1 for null) nodes will be in function stack
    cout << "Size of Binary Tree: " << recGetSize(root) << endl;
}