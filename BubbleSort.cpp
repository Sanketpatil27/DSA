#include <iostream> //   i   i+1          n
                    // a= 56   2    89     3
using namespace std;

void BubbleSort(int a[], int n)
{
    // int count = 1;
    // while ((count < n))
    // {
    //     for (int i = 0; i < n - count; i++)    // count for comparsons in each pass decreases
    //     {
    //         if (a[i] > a[i + 1])
    //         {
    //             int temp = a[i];
    //             a[i] = a[i + 1];
    //             a[i + 1] = temp;
    //         }
    //     }
    //     count++;
    // }

    for (int i = 0; i < n - 1; i++) // for number of passes
    {
        for (int j = 0; j < n - 1 - i; j++) // for number of comparisons
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n;

    cout << "Enter size of array: ";
    cin >> n;

    int a[n];

    cout << "Enter Array Elements: \n";

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    BubbleSort(a, n);
    cout << "Sorted Array: \n";
    for (int i = 0; i < n; i++)
    {
        cout << " " << a[i];
    }

    return 0;
}