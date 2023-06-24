// this is order-Agnostic binary search 
// we use this when we know array is sorted but don't in ascending or descending order!
// this is used so we can understand in which half our target lies between

#include<iostream>
using namespace std;
 
int orderAgnostic(int arr[], int n, int target) {
    int low = 0, high = n-1;

    // we can find wheather an array is in ascending or descending using 
    bool isAsc = arr[low] < arr[high];      

    // now we apply normal binary search
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if(arr[mid] == target)
            return mid;

        // this code for if array is in ascendign order
        if (isAsc)
        {
            if(arr[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        // this code for if array is in descending order
        else
        {
            if(arr[mid] > target)
                low = mid + 1;
            else
                high = mid - 1;
        }   
    }
        
    return -1;    
}

int main()
{
    int n = 7;
    // int arr[8] = {90, 75, 18, 12, 6, 4, 3, 2};
    int arr[8] = {1, 2, 3, 4, 5, 6, 7};
    int target = 6;

    cout << "Target is at index: " << orderAgnostic(arr, n, target);
}