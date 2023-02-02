#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

// time complexity is O(n^2), space: O(1)
int countDist(vector<int> v) {
    int res = 0;

    for(int i = 0; i < v.size(); i++) {
        bool flag = false;      // initially false means we don't find this elem on left side 
        
        for(int j = 0; j < i; j++) {
            if(v[i] == v[j]) {
                flag = true;        // means we find current elem on left side
                break;              // no need to check further, this is not distinct
            }
        }

        // if we not find this elem before(left side), then it is distinct
        if(flag == false) 
            res++;
    }

    return res;
}

int main() {
    vector<int> v = {23, 45, 23, 54, 45, 76, 87, 89};
    int n = 8;
    int arr[8] = {23, 45, 23, 54, 45, 76, 87, 89};

    // neive appraoch
    cout << countDist(v) << endl;    
    

    // time: O(1),   Auxilary space: O(n)
    unordered_set<int> s;

    for(auto i: v) 
        s.insert(i);
    
    cout << "Using set: " << s.size() << endl;  

    // we can also improve this using
    unordered_set<int> s1(v.begin(), v.end());          // direct insert vector into set
    // unordered_set<int> s1(arr, arr + n);     // can also use this

    cout << "Improved set: " << s1.size() << endl;

}