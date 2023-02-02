#include<iostream>
#include<unordered_set>

using namespace std;

// Q. we have to find *pairs* which can match sum
// time: O(n) space: O(n)


int main() {
    int n = 5;
    int arr[n] = {3, 2, 8, 15, -8};
    int sum = 181;

    unordered_set<int> s;

    for (int i = 0; i < n; i++)
    {
        // we check from our previous set of elems that can we find remaining  amount 
        // when we substract current elem from sum, yes then true
        if(s.find(sum - arr[i]) != s.end()) {
            cout << "we find the pair" << endl;
            return 0;
        }
        // if we cannot find remaining amount then insert for upcoming elems
        s.insert(arr[i]);
    }

    cout << "we didn't find such pair";
    return 0;
}