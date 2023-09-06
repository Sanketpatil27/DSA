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

// time: O(n)
int height(Node *root)
{
    if (root == NULL)
        return 0;

    return max(height(root->left), height(root->right)) + 1;
}

// time: O(H * n) H is height
void kDist(Node *root, int k)
{
    if (root == NULL)
        return;
    
    if(k == 0)
        cout << root->key << " ";
        
    kDist(root->left, k-1);
    kDist(root->right, k-1);
}


// Neive:
void levelOrderTraversal(Node *root)
{
    // step1: we first get height of tree
    // step2: we start k from 0 till height of tree so, k tells no.of level to print

    int h = height(root);
    int k = 0;

    // k will start from level 0 and goes till last level and print level wise nodes
    while (k < h)
    {
        kDist(root, k);             // this will print nodes for every level k
        k++;
    }
}


// efficient approach:
void BFS(Node *root)
{
    // step1: we enqueue first level int Q
    // step2: then deque front node and print it, and enqueue its childs in Q (means next level of current node)
    // ex:    enque Q = [10] first, then deque 10 and print it, then enque its childs that is Q = [20, 30], then 
    //        pop 20 & print it & push its childs Q = [30, 70] , 20 only has 1 child, and we do it until last level is 
    //        processed, means till Q becomes empty

    if(root == NULL)
        return;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *curr = q.front();      // deque current node & print it
        q.pop();
        cout << curr->key << " ";   

        // enqueue next level of current popped node

        // if there is left child of current node present in tree then enqueue it
        if(curr->left)
            q.push(curr->left);

        // if there is right child of current node present in tree then enqueue it
        if(curr->right)
            q.push(curr->right);
    }    
}

int main()
{
    // Tree looks like this:              o/p: 10 20 30 70 40 50
    //             10           Level 0
    //           /  \
    //         20    30         Level 1
    //        /     /  \
    //      70    40    50      Level 2

    Node *root = new Node(10);
    root->left = new Node(20);
    root->left->left = new Node(70);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);

    // neive: overall Time: O(h * n)
    cout << "Level Order Traversal: ";
    levelOrderTraversal(root);
    
    cout << endl;

    // since we can't stop at specific level of left subtree and continue right subtree for that level, so recursion is 
    // not good idea here, so We USE QUEUES 
    // time: O(n)               every node enqueue & deque only once
    // space:  theta(width)     at max there are width number of current level nodes will be present in queue
    cout << "Level Order Traversal: ";
    BFS(root);
}