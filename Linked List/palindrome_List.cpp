#include <bits/stdc++.h>
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
    Node *curr = head;

    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next; // assigninng next node to current node
    }
}

Node *reverseList(Node *mid)
{
    Node *next = NULL;
    Node *prev = NULL;

    while(mid != NULL) {
        next = mid->next;
        mid->next = prev;
        prev = mid;

        mid = next;         // jump on next node
    }

    // our previous will remain on last node which is now our head
    return prev;
}

bool isPalindrome(Node* head) {
    // find middle and reverse from middle
    Node *slow = head;
    Node *fast = head;

    while(fast != NULL && fast->next != NULL) 
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // now we have middle node on slow, reverse it
    Node *reversed = reverseList(slow);

    // now check first half & second reversed half
    while(reversed != NULL) {
        if(reversed->data != head->data)
            return false;

        reversed = reversed->next;
        head = head->next;
    }

    // loop successfully complete means all nodes are same!
    return true;
}


int main()
{
    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *forth = new Node(20);
    Node *fifth = new Node(10);
    
    // linking
    head->next = second;
    second->next = third;
    third->next = forth;
    forth->next = fifth;
    fifth->next = NULL;


    // time: O(n) space: O(1)
    cout << "linked List: ";
    printList(head);

    cout << "\nIs List Palindrome: "  <<  isPalindrome(head);
}