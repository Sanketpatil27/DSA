// find kth missing positive number (numbers starts from 1)
// return kth positive integer that missing from array.
// example
// [2, 3, 4, 7, 11]
// output: 9        (as 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11)  from this 1,5,6,8,9 are missing number 5th is 9

#include<iostream>
#include<vector>

using namespace std;
 
// neive approach take time: O(n)   space: O(1)
int neive(vector<int> nums, int k) 
{
    for (int i = 0; i < nums.size(); i++)
    {
        if(nums[i] <= k) 
            k++;
        else
            break;
    }

    return k;
}


int findKthMissing(vector<int> nums, int k) 
{
    // our low is on the first ind & high on last ind
    int low = 0;
    int high = nums.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low)  / 2;
        // int mid = (high + low)  / 2;                 // same as up

        // now we have to find out count of *missing numbers* for each *position
        // mid + 1 is the ideal number that should be there at nums[mid] so minus it from actual no. of that position will give missing numbers
        int missing = nums[mid] - (mid + 1);

        // now we have to check that missing nums < k or not, to eliminate one half from array
        // if missing numbers at current position is less then we can eliminate left half else have to eliminate right half
        if(missing < k) 
            low = mid + 1;
        
        else
            high = mid - 1;
    }
    
    // our high will remain at previous point of the left then we can add how more missing elems we have to add to get kth missing number
    // this formula comes our from this: arr[high] + (k - missing);  here k - missing will give the count of remaining 
    // missing numbers that we have to find
    return (high + 1 + k);        // or low + k;          
}


int main()
{
    // vector<int> nums = {1, 2, 3, 7, 11};       // ans should be 9 for k = 5
    vector<int> nums = {1, 2, 3, 4};               // ans should be 6 for k = 2
    int k = 2;                                     // find kth missing number
    cout << "Neive: Kth missing number from the array is: " << neive(nums, k) << endl;

    cout << "Optimized: Kth missing number from the array is: " << findKthMissing(nums, k) << endl;
}