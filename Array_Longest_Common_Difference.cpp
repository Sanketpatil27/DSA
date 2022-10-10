// Question from ||google's kick start||        // from apna college array practice Qs cpp course
// (simple Qs. - length of the longest contiguous arithmetic subarray)

// Problem:
// An arithmetic array is an array that contains at least two integers and the 
// differences between consecutive(सलग, क्रमागत)integers are equal. 
// For example, [9, 10], [3, 3, 3], and [9, 7, 5, 3] are arithmetic arrays,
// while (1, 3, 3, 7], [2, 1, 2], and [1, 2, 4) are not arithmetic arrays.
// Sarasvati has an array of N non-negative integers. The i-th integer of the array is A. 
// She wants to choose a contiguous arithmetic subarray from her array that has the maximum length.
// Please help her to determine the length of the longest contiguous arithmetic subarray.


// this will include all the header files, used in compitions to save the time
#include "bits/stdc++.h"

using namespace std;

int main()
{
    int n = 7;
    int a[n];

    cout << "Enter 7 array elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int ans = 0;          // stores the maximum length of the contiguous common differences
    int pd = a[1] - a[0]; // it stores the previous common difference of array elems, initially it is storing the first two elems difference
    int curr = 2;         //  current length, it initially 2, coz we getting difference between minimum 2 numbers
    int j = 2;            // 2 coz we already check difference for a[0] and a[1], so start with next index

    while (j < n)
    {
        if (pd == a[j] - a[j - 1])   // previous common difference is compared with current common difference
        {
            curr++;     // when difference is matches then we increase the length of contiguous elems
        }
        else
        {
            curr = 2;  // if difference not matches then we reset the current length, coz our streak of matching elems is break
        }
        ans = max(ans, curr);  // here we are checking the length of previous longest streak vs current streak
        j ++;
    }
    cout << "Longest length of countiguous subarray is: " << ans << endl;
}