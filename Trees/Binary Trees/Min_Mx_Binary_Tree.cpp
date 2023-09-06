#include <iostream>
#include <queue>
#include <limits.h>
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

int findMax(Node *root)
{
    queue<Node *> q;
    q.push(root);
    int mx = INT_MIN;

    while (q.size())
    {
        Node *curr = q.front();
        q.pop();

        mx = max(mx, curr->key);

        if (curr->left)
            q.push(curr->left);

        if (curr->right)
            q.push(curr->right);
    }

    return mx;
}

int findMin(Node *root)
{
    queue<Node *> q;
    q.push(root);
    int mn = INT_MAX;

    while (q.size())
    {
        Node *curr = q.front();
        q.pop();

        mn = min(mn, curr->key);

        if (curr->left)
            q.push(curr->left);

        if (curr->right)
            q.push(curr->right);
    }

    return mn;
}

// recursive:
int recfindMax(Node *root)
{
    // recursive solution
    if (root == NULL)
        return INT_MIN;

    else
        return max(root->key, max(recfindMax(root->left), recfindMax(root->right)));
}

int recfindMin(Node *root)
{
    if (root == NULL)
        return INT_MAX;

    else
        return min(root->key, min(recfindMin(root->left), recfindMin(root->right)));
}

int main()
{
    // Tree looks like this:            o/p: max = 50, min = 10
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

    // iterative approach using queues  time: O(N)  space: O(width) 
    // queue approach same as level order binary tree traversal
    // for each level we check max and min
    cout << "Maximum: " << findMax(root) << endl;
    cout << "Minimum: " << findMin(root) << endl;

    // using recursive: time: O(N) space: O(height)
    cout << "Maximum: " << recfindMax(root) << endl;
    cout << "Minimum: " << recfindMin(root) << endl;
}