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

int printList(Node *head)
{

    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

int searchList(Node *head, int val)
{
    int cnt = 0;
    while (head != NULL)
    {
        cnt++;
        if (head->data == val)
            return cnt;

        head = head->next;
    }

    return -1;
}

// searchListRec(head(1), 3)                            return (res+1)  (2+1)  == 3 position
//          |                   
//          searchListRec(head(2), 3)                   return res+1  (1+1)
//                  |                       
//                  searchListRec(head(3), 3)           val == head->data return 1
//         

int searchListRec(Node *head, int val) {
    if(head == NULL)
        return -1;
    
    if (head->data == val)
        return 1;

    else
    {
        int res = searchListRec(head->next, val);

        if(res == -1)       
            return -1;
        
        return (res+1);
    }
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    cout << "printing list: ";
    printList(head);

    // we can't use binary serach on linked list coz we can't find middle elem in O(1) time so it's not 
    // possible to implement binary search in O(log N) time

    // time: O(n)   space: O(1)
    cout << "\nelement at position: " << searchList(head, 3);
    
    // time: O(n)   space: O(n)
    cout << "\n(rec)element at position: " << searchListRec(head, 3);
}