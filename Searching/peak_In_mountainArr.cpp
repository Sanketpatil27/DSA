// mountain array properties:
// mountian array is a array where one side is *decreasing from *peak or another side is *increasing till *peak 
// so there will always one peak element. array length must >= 3

// ex: [0, 1, 0]        
//          1       (peak in mountain)
//        /  \
//      0      0

// ex: [0, 2, 1, 0]        
//          2       (peak in mountain)
//        /  \
//      0      1
//              \
//               0


#include<iostream>
using namespace std;
 
int neive(int arr[], int n) {
    if(n == 1 || arr[0] >= arr[1])  
        return arr[0];

    if(arr[n-1] >= arr[n-2])
        return arr[n-1];


    for (int i = 1; i < n-1; i++)
        if(arr[i] >= arr[i-1] && arr[i] >= arr[i+1])
            return arr[i];

    return -1;
}

int peakInMountain(int arr[], int n)
{
    int low = 0, high = n - 1;
    int mid;

    // we don't take here low <= high coz we have to return when they both are on same index
    while (low < high)
    {
        mid = (low + high) / 2;

        // means we are in decreasing part so mid can be the ans coz it > mid+1 but we have to look at left half
        // no point to go in decreasing part in right side
        if(arr[mid] > arr[mid+1]) 
            high = mid;         // not mid-1 coz mid can be ans

        // means mid elem is < mid+1,  means we are going in increasing part so go to right side
        else
            low = mid + 1;
    }
    
    // here both low & high will pointing to same elem that is peak elem return any of them
    return arr[low];
}

int main()
{
    int n = 8;  // -increasing- | -decreasing-
    int arr[n] = {1, 2, 3, 5, 6, 4, 3, 2};

    // neive approach: time: O(n)   in worst-case
    cout << "peak element is: " << neive(arr, n) << endl;
    
    // efficient approach: time: O(logn) 
    cout << "peak element is: " << peakInMountain(arr, n) << endl;
}