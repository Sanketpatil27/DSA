#include <iostream>

using namespace std; // binary search needs array in sorted order

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
    cout << "Array elements after sort are: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << " " << a[i];
    }
}

// void prtarray(int a[],int n)
// {
// //  cout << "Array elements after sort are: " << endl;
// //     for (int i = 1; i <= n; i++)
// //     {
// //         cout << " " << a[i];
// //     }
// }

void binarysearch(int a[], int n, int key)
{
    int s = 1;
    int e = n; // s & e start & end of array
    int c = 0;

    //   for (int i = s; i <= e; i++)        // we have to start loop from s & rnd with e bcoz it is updating in else is conditions
    //   {
    while (s <= e)     //we have to change s =0 & i < e while using for loop
    {
        int mid = (s + e) / 2;
        if (a[mid] == key)
        {
            cout << "\nKey elment is found at position: " << mid + 1 << endl;
            c = 1;
            break;
        }
        else if (a[mid] < key)
        {
            s = mid + 1;
        }
        else // if (a[mid] > key) // if mid > key
        {
            e = mid - 1;
        }
    }
    // if (s == e)
    // {
    //     cout << "Key elment is found at position: ?" << endl;        // not working & not important in code
    //     c = 1;
    // }
    if (c == 0)
    {
        cout << "\nKey element not found!!!";
    }
}

int main()
{
    int n, key;

    cout << "\nHow many numbers you want in array: ";
    cin >> n;

    int a[n]; // if we take a[n] it will effect when array size increases3

    cout << "\nEnter array elements: " << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << "\nEnter key element: ";
    cin >> key;

    selectionsort(a, n);
    binarysearch(a, n, key);

    return 0;
}