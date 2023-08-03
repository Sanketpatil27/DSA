#include<bits/stdc++.h>
using namespace std;

// for n size there are always 2^n subsequences
// time complexity: O(2^n+n)    for every number there are couple of options of take it or not take it. 
// space complexity: O(n);     using n size current array

void printSequences(vector<int> nums, vector<int> &curr, int index, int n) {
    // base condition for when index reach the end of the vector length
    if(index == n) {
        // we print all subsequences till now from current array, if our index reach end.
        for (auto i : curr) {
            cout << i << " ";
        }   

        if (curr.size() == 0)   // to ensure the white space which is empty subsequence
            cout << "{}";

        cout << endl;

        return;
    }

    // we first call for include current element 
    curr.push_back(nums[index]);    // this will include current element of nums array
    printSequences(nums, curr, index+1, n);

    // now we call for exclude current element, means current elem will not included in further subsequence
    curr.pop_back();            // this will exclude current element from the array
    printSequences(nums, curr, index+1, n);
}

int main() {
    int n = 3;      // size of vector nums
    vector<int> nums{3, 1, 2};
    vector<int> curr;
    int index = 0;      // index to point the vector length

    printSequences(nums, curr, index, n);

    // cout << curr.size();
    return 0;
}