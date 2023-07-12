#include<iostream>
using namespace std;
 
// cretion on NOdes
struct Node
{
    int data;
    Node *prev;         // store previous node location
    Node *next;         // store next node location

    Node(int val) {
        data = val;
        prev = NULL;
        next = NULL;
    }
};


int main()
{
    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);

    // link created nodes, store all nodes previous location & next locations
    head->next = second;            // previous of this is already NULL, in Constructor
    second->prev = head;            
    second->next = third;
    third->prev = second;           // next of this is stored null while constructing

    cout << "3 nodes created successfully!!" << endl;
}