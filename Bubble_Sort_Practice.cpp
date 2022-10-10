#include <iostream>

using namespace std;

void prtarray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << " " << a[i];
    }
}

void adaptivebubblesort(int a[], int n)
{
    int issorted = 0;

    for (int i = 0; i < n - 1; i++) // first loop for no. of passes
    {
        cout << "Working on pass " << i+1 << endl; // this shows first coz array displayed later
        issorted = 1;
        for (int j = 0; j < (n - 1 - i); j++) // second for no of comparisons in each pass which are decresing pass wise
        {
            if (a[j] > a[j + 1]) // we have to comparison till second last ele.(n-1-i) coz we have to calculate j+1 also
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                issorted = 0;
            }
        }
        if (issorted) // mean issorted = 1
        {
            return;
        }     
    }

}

// void bubblesort(int a[], int n)
// {
//     for (int i = 0; i < n - 1; i++) // first loop for no. of passes
//     {
//         for (int j = 0; j < (n - 1 - i); j++) // second for no of comparisons which are decresing pass wise
//         {
//             if (a[j] > a[j + 1]) // we have to comparison till second last ele.(n-1-i) coz we have to calculate j+1 also
//             {
//                 int temp = a[j];
//                 a[j] = a[j + 1];
//                 a[j + 1] = temp;
//             }
//         }
//     }
// }

int main()
{
    int n;
    cout << "\nhow many numbers you want in array: ";
    cin >> n;

    int a[n];

    cout << "Enter array elements: \n";

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "array elements are: \n";
    prtarray(a,n);
    cout << endl;
    
    // bubblesort(a, n);
    adaptivebubblesort(a,n);
    cout << "\nSorted Array:\n";
    prtarray(a,n);

    return 0;
}