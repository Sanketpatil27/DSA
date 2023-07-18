#include <iostream>
#include <unordered_set>
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

int detectLoop(Node *head)
{
    // we use hashing to store nodes
    // 1. create unordered_set<Node *> of type node
    // 2. Traverse List. if we found curr node already stored in set then we reutrn true as loop detected
    // 3. else we store that curr node in set & move to next node
    // 4. loop will only end when we saw NULL there so, it means no cycle there so return false

    unordered_set<Node *> s;

    Node *curr = head;
    while (curr != NULL)
    {
        // if we find same pointer in set already present, then this is our starting point of the cycle
        if (s.find(curr) != s.end())
            return curr->data;

        s.insert(curr);
        curr = curr->next;
    }

    // the loop will only stop when curr becomes null means no cycle in list
    return -1;
}


int getStartingPoint(Node *head, Node *fast)
{
    // we make slow at head and fast as it is
    Node *slow = head;
    
    // and move both by 1 step at time and when they meet that is tehir meeting point
    while(slow != fast) 
    {
        slow = slow->next;
        fast = fast->next;
    }
    
    // at this point they are at same node which is starting point of cycle
    return slow->data;
}

int floydsCycleDetection(Node *head)
{
    // approach 2: we use floyd's cycle detection algorithm
    // for reference use detect loop in list problem

    Node *slow = head;
    Node *fast = head;

    while(fast != NULL && fast->next != NULL) 
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
            break;
    }

    // to ensure the linked list has stopped becasue of null present, means no cycle is there
    if(fast == NULL || fast->next == NULL)
        return -1;


    // else here our implementation for returning start point of loop

    return getStartingPoint(head, fast);
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
    fifth->next = NULL;

    cout << "Linked List: ";
    printList(head);

    // creating loop by changing last node to any other node in list
    // do not traverse it after making loop in list, coz there is no null to stop loop!!!
    fifth->next = third;

    // using hashing time: O(n) space: O(n)
    cout << "\ncycle starting point: " << detectLoop(head);

    // using two pointes time: O(n) space: O(1)
    cout << "\ncycle starting point: " << floydsCycleDetection(head);
}