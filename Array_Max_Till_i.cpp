// print the maximum number in array till ith index

#include <iostream>
#include <climits> // to add INT_MIN
using namespace std;

int main()
{
    int n = 4;
    int a[n];
    int maxnum = INT_MIN;

    cout << "Enter Array Elements: ";
    for (int k = 0; k < n; k++)
    {
        cin >> a[k];
    }


    for (int i = 0; i < n; i++)
    {
        maxnum = max(maxnum, a[i]);
        cout << maxnum << endl;
    }

    cout << "Maximum number in the array is: " << maxnum << endl;
}