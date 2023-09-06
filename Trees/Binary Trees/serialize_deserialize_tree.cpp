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

void preorder(Node *root)
{
    if(root == NULL)    
        return;

    // printing leftmost node of current subtree
    cout << root->data << " ";
    
    // call for left sub-tree
    preorder(root->left);

    // call for right sub-tree
    preorder(root->right);
}

// we use preorder traversal to store nodes
// we store -1 as if there is NULL node (data always given in positive numbers)
void helper(Node *root, vector<int> &ans)
{
    if(!root)
    {
        ans.push_back(-1);
        return;
    }
    
    ans.push_back(root->data);
    
    helper(root->left, ans);
    helper(root->right, ans);
}

vector<int> serialize(Node *root) 
{
    vector<int> nodes;
    helper(root, nodes);
    
    return nodes;
}

int ind = 0;      // global variable to manage our current index in array 
Node * deSerialize(vector<int> &A)
{
    if(ind == A.size())
        return NULL;
        
    // get current value & increment index 
    int val = A[ind];
    ind++;              
        
    // if element at current index is -1 then also we return -1
    if(val == -1)
        return NULL;
        
    Node *root = new Node(val);
    
    // link left & right part to root
    root->left = deSerialize(A);
    root->right = deSerialize(A);
    
    // and return the root
    return root;
}

int main()
{
    // https://practice.geeksforgeeks.org/problems/serialize-and-deserialize-a-binary-tree/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
    
    // Q. Serialization is to store a tree in an array
    // Deserialization is reading tree back from the array.

    // Tree looks like:            
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
    
    cout << "Original Tree: ";
    preorder(root);
    cout << endl;
    
    // time: O(N)  space: O(N)      for both serialize & deserialize

    vector<int> nodes = serialize(root);
    
    // for debuging, to check that the vector filled correctly
    cout << "Serilized Tree: "; 
    for(auto i: nodes)
        cout << i << " ";
    cout << endl;

    // new recreated tree
    cout << "Deserialized Tree: ";
    root = deSerialize(nodes);
    preorder(root);
}