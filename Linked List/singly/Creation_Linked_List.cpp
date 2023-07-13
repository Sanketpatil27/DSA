#include <iostream>
using namespace std;

// this is the node representation
struct Node {
    int data;

    // pointer type of same as structure, such structures called self refferential structures
    Node *next;
    
    // creating constructor for assigning value for data & next address at the node creation time
    Node(int val) {
        data = val;
        next = NULL;
    }
};

int main() {

    // allocating nodes in heap using new keyword & assigning data to nodes through constructor        
    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);

    // now we link the nodes 
    head->next = second;
    second->next = third;
    third->next = NULL;          // this not required coz already constructor did it while creation of node

    // short form (no need of second & third variables) of making three nodes
    // & assigning data & next pointer to it is:

    // Node *head = new Node(10);
    // head->next = new Node(20);
    // head->next->next = new Node(30);

    return 0;
}