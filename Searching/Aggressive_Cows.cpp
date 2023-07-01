// You are given an array consisting of n integers which denote the position of a stall. You are also given an integer k which denotes the number of aggressive cows. You are given the task of assigning stalls to k cows such that the minimum distance between any two of them is the maximum possible.
// The first line of input contains two space-separated integers n and k.
// The second line contains n space-separated integers denoting the position of the stalls.
// input:
// n=5 k=3 stalls = [1 2 4 8 9]
// Output:3
// Explanation:
// The first cow can be placed at stalls[0], the second cow can be placed at stalls[2] and the third cow can be placed at stalls[3]. The minimum distance between cows, in this case, is 3, which also is the largest among all possible ways.

#include<iostream>
#include<vector>
#include<algorithm>     // for sort function

using namespace std;

int canWePlaceCows(vector<int> stalls, int cows, int minDist) {
    int lastCow = stalls[0];
    int cntCows = 1;        // as we placed 1 cow on stall 1
    
    for(int i = 1; i < stalls.size(); i++) {
        
        // we have to maintain min distance of minDist
        if(stalls[i] - lastCow  >= minDist) {
            cntCows++;
            // place current cow on this valid stall 
            lastCow = stalls[i];   
        } 
        
        if(cntCows >= cows) 
            return true;
    }

    return false;
}


int brute(int n, int k, vector<int> &stalls) {

    // sort stalls so we can get contigious correct distance between two stalls
    sort(stalls.begin(), stalls.end());

    int mxdiff = stalls[n-1] - stalls[0];                         

    for (int i = 1; i <= mxdiff; i++)
    {
        if(canWePlaceCows(stalls, k, i)) 
            continue;
        
        else
            return i-1;         // previous executed is our answer
    }
    

    return -1;
}


int solve(int n, int k, vector<int> &stalls) {

    // sort stalls so we can get contigious correct distance between two stalls
    sort(stalls.begin(), stalls.end());
    
    int low = 1;
    
    // high can mix diff - min dist, coz we don't get more than this distance
    int high = stalls[n-1] - stalls[0];                         
    int ans = -1;
    
    while(low <= high) {
        int mid = (low + high) / 2;
        
        // see if we can place k cows with target(mid) min distance
        
        if(canWePlaceCows(stalls, k, mid)) {
            // this can be answer, try for more minimum distance which is max
            ans = mid;
            low = mid + 1;
        }
        
        else 
            high = mid - 1;
    }

    return high;               
    // high first placed at last place and will end with the index of the possible 
    // minimum maximum answer
}


int main()
{
    int n = 5, k = 3;
    vector<int> stalls = {1, 2, 4, 8, 9};
    // vector<int> stalls = {10, 1, 2, 7, 5};

    // brute force: time: O(mxdiff - mindiff) * O(n))   space: (1)

    cout << "min distance which is maximum: " << brute(n, k, stalls) << endl;
    
    // optimized: time: O(n* log(max-min))      max distance - min distance
    cout << "min distance which is maximum: " << solve(n, k, stalls) << endl;
}