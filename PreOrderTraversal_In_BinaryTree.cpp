// root left right (structure fo preorder tree)
#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// creating function of return type struct Node
struct Node *createNode(int val) {
    struct Node *n = new struct Node();
    n->data = val;
    n->left = NULL;
    n->right = NULL;

    return n;
}

void preOrderTraverse(struct Node *root) {
    // it means run until any subtree reaches to the final node or leaf node 
    if (root != NULL)        
    {
        cout << root->data << " ";

        // after recursion all the function run for the following subtree(either left or right or every subTree)
        preOrderTraverse(root->left);       // traverse for left subTree using recursion
        // when it compleates the all left subTrees then it comes to the right subTrees. for first default root
        preOrderTraverse(root->right);      // traverse for right subTree using recursion
    }
}

int main()
{
    struct Node *r = createNode(4);
    struct Node *ch1 = createNode(1);
    struct Node *ch2 = createNode(6);
    struct Node *ch3 = createNode(5);    //creating subchild
    struct Node *ch4 = createNode(2);    //creating subchild 


    // linking root node with left and right node
    r->left = ch1;
    r->right = ch2;
    ch1->left = ch3;
    ch1->right = ch4;

    preOrderTraverse(r);

    // Final tree looks like this
    //             4
    //           /  \
    //          1    6
    //        /  \
    //       5    2
}