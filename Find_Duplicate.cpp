#include<iostream>
using namespace std;

// given an array with size n. 1 to n-1 all elems are present in array and one remaining is duplicate
// find that duplicate element
// video: https://www.youtube.com/watch?v=oVa8DfUDKTw&t=851s

// n = 5, array = 2 1 4 3 2
// 2nd loop for XOR , 1 to n-1 = 1 2 3 4  stored in ans 
// in XOR operation 2 gone for 2 just like that all other elements will gone and that 3rd time of 2 is as it is returned coz, 0^2 = 2 

int duplicate(int a[], int n) {
    int ans = 0;

    // we have to make duplicates of all array elems, then that one duplicate elem is becomes 3 times

    // when taking two loops that one duplicate becomes three times , after removing two of them , last is returned

    // XORing all array elems
    for (int i = 0; i < n; i++)
    {
        ans ^= a[i];
    }
    // XORing 1 to n-1 elems
    for (int i = 1; i < n; i++)
    {
        ans ^= i;
    }
    // in exp: 1 2 3 4 2 , 1 will gone for 2nd loop 1 , 2 gone for 2nd loop 2, as it is ,then ans becomed 0,then extra 2 is returned as it is
    return ans; 
}

int main(){
    int n;
    cout << "Enter Array size: ";
    cin >> n;

    int a[n];

    cout << "Enter Array Elems: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << "Duplicate number in array is: " << duplicate(a, n) << endl;
}