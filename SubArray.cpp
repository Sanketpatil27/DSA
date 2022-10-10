// formula of maximum subarrays in an array of nth elements: n*(n+1)/2.

#include <iostream>
#include <climits>       // to use INT_MIN
using namespace std;

int main()
{
    int n = 4;
    int a[n];
    int maxsum = INT_MIN;

    cout << "Maximum SubArrays: " << n*(n+1)/2  << endl;

    cout << "Enter an Array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << "SubArray: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)   // it defines the start of the subarray 
            {
                cout << a[k] << " ";     // printing the subarray
                sum += a[k];
            }
            cout << endl;
            maxsum = max(maxsum, sum);          // better way in kadane's algo.
        }
    }
    cout << "Maximum sum of an subArray: " << maxsum << endl;

    return 0;
}