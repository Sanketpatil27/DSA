// Given an integer, we need to find floor of its square root.

#include <iostream>
using namespace std;

// neive appraoch:
int sqRoot(int x)
{
    int i = 1;
    while(i*i <= x)
        i++;
    
    // after loop we are at number which is greater than x so i-1 is floor of square root of x
    return i-1;
}


// we use binary search from 1 to x as low & high
int sqRoot2(int x) {
    int l = 1, h = x;
    int mid, midSqr;
    int ans = -1;

    while(l <= h) {
        mid = (l+h) / 2;
        midSqr = mid*mid;           // check for mid as square root

        if (midSqr == x)
            return mid;

        if(midSqr > x)    
            h = mid-1;

        // this mid can not be the closest floor so we store it as possible ans, if we find another close mid then again change
        // means if(midSqr < x)
        else
            l = mid + 1;
            ans = mid;              
    }

    return ans;
}

int main()
{
    int x = 81;

    // time: theta(squareRoot of x)
    cout << "Neive approach: " << sqRoot(x) << endl;

    // time: O(logx)
    cout << "Efficient appraoch: " << sqRoot2(x) << endl;
}