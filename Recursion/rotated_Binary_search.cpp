#include<iostream>
#include<vector>
using namespace std;
 
int rotatedSearch(vector<int> arr, int target, int low, int high)
{
    // base case
    if(high < low)
        return -1;

    int mid = (low + high) / 2;

    if(arr[mid] == target)
        return mid;

    // we check for which half is sorted, and search in that part

    // if left side sorted then:
    if(arr[low] <= arr[mid])
    {
        // if target present in left half range, then we discard right half
        if(target >= arr[low] && target < arr[mid])
            return rotatedSearch(arr, target, low, mid-1);
        
        // if target not presented in sorted left half then check in right half, and discard left half
        else
            return rotatedSearch(arr, target, mid+1, high);
    }

    // if right side sorted then:
    else
    {
        // if target present in right half, then we discard left half
        if(target > arr[mid] && target <= arr[high])
            return rotatedSearch(arr, target, mid+1, high);
        
        // if target not presented in sorted right half then check in left half, and discard right half
        else
            return rotatedSearch(arr, target, low, mid-1);
    }
}

int main()
{
    vector<int> arr = {7, 8, 1, 2, 3, 4};
    int target = 2;
    int low = 0, high = 5;

    cout << "Index of target in Rotated array: " << rotatedSearch(arr, target, low, high);
}