#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *ptr)
{
    int pal = 0, sum = 0, n = 0, rem = 0;
    while (ptr != NULL)
    {
        cout << "Element: " << ptr->data << endl;
        n = (n * 10) + ptr->data;       // to store the elements in one integer
        ptr = ptr->next;
    }

    pal = n;
    while (n > 0) {
        rem = n%10;     
        sum = sum*10 + rem;     // it will adding the last numbers of the n
        n /= 10;                // it will update the n with removed last number
    }

    if (pal == sum)
    {
        cout << "Linked List is Palindrome!" << endl;
    }
    else
    {
        cout << "Linked List is not Palindrome!" << endl;
    }    
}

int main()
{
    struct Node *head = new struct Node;
    struct Node *second = new struct Node;
    struct Node *third = new struct Node;

    head->data = 2;
    head->next = second;

    second->data = 6;
    second->next = third;

    third->data = 2;
    third->next = NULL;

    
    linkedListTraversal(head);
}
