#include <iostream>

using namespace std;

void selectionsort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++) // second arary for comparison with next element of array a[0] > i + 1(2) // arr = 1 2 3 5
        {
            if (a[i] > a[j]) // 1 34 7 3
            {                // if 1(a[i]) > 34 (a[j])
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

void array(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << " " << a[i];
    }
}

int main()
{
    int n;

    cout << "How many elements you wants in array: ";
    cin >> n;

    int arr[n];

    cout << "\nEnter array elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    selectionsort(arr, n);
    cout << "Array After Sort: \n";
    array(arr, n);

    return 0;
}