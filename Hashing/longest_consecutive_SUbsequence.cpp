// Q. find longest consecutive *subsequence means (x, x+1, x+2, x+3...)

#include<bits/stdc++.h>     // which header file require for sort() ?

using namespace std;

// using sorting
void neive(int arr[], int n) {
    sort(arr, arr+n);                   // takes time: O(logn)
    int curr = 1;
    int res = 1;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] == arr[i-1] + 1)
        {
            curr++;
        }
        else if (arr[i] != arr[i-1])    // else to avoid repeting element
        {
            res = max(res, curr);
            curr = 1;                   // reseat curr after checking res
        }
    }

    // for last possible subseqeunce checking 
    cout << "ans: " << max(res, curr) << endl;
    
}

// using unordered_set
void optimize(int arr[], int n) {
    unordered_set<int> s(arr, arr+n);       // order cann't predictable in set
    int res = 1;

    for (auto x: s)
    {
        // if its previous is not present! eg: 2 prev is 1 not present then it can be the first point of new starting
        // don't check for elems that previous is in set, it will be get from while loop when its base enters in loop
        // (ex: 3 not go in if when 1 ( its prev 0 not present) go then it count 3)
        if (s.find(x - 1) == s.end())        
        {                                                                                        
            int curr = 1;
            while (s.find(x+curr) != s.end())      // if next consecutive present then inc curr
                curr++;

            res = max(res, curr);
        }
    }
    
    cout << "ans: " << res << endl;
}

int main() {
    int n = 7;
    int arr[n] = {1, 4, 9, 3, 2, 8, 12};

    // time: O(nlogn) for sorting, space: O(1)
    neive(arr, n);

    // time: (theta) O(n), space: O(n)
    optimize(arr, n);
}