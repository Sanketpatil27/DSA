#include <iostream>
using namespace std;

// cretion on NOdes
struct Node
{
    int data;
    Node *next; // store next node location

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

Node *swapPairs(Node* head) {
    // this porblem exact similar to reverse list in k groups, here k always 2 


    // if list is empty or there is only 1 node 
    if(head == NULL || head->next == NULL)
        return head;


    Node *curr = head;
    Node *prevFirst = NULL;
    bool isFirstPass = true;

    while(curr != NULL)
    {
        int count = 0;
        Node *first = curr;          // first of the 
        Node *next = NULL;          // to store next node
        Node *prev = NULL;          // to store prev node 

        while(curr != NULL && count < 2)                // as pair always of size 2
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;

            // // as we change next to prev, so whatever is on next now on prev so move to prev
            curr = next;      
            count++;
        }

        if(isFirstPass) 
        {
            head = prev;            // we change our head as second node of original list
            isFirstPass = false;    // only run at first pair swap
        }
        else
            prevFirst->next = prev; // we change previous first node's next to new head of pair


        prevFirst = first;       // change prevFirst with 1 node of current original pair
    }

    return head;
}

int main()
{
    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);
    Node *forth = new Node(4);
    Node *fifth = new Node(5);
    Node *sixth = new Node(6);

    // Linking nodes
    head->next = second;
    second->next = third;
    third->next = forth;
    forth->next = fifth;
    fifth->next = NULL;         // for checking odd nodes

    cout << "Before swapping pairwise: ";
    printList(head);

    // exact same approach as reverse list in groups of 'k' here k is always 2 (pairs)l
    // new head after swapping nodes pairwise 
    head = swapPairs(head);
 
    cout << "\nAfter swapping pairwise: ";
    printList(head);
}