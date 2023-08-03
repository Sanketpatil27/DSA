#include<iostream>
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
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

Node* removeElements(Node* head, int val) {
    // first check if head has to be change explicitly
    // move head till head->data != data
    if(head && head->data == val)
    {
        Node *temp = head;
        head = head->next;
        delete temp;            // deleting node from memory

        head = removeElements(head, val);   // recursive call for next head
    }

    // means after loop head reaches NULL means all nodes containing data == data
    if(!head)   
        return head;

    // loop till next Node is not NULL, coz we are checking next nodes data
    Node *curr = head;

    if(curr && curr->next)
    {
        // if next node having same data then break connection with it & don't move to next node
        // till next node's data != data
        if(curr->next->data == val)
        {
            Node *temp = curr->next;
            curr->next = curr->next->next;      
            delete temp;                    // deleting node from memory

            curr = removeElements(curr, val); // call for same node till next node's->data != data
        }
        else
        {
            curr = curr->next;
            curr = removeElements(curr, val);            // call for next node
        }
    }

    return head;
}


int main()
{
    Node *head = new Node(12);
    head->next = new Node(78);
    head->next->next = new Node(78);
    head->next->next->next = new Node(34);
    head->next->next->next->next = new Node(78);

    cout << "Original List: ";
    printList(head);

    int val = 78;
    head = removeElements(head, val);
    // new head after removing nodes with data == data
    cout << "\nnew list after removing val nodes: ";
    printList(head);
}