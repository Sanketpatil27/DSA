#include<iostream>
using namespace std;
 
bool isSorted(int arr[], int i, int n)
{
    // it we are on last element in array
    if(i == n-1)
        return true;

    if (arr[i] < arr[i+1])
        isSorted(arr, i+1, n);
    else
        return false;
}

int main()
{
    int n = 6;
    int arr[n] = {1, 3, 45,65,70, 97};

    int i = 0;
    cout << "is array sorted?: " << isSorted(arr, i, n);
}