// Q. find longest common span with same sum in two binary arrays 

#include<iostream>  
#include<unordered_map>  

using namespace std;


void neive(int arr1[], int arr2[], int n) {

    int res = 0;

    for (int i = 0; i < n; i++)
    {
        int sum1 = 0, sum2 = 0;     // to calculate both array sum
        for (int j = i; j < n; j++)
        {
            sum1 += arr1[j];
            sum2 += arr2[j];

            if (sum1 == sum2)
            {
                res = max(res, j-i+1);
            }
        }
    }

    cout << "longest common span: " << res << endl;
    
}

void optimize(int arr1[], int arr2[], int n) {
    // create extra array to store  *substraction of both arrays, time: O(n) + space: O(n) for tmp 
    int tmp[n];
    for (int i = 0; i < n; i++)
    {
        tmp[i] = arr1[i] - arr2[i];
    }
    // tmp = {-1, 1, 0, 0, 0, 1}
    // *** now our problem becomes find --longest subarray with 0 sum--  (refer this)***
    
    unordered_map<int, int> mp;
    int sum = 0;        // for comparing result
    int res = 0;
    int prefSum = 0;

    for (int i = 0; i < n; i++)
    {
        prefSum += tmp[i];

        // corner case
        if (prefSum == sum) 
            res = i+1;
        
        // add if not in map
        if (mp.find(prefSum) == mp.end())
            mp[prefSum] = i;
        
        // if already present
        // we will not change the prefSum index, which stored in map aleready, coz we want max length
        // so dont ugrade it to new index
        if(mp.find(prefSum - sum) != mp.end())
            res = max(res, i - mp[prefSum - sum]);      // to get length
    }

    cout << "longest common span: " << res << endl;   
}

int main() {
    int n = 6;
    int arr1[n] = {0, 1, 1, 0, 0, 0};
    int arr2[n] = {1, 0, 1, 0, 0, 1};

    // time: O(n^2),  space: O(1)
    neive(arr1, arr2, n);

    // time: O(n) for tmp elem storing + O(n) for finding length == O(n)
    // space: O(n) for tmp array + O(n) for hashing == O(n)
    optimize(arr1, arr2, n);
}