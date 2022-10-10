// arr before swaping = 1 3 4 5
// after swap alternatives =  3 1 5 4
// video: https://www.youtube.com/watch?v=oVa8DfUDKTw&t=851s

#include<iostream>
using namespace std;

void printArr(int a[], int n) {

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

void swapAlternatives(int a[], int n) {
    
    // increase i with 2 coz we have to swap alternatives  0th elem with 1th   and 2nd elem with 3rd
    for (int i = 0; i < n; i+=2)
    {
        // here we are checking if i+1 is not out of range of an array size, if it is then we don't do anything
        // otherwise we swap i with i+1, therefore checking for (i+1<n)
        if (i+1 < n)
        {
            // swap(a[i], a[i+1]);  // function to swap elems
            int temp = a[i+1];
            a[i+1] = a[i];
            a[i] = temp;
        }
    }
}

int main(){
    int n; 
    cout << "Enter array size: " << endl;
    cin >> n;
    int a[n];


    cout << "Enter array Elements: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << "Array Elements are: " << endl;
    printArr(a, n);
    cout << "\nArray Elements after swapping alternatives are: " << endl;
    swapAlternatives(a, n);
    printArr(a, n);
}