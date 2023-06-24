// Google Interview Question (leetCode)

// Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.
// Return the minimized largest sum of the split.
// A subarray is a contiguous part of the array.

// Example 1:
// Input: nums = [7,2,5,10,8], k = 2
// Output: 18
// Explanation: There are four ways to split nums into two subarrays.
// The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.


// case1: 
// min partitions can be 1, where all array is calculated and our answer is the total sum
// case2:
// max partitions can be n, where all elements have individual partition, then our ans is 
// max element in that array

// so here we know,
// low answer = max element of that array (from case1)
// high answer = sum of all elements (from case2)
// here we got a range [low, high] answer must lie between this 


#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
 
int splitArray(vector<int>& arr, int m) {
        
    int low = 0, high = 0;

    // to find low & high we have to check the array
    for (int i = 0; i < arr.size(); i++)
    {
        // we usign low & high according case1 & case2 from notes:
        // low contain max value from array & 
        // high will contain total sum of array 
        low = min(low, arr[i]);
        high += arr[i];
    }
    

    // so we find the range[low, high] now check with binary search

    while (low < high)
    {
        int mid = (low + high) / 2;

        // calculate in how many pieces we can devide this int with maximum sum
        int sum = 0;        // use to check mid can find in partition
        int pieces = 1;     // partitions we make in array at starting to store elements

        for(int i: arr) {
            // if sum > mid means our desired target not fit in current partition
            // so create another partition and calculate sum in that new partition
            if(sum + i > mid) {
                // then we have to create new array and
                // then sum will be current elem 
                // as we see in example
                sum = i;
                pieces++;   // this will be our next partition
            }
            else
                sum += i;
        }

        if(pieces > m)
            low = mid + 1;
        // pieces <= m means greater partition is needed to store the target value 
        // ex: [1,2,3,4] m = 2 target=10 so here our partition is only 1 to store 10
        // so we have to reduce the target value(that is mid) 
        else
            high = mid;
    }
    
    // at end our low == mid == high so we can't further check for any possibilities 
    // so this is our answer (there will always be answer coz our mid not reduce by mid-1 it is reduced to mid & that mid 
    // we already checked thats why checking for left side that we are checking more minimum value)

    return low;     // at end low == high 
}


int main()
{
    // vector<int> arr = {7, 2, 5, 10, 8};      // ans should be 18
    vector<int> arr = {1, 2, 3, 4, 5};          // ans should be 9
    int m = 2;                                  // it is number of partition in which we have to split array

    cout << "from all possible maximum sum's minimum sum is: " << splitArray(arr, m) << endl;
}