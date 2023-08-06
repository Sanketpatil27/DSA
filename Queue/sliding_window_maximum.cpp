#include<iostream>
#include<queue>
#include<vector>
#include<climits>
using namespace std;
 

// this returns the max from the current k size window
int getMax(queue<int> q)
{
    int mx = INT_MIN;
    while(!q.empty())
    {
        mx = max(mx, q.front());
        q.pop();
    }

    return mx;
}

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> maxi;
    queue<int> q;
    int mx = INT_MIN;

    // first we calculate first k size array
    for(int i = 0; i < k; i++)
    {
        q.push(nums[i]);
        mx = max(nums[i], mx);
    }

    // store first k size array max elem
    maxi.push_back(mx);

    // pop the front elem which is out of k window size for next window size
    // q.pop();       

    for(int i = k; i < nums.size(); i++)
    {
        // if popped item from current window is max then get new max
        if(q.front() == mx)
        {
            q.pop();
            q.push(nums[i]);
            mx = getMax(q);     // get new max from new k window size
        }

        // else normally pop out of window elem, get max from curr max and new pushed item
        else 
        {
            // pop the out of window element
            q.pop();  

            // we first push new elem for completing current k size window
            q.push(nums[i]);

            // take max from current size
            mx = max(mx, nums[i]);
        }

        // store the mx of current k window size
        maxi.push_back(mx);
    }

    return maxi;
}
 
int main()
{
    // You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. 
    // You can only see the k numbers in the window. Each time the sliding window moves right by one position.
    // Return the max sliding window.

    // Example 1:
    // Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
    // Output: [3,3,5,5,6,7]
    // Explanation: 
    // Window position                Max
    // ---------------               -----
    // [1  3  -1] -3  5  3  6  7       3
    //  1 [3  -1  -3] 5  3  6  7       3
    //  1  3 [-1  -3  5] 3  6  7       5
    //  1  3  -1 [-3  5  3] 6  7       5
    //  1  3  -1  -3 [5  3  6] 7       6
    //  1  3  -1  -3  5 [3  6  7]      7
    
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;

    // getting TLE for this function in LEEtCode
    vector<int> ans = maxSlidingWindow(nums, k);
    cout << "Maximum of each window: ";
    for(int i: ans) 
        cout << i << " ";
}