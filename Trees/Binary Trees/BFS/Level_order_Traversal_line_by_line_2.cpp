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

void BFS(Node* root) {
    // modification of the previous simple level order Problem's, new steps for this problem is 
    // step1: when we traverse current level completely we push a NULL marker into Q as next level completely enqueqed in Q
    // step2: and when we see NULL next time we sure that complete next level there in the queue
    //        so we can push another NULL as for next level completion mark. (DRY RUN IT)

    if(root == NULL)
        return;

    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (q.size() > 1)
    {
        Node *curr = q.front();      // deque current node & print it
        q.pop();

        if(curr == NULL)
        {
            cout << endl;
            q.push(NULL);                   // push null for next complete level is in Q
            continue;                       // go to next node (next level starting)
        }

        cout << curr->key << " "; 

        // enqueue next level of current popped node
        // if there is left child of current node present in tree then enqueue it
        if(curr->left)
        {
            q.push(curr->left);
        }

        // if there is right child of current node present in tree then enqueue it
        if(curr->right)
        {
            q.push(curr->right);
        }
    }
}


int main()
{
    // this is Method 2
    // this question is extension of previous level Order problem but here we have to print each level values on different lines
    // https://leetcode.com/problems/binary-tree-level-order-traversal/ leetCode problem, this method  don't work for this 
    // problem coz when we see Null it means next level nodes are there in our arry also and we print them as in they are in same level

    // Tree looks like this:              o/p: 10 '\n' 20 30 '\n' 70 40 50
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
    
    cout << "BFS Level By Level: " << endl;
    BFS(root);
    cout << endl;
}