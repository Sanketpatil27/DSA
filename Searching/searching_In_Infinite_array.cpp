// we can't use direct binary search here coz it requires low & and high
// so here is no high consider it is as infinite array
// approach:  
// the idea is to *double the indexes and search between them
// we begin with index 1 then go to 2 then 4, 8, 16..... (not from 0 coz 0*0 = 0)
// keep doing it while current elem is smaller than x, then if curr elem == x return i
// if elem != x then apply binary search from (i/2 + 1) to (i - 1)
// ** time complexity: O(log position + log Position (for search)) ==  O(log of position)

#include<iostream>
using namespace std;

int binarySearch(int arr[], int l, int h, int x) 
{
    int mid;

    while (l <= h)
    {
        mid = (l + h) / 2;

        if (arr[mid] == x)
            return mid;
        
        if(arr[mid] < x)
            l = mid + 1;
        
        else 
            h = mid - 1;
    }
    
    return -1;
}


int solve(int arr[], int x) {

    // handle 0 index explicitly
    if(arr[0] == x) 
        return 0;
    
    int i = 1;
    while (arr[i] < x) 
        i = i * 2;          // if elem is less than x then double the indexed

    
    if(arr[i] == x)         // after failing loop we check current position 
        return i;

    // else we use binary search from (i/2 + 1) (which is last we check and doubled i) to i - 1
    int l = (i/2) + 1;
    int h = i - 1;          // we also checked ith index so high is previous of it

    return binarySearch(arr, l, h, x);
}

int main()
{
    // consider array as infinite length 300,........
    int arr[] = {1, 10, 14, 15, 16, 20, 69, 100, 200, 300};     
    int x = 10;            

    cout << "index of 100 is: " << solve(arr, x);  
}