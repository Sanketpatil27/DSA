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

vector<vector<int>> levelOrder(Node *root)
{
    vector<vector<int>> ans; // store values level-by-level
    vector<int> currLvl;     // push the current level node values only

    if (root == NULL)
        return ans;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int count = q.size();

        // we don't use q.size() condition in for loop coz it changes its size in for loop we are adding next level in Q
        for (int i = 0; i < count; i++)
        {
            Node *curr = q.front(); // deque current node & print it
            q.pop();

            if (curr->left)
                q.push(curr->left);

            if (curr->right)
                q.push(curr->right);

            currLvl.push_back(curr->key);
        }

        ans.push_back(currLvl);
        currLvl.clear();        // clear it for storing next level
    }

    return ans;
}

void BFS(Node *root)
{
    if (root == NULL)
        return;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int count = q.size();

        // we don't use q.size() condition in for loop coz it changes its size in for loop we are adding next level in Q
        for (int i = 0; i < count; i++)
        {
            Node *curr = q.front(); // deque current node & print it
            q.pop();

            cout << curr->key << " ";
            if (curr->left)
                q.push(curr->left);

            if (curr->right)
                q.push(curr->right);
        }

        cout << endl;
    }
}

int main()
{
    // this is Method 3
    // this question is extension of previous level Order problem where we have to print each level values on different lines
    // https://leetcode.com/problems/binary-tree-level-order-traversal/ leetCode problem, method 2  don't work for this
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

    // time: O(n) as every nodes enqueued and dequeued only Once, and enque, deque are constant time operations
    // Space: O(width) at max there can be max width of level nodes present in queue

    // modification from the previous method 2
    // here we uesd 2 loops inner loop will print current level
    // outer loop print new line after current level printed then it goies to next level

    cout << "BFS Level By Level: " << endl;
    BFS(root);

    cout << endl;

    // this is for leetcode question:
    vector<vector<int>> ans = levelOrder(root);

    cout << "BFS Level By Level: " << endl;
    cout << '[';
    for (auto i : ans)
    {
        cout << '[';
        for (int j : i)
            cout << j << ' ';

        cout << "] ";
    }

    cout << ']' << endl;
}