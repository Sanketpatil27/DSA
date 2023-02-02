#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;


// we have to count distinct elems that are intersecting (same)


// time complexity: O(m * (m + n))        where m is size of first and n is size of second array

int distCount(vector<int> arr1, vector<int> arr2) {
    int res = 0;

    for(int i = 0; i < arr1.size(); i++) {
        
        // first we find if it not come before it(left side), if not then only check, else continue
        int flag = false;
        for(int j = 0; j < i; j++) {
            if(arr1[i] == arr1[j]) {
                flag = true;
                break;
            }
        }

        if(flag == true) { continue; }

        //  completed checking  for repetitiion

        // now we check second array have this elem or not
        for(int j = 0; j < arr2.size(); j++) {
            if(arr1[i] == arr2[j])  {
                res++;
                break;      // after finding same elem break loop
            }
        }
    }

    return res;
}



// time is O(m + n),    space: O(m)     for storing first array elems
int optimized(vector<int> arr1, vector<int> arr2) {
    int res = 0;

    // storing first array elements in set  takes O(m) time in loop & O(m) space
    unordered_set<int> s(arr1.begin(), arr1.end());

    // now traverse second array and find it in set
    for (int j = 0; j < arr2.size(); j++)
    {
        if(s.find(arr2[j]) != s.end()) {    
            res++;                          // if find that elem then:
            s.erase(arr2[j]);               // erase from set coz this can come again in arr2 then it will find again so don't want it
        }                                   // erase and find take constant time O(1)
    }
    
    return res;
}

int main() {
    vector<int> arr1 = {10, 15, 20, 15, 30, 80, 5};
    vector<int> arr2 = {30, 5, 30, 80};
    
    // neive approach
    cout << "distinct intersection: " << distCount(arr1, arr2) << endl;

    cout << "distinct intersection: " << optimized(arr1, arr2) << endl;

    return 0;
}