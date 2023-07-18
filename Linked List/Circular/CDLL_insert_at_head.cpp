// circular doubly linked list  (CDLL)
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;

    Node(int val)
    {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

// traversal of circular doubly Linked list is same as traversal of circular list
void printList(Node *head)
{
    // checking this corner case seperately coz using do while this will access NULL's data & next without checking
    // it is null or not
    if(head == NULL) {
        cout << "empty list!";
        return;         // this is imp for not accessing next content
    }


    Node *curr = head;

    // using do while coz we have to first print data of first node & then go to next node without checking condition
    do {
        cout << curr->data << " ";
        curr = curr->next;
    } while (curr != head);          // we stop when we see head as current node again
}


Node *insertAtHead(Node *head, int val) {
    // appraoch: 
    // 1. Create New Node as newHead for new head of list
    // 2. make newNode-> next = head & newNode-> prev = tail node
    // 3. make Tail->next = newNode    (we get tail by head->prev, before modifying head->prev as newNode)
    // 4. and then we modify head->prev = newNode
    // 5. return newNode as new head

    Node *newHead = new Node(val);

    // corner cases:
    if(head == NULL) {
        newHead->next = newHead;
        newHead->prev = newHead;
        return newHead;
    }

    // 2nd step:
    newHead->next = head;
    newHead->prev = head->prev;       // this is how get tail node from head node

    // step 3: we make tail nodes next as new Node
    head->prev->next = newHead;     // head->prev is tail node & we accessing its next 

    // step 4: update head's prev as newNode
    head->prev = newHead;

    // return newHead as new head
    return newHead;         
}


int main()
{
    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);

    // now we link nodes next & prev pointers to other nodes
    head->prev = third;
    head->next = second;

    second->prev = head;
    second->next = third;

    third->prev = second;
    third->next = head;

    // head = NULL;        // this is to ensures the code works even for null head

    cout << "Linked List before insertion at head: ";
    printList(head);


    // time: O(1)      **same approach for insert tail, just don't reutnr newNode as head return head as it is**
    cout << "\nLinked List after insertion at head: ";

    head = insertAtHead(head, 12);
    head = insertAtHead(head, 123);

    printList(head);
}