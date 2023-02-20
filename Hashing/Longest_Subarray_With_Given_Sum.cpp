// Q. find longest subarray with given sum 
// subarray is set of contigious elems 

#include<iostream>
#include<unordered_map>

using namespace std;

int neive(int arr[], int n, int sum) {
    int res = 0;        // stores length of longest subarray

    for (int i = 0; i < n; i++)
    {
        int curr = 0;
        for (int j = i; j < n; j++)
        {
            curr += arr[j];
            if (curr == sum)
            {
                res = max(res, j-i+1);      
            }
        }
    }
    
    return res;
}


int optimize(int arr[], int n, int sum) {
    unordered_map<int, int> mp;
    int prefSum = 0;
    int res = 0;

    for (int i = 0; i < n; i++)
    {
        prefSum += arr[i];
        if (prefSum == sum)     // handle corner case, if subarray starts with ind 0
            res = i + 1;

        // if prefSum not present in map
        if (mp.find(prefSum) == mp.end())
            mp[prefSum] = i;

        // if already present
        // we will not change the prefSum ind which stored in map aleready, coz we want max length
        // so dont ugrade it to new index
        if (mp.find(prefSum - sum) != mp.end())
            res = max(res, i - mp[prefSum - sum]);
    }
          
    return res;
}

int main() {
    int n = 8;
    int arr[n] = {8, 3, 1, 5, 6, -6, 2, 2};   
    // prefSum = {8, 11, 12, 17, 23, 17, 19, 21};   for optimize approach looks like
    int sum = 0;

    // time: O(n^2)     space: O(1)
    cout << "Longest Subarray Length: " << neive(arr, n, sum) << endl;

    // time: O(n)        space: O(n)
    // using prefix sum + hashing technique
    cout << "Longest Subarray Length: " << optimize(arr, n, sum) << endl;
}