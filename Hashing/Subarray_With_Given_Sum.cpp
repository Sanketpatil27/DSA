// Q. find subarray with given sum 
// subarray is set of contigious elems 

#include<iostream>
#include<unordered_set>

using namespace std;


// neive approach can be O(n^2), traversing from i to n and checking sum
// optimized approach: using prefix sum + hashing like subarray with 0 sum: 
// time: O(n), space: O(n)
int main() {
    int n = 4;
    int arr[n] = {4, 3, 2, 6};
    int sum = 9;

    unordered_set<int> s;
    int prefSum = 0;        

    for(int i = 0; i < n; i++) {
        prefSum += arr[i];

        // to handle courner case, subarray begin with index 0 as answer we cannot found them without this 
        // condition, coz we do not have any previous point, so we can't find them ({4, 3, 2, 6})
        if(prefSum == sum) {
            cout << "we found it!" << endl;
            return 0;
        }
        
        if (s.find(prefSum - sum) != s.end())  
        {   // if it present already in set
            cout << "we found the subarray!" << endl;
            return 0;
        }

        s.insert(prefSum);
    }

    cout << "we cannot find it :(" << endl;
}