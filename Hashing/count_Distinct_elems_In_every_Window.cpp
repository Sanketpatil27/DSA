#include<iostream>
#include<unordered_map>

using namespace std;

void neive(int arr[], int n, int k) {
    for (int i = 0; i <= n-k; i++)
    {
        int cnt = 0;

        // traverse every elemnent of current window
        for (int j = 0; j < k; j++)
        {
            bool flag = false;
            // to check whether this elem is seem before or not
            for(int b = 0; b < j; b++)
                if (arr[i+b] == arr[i+j]) {
                    flag = true;       
                    break;
                }

            // if it still not seen then increment count
            if (flag == false)
                cnt++;
        }

        cout << cnt << " ";
    }    
    cout << endl;
}

void optimize(int arr[], int n, int k) {
    unordered_map<int, int> mp;

    // first store first k elems in map
    for (int i = 0; i < k; i++)
        mp[arr[i]]++;
    
    cout << mp.size() << " ";           // print size as distinct element

    for (int i = k; i < n; i++)
    {
        // add new element of new window in map, if present increase frequency
        mp[arr[i]]++;

        // decrement old element of outside new window in map, remove also if frequency is 0
        // frequency 0 indicates element is completely removed from new window
        mp[arr[i-k]]--;
        if(mp[arr[i-k]] == 0)
            mp.erase(arr[i-k]);

        cout << mp.size() << " ";
    }
    cout << endl;
}

int main() {
    int n = 7;
    int arr[n] = {10, 20, 20, 10, 30, 40, 10};
    int k = 4;      // window size;

    // time: O((n-k)*k*k)   space: O(1)
    neive(arr, n, k);

    // time: O(n)    space: O(n)
    optimize(arr, n, k);
}