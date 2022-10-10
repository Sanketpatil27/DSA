#include<iostream>
using namespace std;

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// function of return_type pointer struct Node to create new node (do not repeat yourself)
struct Node *createNode(int val)    
{
    // creating a node pointer with dynamic memory allocation(in heap)
    struct Node *n = new struct Node();
    n->data = val;
    n->left = NULL;             // setting left children to null
    n->right = NULL;            // setting right children to null

    return n;                   // returning the created node
};


int main(){
    // constructing the root node with functions 
    struct Node *r = createNode(1);

    // constructing the first & second child node respectively with functions 
    struct Node *ch1 = createNode(2); 
    struct Node *ch2 = createNode(3);

    cout << r->data << endl;
    cout << ch1->data << endl;
    cout << ch2->data << endl;

    // linking the root node with the left and right node
    r->left = ch1;             // stores the location of the left node
    r->right = ch2;            // stores the location of the right node
}
