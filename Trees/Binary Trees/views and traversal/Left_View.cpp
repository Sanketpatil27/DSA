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

void leftView(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    // we use level order traversal approach 3 using queue, we only print first Front Node of the queue as it will be the left node
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int cnt = q.size();

        for (int i = 0; i < cnt; i++)
        {
            Node *curr = q.front();
            q.pop();

            // only print leftMost of current level
            if(i == 0)
                cout << curr->key << " ";
            
            if(curr->left)
                q.push(curr->left);
            
            if(curr->right)
                q.push(curr->right);
        }
    }
}   

// recursive: we use preOrder of binary tree, so we always going to visit leftmost node first  
int mxLevel = 0;

void recleftView(Node *root, int level)
{
    if(root == NULL)
        return;

    // we only print when our mxLvl is lesser than level, so it will help to only print 
    // first node of that level & it will leftmost node of that level
    // it doesn't print any other nodes than first node
    if(mxLevel < level)
    {
        cout << root->key << " ";
        mxLevel = level;              //update mxLvl to new level
    }

    // same level increment for left & right calls but we using mxLevel so it will print only first 
    // node from that level & change itself with next level only if mxlvl < curr lvl not for (mxlvl == curr lvl)
    recleftView(root->left, level+1);
    recleftView(root->right, level+1);
}

int main()
{
    // Tree looks like this:            o/p: 10 20 40       this is left view of binary tree
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

    // we use iterative approach, of level order traversal using queue: time: O(N) space: O(width)
    cout << "Left View Of Binary Tree: ";
    leftView(root);
    
    cout << endl;

    // recursive: time: O(N) space: O(height)
    cout << "Left View Of Binary Tree: ";
    recleftView(root, 1);
}