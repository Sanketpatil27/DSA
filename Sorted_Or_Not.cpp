#include <bits/stdc++.h>
using namespace std;

//checking if array is sorted or not in non-decreasing order, same elems are allowed
// O(n) complexity - traversing elements only one time

bool isSorted(int a[], int n) {
    // setting zero'th  index to previous, so checking from first index
    for (int i = 1; i < n; i++)
        if (a[i] < a[i-1])      // if current elem is less than previous index then return false
            return false;

    return true;        // if not return in loop, means it is sorted
}

int main(){
    int a[] = {1,2,35,74,74,222};
    int n = 6;      // size of the array
    cout << isSorted(a, n);

    return 0;
}