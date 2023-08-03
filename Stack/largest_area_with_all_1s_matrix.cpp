#include<iostream>
using namespace std;
 
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

int largestRectangleArea(vector<int>& heights, int n) {
    // we calculate next smaller height bar & previous smaller height bar for every ith elem
    // time: O(n) space: O(n)
    
    // here n is actually no. of cols

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
    // from love babbar:
    // we make this problem as largest area in histogram problem, calculate height for each bar adding upper rows

    // Binary Matrix
    int n = 4;      // rows
    int m = 4;      // cols
    vector<vector<int>> arr = { 
                                {0, 1, 1, 0},
                                {1, 1, 1, 1},
                                {1, 1, 1, 1},
                                {1, 1, 0, 0},
                              };                 // op: 8

    int area = largestRectangleArea(arr[0], m);

    // start adding further rows
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // row update by adding previous row's values
            // only add when current base is not '0'
            if(arr[i][j] != 0)
                arr[i][j] = arr[i][j] + arr[i-1][j];
            else    
                arr[i][j] = 0;      // make it as it is, 0
        }

        // entire row is updated now
        int newArea = largestRectangleArea(arr[i], m);
        area = max(area, newArea);
    }

    cout << "Max area: " << area;    
}