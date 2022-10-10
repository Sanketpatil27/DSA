#include<iostream>
#include<climits>       // to add INT_MIN
using namespace std;

int main()
{
    int n = 4;
    int a[n];
    int maxnum = INT_MIN;

    cout << "Enter Array Elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        maxnum = max(maxnum, a[i]);
    }
    cout << "Maximum number in the array is: " << maxnum << endl;    
}