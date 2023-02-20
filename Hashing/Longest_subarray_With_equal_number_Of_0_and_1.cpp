// Q. find longest subarray with equal num of 0's and 1's 
// subarray is set of contigious elems 

#include<iostream>
#include<unordered_map>

using namespace std;


void neive(int arr[], int n) {

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int count0 = 0;         // count no. of 0's & 1's for each subarray
        int count1 = 0;

        for (int j = i; j < n; j++)
        {
            if (arr[j] == 1)    
                count1++;
            else
                count0++;

            if(count0 == count1)
                res = max(res, j-i+1);
            
        }
    }
    
    cout << "Longest subarray is: " << res << endl;
}


void optimize(int arr[], int n) {
    // first we have to replace all 0's with -1, to make easy our task 
    // we can use prefix sum and if it becomes 0 means there should be subarray with equals( [1, -1] == 0)

    // replace 0's with -1
    // instead of this loop we can use ternary operator to add -1 to prefix sum when there is 0
    for (int i = 0; i < n; i++)
        if (arr[i] == 0)
            arr[i] = -1;

    // {1, 0, 1, 1, 1, 0, 0}
    // {1, -1, 1, 1, 1, -1, -1};


    // similar to longest subarray with given sum(here use 0 as *sum)
    unordered_map<int, int> mp;
    int prefSum = 0;                 // {1, 0, 1, 2, 3, 2, 1};
    // we haven't store 1 on ind 2 coz it already appear on 0th ind, don't store it again in map, 
    // previous one make longest subarray!
    int res = 0;                      
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        prefSum += arr[i];

        if (prefSum == sum)
            res = i+1;

        // put in map if not already present
        if (mp.find(prefSum) == mp.end())
            mp[prefSum] = i;

        // if already present then compare res
        if (mp.find(prefSum - sum) != mp.end())
            res = max(res, i - mp[prefSum]);        
    }

    cout << "Longest length of equals: " << res << endl;    
}


int main() {
    int n = 7;
    int arr[n] = {1, 0, 1, 1, 1, 0, 0};       
    // int arr[n] = {0, 1, 0, 1};       


    // time: O(n^2), space: O(1)
    neive(arr, n);

    // time: O(n), space: O(n)
    optimize(arr, n);
}