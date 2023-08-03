#include<iostream>
#include<vector>
#include<stack>
using namespace std;
 
// 
//              ___
//             |  |
//          ___|  | 
//         |  |   |
//       __|  |   |
//      |  |  |   |
//       1  3   5           ans: 6: as 3+3 area

int neive(vector<int>& arr)
{
    // we find min height for 'i' which is greater or equal to ith height on both left & right side 
    // & add the ith height that number of times
    // ex: [2,6,4, 1]  for i = 0th index, so for 2 there is no left so find on right side there are 6, 4 are greater area
    // so we add 2, 3 times (0th, 1st, 2nd index)
    // for i = 2 (4 height) on left side only 6 is greater height, on right side no greate or equal, so for 4 we add
    // 4+4  [1,2 index]     so total largest area in this histogram is "8"

    int n = arr.size();
    int maxArea = 0;

    for (int i = 0; i < n; i++)
    {
        int currArea = arr[i];
        // for calculating max height's on left side
        for(int j = i-1; j >= 0; j--) {
            if(arr[j] < arr[i])
                break;
            currArea += arr[i];
        }

        // for calculating max hieght's on right side
        for(int j = i+1; j < n; j++) {
            if(arr[j] < arr[i])
                break;
            currArea += arr[i];
        }

        maxArea = max(maxArea, currArea);
    }
    
    return maxArea;
}


vector<int> getNextSmaller(vector<int>& heights, int n) {
    // start traversing from right side, for more clear check next greater element problem
    vector<int> ans(n);
    stack<int> s;
    s.push(-1);                // store last element index

    for(int i = n-1; i >= 0; i--) {
        while(s.top() != -1 && heights[s.top()] >= heights[i])
            s.pop();

        // ans is top of stack
        ans[i] = s.top();
        s.push(i);
    }

    return ans;
}

vector<int> getPrevSmaller(vector<int>& heights, int n) {
    // check prev smaller problem for more clarification

    vector<int> ans(n);
    stack<int> s;
    s.push(-1);                 // store last element

    for(int i = 0; i < n; i++) {
        while(s.top() != -1 && heights[s.top()] >= heights[i])
            s.pop();

        // ans is top of stack
        ans[i] = s.top();
        s.push(i);
    }

    return ans;
}

int largestRectangleArea(vector<int>& heights) {
    // we calculate next smaller height bar & previous smaller height bar for every ith elem
    // time: O(n) space: O(n)
    
    int n = heights.size();

    vector<int> next = getNextSmaller(heights, n);
    vector<int> prev = getPrevSmaller(heights, n);
    int maxArea = 0;

    // area of rectangle is area = length * width
    // we calculate length & width here

    for(int i = 0; i < n; i++) {
        int l = heights[i];

        if(next[i] == -1)
            next[i] = n;        // store value which is beyong index if there is no greater

        // this is the formula to get the width from prevsmaller to nextSmaller bars
        int w = next[i] - prev[i] - 1;

        int newArea = l * w;
        maxArea = max(maxArea, newArea);
    }

    return maxArea;
}

int main()
{
    // height's of histogram
    vector<int> arr = {6, 2, 5, 4, 4, 8, 6};

    // neive solution: time: O(n^2) space: O(1)
    cout << "largest area: " << neive(arr);
    
    // better solution: time: O(n) space: O(n)
    cout << "\nlargest area: " << largestRectangleArea(arr);

    // there is efficient solution for this using stack only one traversal and 1 auxilary stack required
    // i'haven't learnt that till now
}