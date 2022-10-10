// Q.remove duplicates from sorted array, an return the new index until non-duplicates

#include <bits/stdc++.h>
using namespace std;

// (self made) aslo on GFG: time complexity: O(n), auxilary space: O(1)  (efficient way) + (two pointer algorithm)

// this function will return the new size of array to be considered, the elements under that size will not be duplicate
int removeDuplicate(int a[], int n)
{
    int cnt = 1; // it will help to access a[1]th element first time
                 // first (a[0]) element will always be in array, so we start comparing from 1st index
    for (int i = 1; i < n; i++)
    {
        if (a[i] != a[cnt - 1]) // it check if previous copied element is same or not with current elem
        {
            a[cnt++] = a[i]; // changing duplicate elements of the arr to not-duplicate elements
                             // cnt will increase ifter this instruction
        }
    }
    return cnt; // returning new size to array instead of old n
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
    int a[n] = {10, 10, 20, 20, 70, 70, 89, 89, 90};
    printArray(a, n);
    n = removeDuplicate(a, n);
    printArray(a, n);
}
