#include <iostream>
#include <deque>
using namespace std;

// function to rotate deque by k places in anti - clockwise direction.
void left_Rotate_Deq_Byk(deque<int> & deq, int n, int k)
{
    //  we pop k items from front and add them in rear(back) of deque 
    k = k%n;                    // if k > n
    for (int i = 0; i < k; i++)
    {
        int popped = deq.front();
        deq.pop_front();
        deq.push_back(popped);
    }
}

// Function to rotate deque by k places in clockwise direction.
void right_Rotate_Deq_ByK(deque<int> & deq, int n, int k)
{
    // we pop k items from rear and add them in front of deque 
    k = k%n;                     // if k > n
    for (int i = 0; i < k; i++)
    {
        int popped = deq.back();
        deq.pop_back();
        deq.push_front(popped);
    }
}

void printDQ(deque<int> dq)
{
    for (auto i : dq)
        cout << i << ' ';
}

int main()
{
    // Input:
    // 6
    // 1 2 3 4 5 6
    // 1 2

    // Output: 
    // 5 6 1 2 3 4 

    // Explanation: 
    // The dequeue is 1 2 3 4 5 6. 
    // The query type is 1 and k is 2. So, we 
    // need to right rotate dequeue by 2 times. 
    // In 1 right rotation we get 6 1 2 3 4 5. 
    // In another we get 5 6 1 2 3 4.

    deque<int> dq = {1, 2, 3, 4, 5, 6};
    int n = 6;
    int k = 7;

    cout << "Original DQ:         ";
    printDQ(dq);

    cout << "\nleft rotating by k:  ";
    left_Rotate_Deq_Byk(dq, n, k);
    printDQ(dq);

    // this will rotate the deque which is rotated left already
    cout << "\nRight rotating by k: ";
    right_Rotate_Deq_ByK(dq, n, k);
    printDQ(dq);
}