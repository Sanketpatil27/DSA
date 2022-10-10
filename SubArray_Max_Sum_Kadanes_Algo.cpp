// kadane's algorithm

//    Enter an Array: 1 2 3 4
//    SubArray: 
//    1                 sum = 1
//    1 2               sum = 3
//    1 2 3             ...
//    1 2 3 4           sum = 10
//    2                 .
//    2 3               .
//    2 3 4             .
//    3                 .
//    3 4               .
//    4                 sum = 4
//                      MaxSubArraySum = 10

#include <iostream>
#include <climits>           // to use INT_MIN
using namespace std;

int main(){
    int n = 4;
    int a[n];
    int currentSum = 0;         // it will store the sum of the subArray elements
    int maxSum = INT_MIN;

    cout << "Enter an Array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

// max sum always be on the first iteration of the subArray, if there's no negative value,
// so nested loops not needed like SubArray.cpp code

    for (int i = 0; i < n; i++)     
    {
        currentSum += a[i];
        if (currentSum < 0)     // if *sum* is negative, restart the counting to count maximum sum
        {
            currentSum = 0;     // to update the current sum of subArray, and restart the counting from next subArray
        }
        maxSum = max(maxSum, currentSum);
    }

    cout << "Maximum Sum of subArray is: " << maxSum;
}