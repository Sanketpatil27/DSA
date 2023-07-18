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

bool detectLoop(Node *head)
{
    // we use hashing to store nodes
    // 1. create unordered_set<Node *> of type node 
    // 2. Traverse List. if we found curr node already stored in set then we reutrn true as loop detected
    // 3. else we store that curr node in set & move to next node
    // 4. loop will only end when we saw NULL there so, it means no cycle there so return false

    unordered_set<Node *> s;

    Node *curr = head;
    while(curr != NULL)
    {
        // if we find same pointer in set already present, then return true
        if(s.find(curr) != s.end()) 
            return true;

        s.insert(curr);
        curr = curr->next;
    }

    // the loop will only stop when curr becomes null means no cycle in list
    return false;
}

bool floydsCycleDetection(Node *head)
{
    // we use slow and fast pointer technique
    // 1. initiallize both fast & slow as head initially
    // 2. move slow by 1 node & fast by 2 nodes
    // 3. if they meet each other means htere is loop in liked list
    

    Node *slow = head;
    Node *fast = head;

    // 1st condition for even lenght nodes & 2nd condition for odd length nodes
    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        // checking after moving nodes coz initially they both points to head so we have to move them first
        if(fast == slow)
            return true;
    }

    // the loop will only stop when fast reaches null means no cycle in list
    return false;
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
    fifth->next = second;

    // using hashing time: O(n) space: O(n)
    // bool ans = detectLoop(head);
    
    // using two pointes time: O(n) space: O(1)
    bool ans = floydsCycleDetection(head);

    if(ans)
        cout << "\nList contain Loop";
    else
        cout << "\nList not contain loop";
}