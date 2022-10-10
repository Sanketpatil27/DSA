#include <iostream>
using namespace std;

int main()
{
    int n = 4;
    int a[n];
    int sum = 0;

    cout << "Enter an Array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << "SubArraySum: " << endl;
    for (int i = 0; i < n; i++)
    {
         sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += a[j];
            cout << sum << endl;
        }
    }

    return 0;
}