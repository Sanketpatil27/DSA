// find elems which occurence is *more than n/k 

#include<bits/stdc++.h>

using namespace std;

void neive(int arr[], int n, int k) {
    int i = 1;
    int cnt = 1;        // starts from 1st index so we already counted 0th elem

    sort(arr, arr+n);       // takes O(nlogn) time
    while (i < n)
    {
        // if current elem == previous elem means it's inc occurence
        while(i < n && arr[i] == arr[i-1]) {
            cnt++;
            i++;            // move to next elemenet
        }

        // if current elem becomes different than previous, check previous elem's occurence
        if(cnt > n/k){
            cout << arr[i-1] << " occurence: " << cnt << endl;
        }

        cnt = 1;            // update for current elem which is different
        i++;                // go to next elem 
    }
}


void optimize(int arr[], int n, int k) {
    // we store all elems in map with it's frequency
    unordered_map<int, int> mp;

    for(int i = 0; i < n; i++) 
        mp[arr[i]]++;

    // then we traverse through array elem and check it's frequency more than required
    for(auto i: mp) {
        if(i.second > n/k) 
            cout << i.first << " occurence: " << i.second << endl;
    }
}

int main() {
    int n = 7;
    int arr[n] = {10, 10, 20, 30, 20, 10, 10};
    int k = 2;

    // time: O(nlogn)   space: O(1)
    neive(arr, n, k);

    // time: theta O(n) with hash function allows to search & insert in O(1) time 
    // space: O(n/k) (multiple occurences of same elem)
    optimize(arr, n, k);
}