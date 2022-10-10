// reverse the array after the k'th index
#include <bits/stdc++.h>
using namespace std;

void reverseArray(int a[], int n, int k)
{
    int s = k + 1, e = n - 1; // start will assign to k'th index + 1, coz reverse after that index
    while (s < e)
    {
        // s will increment and end will decrement after that instruction
        swap(a[s++], a[e--]);
    }
}

void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    cout << endl;
}

int main()
{
    int n = 9;
    int a[n] = {10, 4, 5, 2, 3, 6, 1, 3, 6};
    cout << "Before reversing: ";
    printArray(a, n);
    cout << "After reversing: ";
    reverseArray(a, n, 3);
    printArray(a, n);
}