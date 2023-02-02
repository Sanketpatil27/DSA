// Q. find subarray with sum 0
// subarray is set of contigious elems 

#include<iostream>
#include<unordered_set>

using namespace std;

bool neive(int arr[], int n) {

    for (int i = 0; i < n; i++)
    {
        int curr = 0;
        // we consider every elem as starting sub-arr and check its sum to 0 or not
        for (int j = i; j < n; j++)
        {
            curr += arr[j];
            if(curr == 0)
                return true;

        }
    }
    
    return false;
}

bool optimize(int arr[], int n) {
    unordered_set<int> s;
    int preSum = 0;

    for (int i = 0; i < n; i++)
    {
        preSum += arr[i];

        if (s.find(preSum) != s.end())      // if not in set then insert it
        {
            // means already in set & again same value comes mean there should be subarray with sum 0
            return true;
        }
        
        // handling if prefix subarray is 0
        if(preSum == 0) 
            return true;

        s.insert(preSum);
    }
    
    return true;
}

int main() {
    int n = 5;
    int arr[n] = {23, 14, -13, -11, 11};

    // neive approach: O(n^2)   
    cout << neive(arr, n) << endl;

    // efficient approach   time: O(n)   space: O(n)
    // using prefix sum & hashing 
    cout << optimize(arr, n) << endl;
}