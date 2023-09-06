#include<iostream>
#include<stack>
#include<queue>
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

// using level order traversal and store alternate levels in stack to print nodes of that level in Reversed order
// time: O(N) (but every node pushed & poped from queue exact once but node can also be push & pop from stack so node traverse at most 4 times O(4N))
// space: O(width)
void zigZagTraverse(Node *root)
{
    if(!root)
        return;

    stack<int> s;
    queue<Node*> q;
    q.push(root);
    bool reverse = false;               // to tell which level has to be print in reverse order

    while (!q.empty())
    {
        int count = q.size();

        for (int i = 0; i < count; i++)
        {
            Node *curr = q.front();
            q.pop();
            
            // if the level has to be reversed then only put its nodes data in stack
            if (reverse)
                s.push(curr->data);
            else
                cout << curr->data << " ";

            if(curr->left)
                q.push(curr->left);
            
            if(curr->right)
                q.push(curr->right);
        }
        
        // now check if current level present in stack to reverse
        while (!s.empty())
        {
            cout << s.top() << " ";
            s.pop();
        }
        
        // revert the flag for next level
        reverse = !reverse;
    }
}


// time: O(N)   space: O(width)     (almost 2 operations will be performed on any node)
// we use 2 stacks 1 will stores leveled nodes & other stores their childs alternatively 
// first fill entire level then fill their entire childs 
// storing will happen something like level-order-traversal
// run loop till both becomes empty 
void spiralTraversal(Node *root)
{
    if (!root)
        return;

    stack<Node*> s1;  
    stack<Node*> s2;  

    // fill entire first level
    s1.push(root);

    while (!s1.empty() || !s2.empty())
    {
        // s2 will store nodes in 'left to right' manner  (traverse level right to left, LIFO order)
        while(!s1.empty())
        {
            Node *curr = s1.top();
            s1.pop();

            cout << curr->data << " ";

            if(curr->left) 
                s2.push(curr->left);
            
            if(curr->right) 
                s2.push(curr->right);
        }
        
        // s1 will store nodes in 'right to left' manner  (traverse level left to right, LIFO order) 
        while(!s2.empty())
        {
            Node *curr = s2.top();
            s2.pop();

            cout << curr->data << " ";
            
            if(curr->right) 
                s1.push(curr->right);

            if(curr->left) 
                s1.push(curr->left);
        }
    }
}

int main()
{
    // https://practice.geeksforgeeks.org/batch/dsa-4/track/DSASP-Tree/problem/zigzag-tree-traversal
    // https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

    // Q. for even levels traverse from left to right, for odds traverse from right to left (level starts from 0)

    // Tree looks like:            o/p:  1 3 2 4 5 6
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

    // neive approach: timeO(N)   space: O(width)
    cout << "Spiral/Zig-Zag Traversal: ";
    zigZagTraverse(root);

    // efficient solution: time: O(N)    space: O(width)
    cout << "\nSpiral/Zig-Zag Traversal: ";
    spiralTraversal(root);
}