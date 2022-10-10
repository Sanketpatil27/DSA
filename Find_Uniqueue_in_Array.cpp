#include <iostream>
using namespace std;

// problem: https://www.codingninjas.com/codestudio/problems/find-unique_625159?source=youtube&campaign=love_babbar_codestudio1&utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_codestudio1
// video: https://www.youtube.com/watch?v=oVa8DfUDKTw&t=851s

// XOR performs on only binary operations, checks bits are same or not return 0 for same 1 for different
// here we are using xor, elements that are same, then in xor it is 0
//  ex: 4 ^ 4 = 0
// if elems are xor with 0 ans is -> that element
// ex: 0 ^ 4 = 4

void printArr(int a[], int n)
{

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

int findUnique(int a[], int n)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = ans ^ a[i]; // here it will xor for all elems, same elems gives ans 0 , if unique is there then ans is that elem
    }
    return ans;
}

int main()
{
    int n;
    cout << "Enter Array size: ";
    cin >> n;

    int a[n];

    cout << "Enter Array Elems: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << "Array Elements are: " << endl;
    printArr(a, n);

    cout << "\nUnique number in array is: " << findUnique(a, n) << endl;
}