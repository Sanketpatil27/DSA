// InOrderTraversal- left root right (structure fo InOrder tree)

#include<iostream>
using namespace std;

struct Node 
{
    int data; 
    struct Node *left;          // stores address of left subtree
    struct Node *right;         // stores address of right subtree
};

struct Node *createNode(int val) {
    struct Node *n = new struct Node();
    n->data = val;
    n->left = NULL;         // setting root node's left to null initially
    n->right = NULL;        // setting root node's right to null initially

    return n;
}

void inOrderTraverse(struct Node *root) {
    if (root != NULL)
    {
        // using recursion to traverse left subTree
        inOrderTraverse(root->left); 

        cout << root->data << " ";  // printing nodes in inOrder

        // using recursion to traverse right subTree
        inOrderTraverse(root->right); 
    }
}

int main(){
    // creating root node
    struct Node *r = createNode(4);
    // creating left node of root
    struct Node *ch1 = createNode(1);
    // creating right node of root
    struct Node *ch2 = createNode(6);
    // creating Left node of ch1
    struct Node *sch1 = createNode(5);
    // creating left right node ch1
    struct Node *sch2 = createNode(2);

    // Linking all nodes as above discussed
    r->left = ch1;
    r->right = ch2;
    ch1->left = sch1;
    ch1->right = sch2;

    // traverse code
    inOrderTraverse(r);

    // Final tree looks like this
    //             4
    //           /  \
    //          1    6
    //        /  \
    //       5    2
    // InOrder : left root right = 5 1 2 4 6
}