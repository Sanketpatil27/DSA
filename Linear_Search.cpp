#include <iostream>
using namespace std;

void linearsearch(int arr[], int n, int key)
{
    int c = 0;
    for (int i = 1; i <= n; i++)
    {
        if (arr[i] == key)
        {
            cout << "key element is present at position: " << i << endl;
            c = 1;
            break;
        }
    }
    if (c == 0)
    {
        cout << "\nkey element is not present";
    }
}

int main()
{
    int n, key;

    cout << "How many numbers you want in array: ";
    cin >> n;

   int a[n];
   
    cout << "Enter array elements: " << endl;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    cout << "Array elements are: " << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << " " << a[i];
    }

    cout << "\nENTER KEY ELEMENT: ";
    cin >> key;

    linearsearch(a, n, key);
    return 0;
}