#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void printList(Node *head)
{
    // checking this corner case seperately coz using do while this will access NULL's data & next without checking
    // it is null or not
    if (head == NULL)
        cout << "empty list!" << endl;

    // use temp node for traversing and stop when we again see head
    // using do while coz we have to first print data of first node & then go to next node without checking condition
    Node *curr = head;
    do
    {
        cout << curr->data << " ";
        curr = curr->next;
    } while (curr != head);
}

Node *deleteHead(Node *head)
{
    // 1: handle some important corner cases as head is null or head is only 1 node
    // 2: we have reach till last node to get pointer to head node to maintain circular manner
    // 3: make last node's next = second node
    // 4: delete head from memory
    // 4: we are at last node so return it's next(second node) as head node

    // corner case: if head is null or it is only one node then delete it & return NULL
    // c++ doesn't throw error if we delete NULL head
    if(head == NULL || head->next == NULL) {
        delete head;
        return NULL;
    }

    Node *curr = head;
    while (curr->next != head)
        curr = curr->next;
    
    // as from 2nd step we are at last node 
    curr->next = head->next;            // modifying last node's circular next

    delete head;

    // as now we are at last node & modified its next circular pointer so return it's next as head node
    return curr->next;
}

Node *efficient(Node *head)
{
    // copy data of second node in head; so we assign head to second node and delete second node
    // 1: set data of head as data of second node (corner cases same as up appraoch)
    // 2: make head->next = third node (link head to direct third node)
    // 3: delete second node (as it has assigned to head data)
    // 4: return head as it is (containing second node data)

    if(head == NULL || head->next == NULL) {
        delete head;
        return NULL;
    }
    

    head->data = head->next->data;
    
    // as per 2nd step: store reference to third node
    Node *temp = head->next->next;         

    // delete second node
    delete head->next;

    // allcate head's next pointer to third node
    head->next = temp;

    // return head as it is
    return head;    
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    // link last node's next to head
    head->next->next->next = head;

    cout << "Linked List Before deletion of head: ";
    printList(head);

    // neive approach:
    // new head after deleting head O(n)
    head = deleteHead(head);

    // efficient approach: time: O(1)
    head = efficient(head);
    // head = efficient(head);

    cout << "\nLinked List after deletion of head: ";
    printList(head);
}