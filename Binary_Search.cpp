#include <iostream>
using namespace std;    // *binary search needs array in sorted order*

void binarysearch(int a[], int n, int key)
{
    int s = 1;      // initially start, start from 1
    int e = n;      // s & e start & end of array
    int c = 0;      // if key elem is found then c will set as 1(true)

    // for (int i = s; i <= e; i++)        // we have to start loop from s & end with e bcoz it is updating in else if conditions
    // {
    while (s <= e)
    {
        int mid = (s + e) / 2;             // calculate the mid index
        if (a[mid] == key)
        {
            cout << "Key elment is found at position: " << mid << endl;
            c = 1;      
            break;
        }
        else if (a[mid] < key)      // if key value is greater than mid element
        {
            s = mid + 1;        // we reseat the start coz elems till mid are alerady checked 
        }
        else //if (a[mid] > key)  // if key value is less than mid element
        {
            e = mid - 1;       // we reseat the end coz elems from mid to end are alerady checked 
        }
    }
    // if (s == e)
    // {
    //     cout << "Key elment is found at position: ?" << endl;        // not working & not important in code
    //     c = 1;                                                       // coz in while it is satisflied
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

    cout << "\nEnter array elements in *sorted order*: " << endl;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    cout << "Array elements are: " << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << " " << a[i];
    }

    cout << "\nEnter key element: ";
    cin >> key;

    binarysearch(a, n, key);

    return 0;
}