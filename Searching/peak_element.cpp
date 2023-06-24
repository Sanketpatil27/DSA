// return any 1 peak element

#include<iostream>
using namespace std;
 
int solve(int arr[], int n) {
    if(n == 1 || arr[0] >= arr[1])  
        return arr[0];

    if(arr[n-1] >= arr[n-2])
        return arr[n-1];


    for (int i = 1; i < n-1; i++)
        if(arr[i] >= arr[i-1] && arr[i] >= arr[i+1])
            return arr[i];

    return -1;
}


int main()
{
    int n = 6;
    int arr[n] = {1, 2, 4, 3, 5, 9};

    // neive approach: time: O(n)   in worst-case
    cout << "Any one peak element is: " << solve(arr, n) << endl;
    
    // efficient approach: time: O(logn) 
    cout << "Any one peak element is: " << solve(arr, n) << endl;
}