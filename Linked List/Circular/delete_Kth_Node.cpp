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

Node *deleteKthNode(Node *head, int k) 
{
    // 1: handle some important corner cases as head is null
    // 2: to stop at previous node of kth node
    // 3: make previous node's next = next of kth node (break link of kth node)
    // 4: delete kth node
    // 5: return head as it is

    // corner case: if head is null or it is only one node then delete it & return NULL, if there is only 1 node then 
    // k must be 1 so deleting head here
    // c++ doesn't throw error if we delete NULL head
    if(head == NULL || head->next == NULL) {
        delete head;
        return NULL;
    }
    
    // we have to explicitly handle the case that if k = 1 head has to be deleted; as next code can't hadle case of if k = 1
    // use the approach of deleting head node
    if(k == 1) {
        head->data = head->next->data;       // store 2nd node data in head
        Node *temp = head->next->next;       // store 3rd node reference 
        
        delete head->next;                   // delete second node as we copied second node in head
        head->next = temp;

        return head;                         // return modified head
    }

    Node *curr = head;
    // we have to stop at previous node of kth node
    for(int i = 0; i < k-2; i++)          // as k can't exceed the length of nodes in list
        curr = curr->next;
    

    // as from 2nd step we are at previous node of kth node
    Node *temp = curr->next;                   // store kth node to be deleted
    curr->next = curr->next->next;            // modifying previous node's next

    // now delete temp node which is holding kth node
    delete temp;

    // return ehad as it is
    return head;
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

    cout << "Linked List Before deletion of kth Node: ";
    printList(head);

    // neive approach:
    int k = 2;                              // k is always  1 <= k <= no. of total Nodes
    // new head after deleting kth node O(n)
    head = deleteKthNode(head, k); 

    // efficient approach: time: O(1)
    // head = efficient(head);

    cout << "\nLinked List after deletion of Kth Node: ";
    printList(head);
}