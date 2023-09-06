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

void rightView(Node *root)
{
    // using level order traversal method 3 
    // iterative approach: time: O(N)   space: O(width)
    // we just need to store last node from every level as we see right view of Tree
    
    if (root == NULL)
        return;

    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        int count = q.size();

        for(int i = 0; i < count; i++)
        {
            Node *curr = q.front();
            q.pop();

            // only push last node from every level
            if(i == count-1)
                cout << curr->key << " ";

            if(curr->left)
                q.push(curr->left);

            if(curr->right)
                q.push(curr->right);
        }
    }
}   

// recursive: as similar as left view only change is we first call right side of tree so we get first node from right side
int mxLevel = 0;

void recRightView(Node *root, int level)
{
    if(root == NULL)
        return;

    if(mxLevel < level)
    {
        cout << root->key << " ";
        mxLevel = level;
    }

    // same level increment for left & right calls but we using mxLevel so it will print only first 
    // node from that level & change itself with next level only if mxlvl < curr lvl not for (mxlvl == curr lvl)
    recRightView(root->right, level+1);
    recRightView(root->left, level+1);
}

int main()
{
    // Tree looks like this:            o/p: 10 30 50       this is right view of binary tree
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
    cout << "Right View Of Binary Tree: ";
    rightView(root);
    
    cout << endl;

    // recursive: time: O(N) space: O(height)
    cout << "Right View Of Binary Tree: ";
    recRightView(root, 1);
}