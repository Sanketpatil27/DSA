// move all zeroes to end of array while maintaining the order of non-zero elements

#include <iostream>
using namespace std;

// neive solution:
// 1]can also solve this problem with creating temp[n] arr and store first non-zero elems and then store zero elems
// and copy that arry to a[] array, this would take some extra space
// 2]one another method is to traverse elems if there is zero then write another loop that will check 
// if next any element is non-zero then swap them, 

// best solution: 
// effiency: time complexity: O(n) we are checking each element only one time, 
// Auxilary space: O(1)  not using any extra space
void moveZeroes(int a[], int n)
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        // we swap the non-zero element with the zero element index with help of cnt variable
        // cnt = 0; arr = 9 0 4, we increament cnt when 9 is there, then ignore 0,
        // then 4 will be replaced with the a[cnt] (that cnt now at the index of the 0th element)
        // which is 1st index element and again cnt will increamented
        if (a[i] != 0)
        {
            swap(a[i], a[cnt++]); // cnt will increament after this instruction
        }
    }
}


void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    cout << endl;
}

int main()
{
    int n = 7;
    int a[n] = {9, 0, 4, 5, 0, 0, 8};
    cout << "Before moving zeroes to end: ";
    printArray(a, n);
    cout << "After moving zeroes to end: ";
    moveZeroes(a, n);
    printArray(a, n);
}