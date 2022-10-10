// Question from ||google's kick start||        // from apna college array practice Qs cpp course

// Problem:
// Isyana is given the number of visitors at her local theme park on N consecutive days.
// The number of visitors on the i-th day is V. A day is record breaking if it satisfies both of the following conditions:
// 1.The number of visitors on the day is strictly larger than the number of visitors on each of the previous days.
// 2.Either it is the last day, or the number of visitors on the day is strictly larger than the number of visitors on the following day(only next day).
// Note that the very first day could be a record breaking day!
// Please help Isyana find out the number of record breaking days.

// (simple- we have to check that the current day visitors is more than the previous visitors of each day 
// and also current day visitors is more than the next day visitors then it is called the record breaker day)

#include "bits/stdc++.h" // it includes all the header files, for time saving
using namespace std;

int main()
{
    int n = 7;
    int a[n+1];    // to compare with last element, one is extra. total arr size = 8
    // this is at the last index(that is as a[n+1] upside code),coz nth index is there, used this 
    // to compare with the last a[n-1]th index to it's next index which is no available so, -1 that will always true for array
    a[n] = -1;        // this is on nth index which is not being used (a[7]) which complete 8 size array
    int mx = -1;   // there should be non negative nums in array
    int breaker = 0; // it will store the number of record breaking days

    cout << "Enter the 7 day's visitors: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (a[i] > mx && a[i] > a[i + 1])
        {
            breaker++;      // increase the record breaking days
        }
        mx = max(mx, a[i]); // it will store the max numbers till ith elem
    }

    cout << "The number of record breaking days are: " << breaker << endl;

    return 0;
}