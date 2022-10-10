// left rotate an array by 1
#include <bits/stdc++.h>
using namespace std;


void leftRotate(int a[], int n) {
    int temp = a[0];     // store the first elemtent
    for (int i = 1; i < n; i++)
    {
        a[i-1] = a[i];      // current value store to the previous index
    }
    a[n-1] = temp;
}


void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    cout << endl;
}

int main()
{
    int n = 6;
    int a[n] = {1, 2, 3, 4, 5, 6};
    cout << "Before left rotation: ";
    printArray(a, n);
    cout << "After left rotation:  ";
    leftRotate(a, n);
    printArray(a, n);
}