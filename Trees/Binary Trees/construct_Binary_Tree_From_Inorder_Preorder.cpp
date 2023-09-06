#include<iostream>
#include<vector>
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


// printing inorder of tree
void printTree(Node *root)
{
    if (root)
    {
        printTree(root->left);
        cout << root->data << " ";
        printTree(root->right);
    }
}

// return root of constructed tree
// we construct tree Node with respect to the preorder, as it will be easy to guess the root in preorder, in preorder
// we first visit root then goes to left & right 

// we use index to track preorder
int preInd = 0;        // this will be globally distrubuted to all calls with same values

Node *constructTree(vector<int> &inorder, vector<int> &preorder, int start, int end)
{
    // when we complete traversed preorder array
    if(preInd == preorder.size() || start >= end)
        return NULL;

    // create root node of current value of preorder, increment preInd after that
    Node *root = new Node(preorder[preInd++]);

    // now we know in inorder traversal we first visit left side of root so we now decided our root, now find that root 
    // in inorder array, so whatever of left of that value that will lie of the left subtree & other part after root lies in right subtree

    int i;      // to get index of root in inorder array, it should begin from 'start'
    for (i = start; i < end; i++)
    {
        if (inorder[i] == root->data)
        {
            // end = i;
            break;
        }
    }

    // now call for connecting left side of root with left side values of inorder 
    // only end will be change for connecting left subtree with root
    root->left = constructTree(inorder, preorder, start, i);

    // now for connecting right subtree we call with left side of root in inorder array
    // i + 1 coz our loop starts from start so we don't want to include our root again, this is not same case in end
    // in upper call we doesn't include end we go till i < end
    root->right = constructTree(inorder, preorder, i+1, end);

    // at last we return root of our constructed tree
    return root;
}


int main()
{
    // https://practice.geeksforgeeks.org/problems/construct-tree-1/1
    // https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

    // Q. 

    // o/p: Tree looks like below Tree
    //             1
    //           /  \
    //         2     3
    //              /  \
    //            4     5
    //                /
    //              6

    // Node *root = new Node(1);
    // root->left = new Node(2);
    // root->right = new Node(3);
    // root->right->left = new Node(4);
    // root->right->right = new Node(5);
    // root->right->right->left = new Node(6);

    vector<int> inorder = {2, 1, 4, 3, 6, 5};
    vector<int> preorder = {1, 2, 3, 4, 5, 6};

    int start = 0;
    int end = inorder.size();
    Node *root = constructTree(inorder, preorder, start, end);

    cout << "Printing inorder of Constructed Tree: ";
    printTree(root);
}