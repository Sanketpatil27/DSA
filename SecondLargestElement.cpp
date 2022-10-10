// we have to return index of the second largest element, no duplicate allowed (second largest != largest element)
#include <bits/stdc++.h>
using namespace std;


// Naive Approach ->

// here we are finding the largest element's index->
// int largestInd(int a[], int n) {
//     int res = 0;        // setting the first index to result initially to check from 1st index
//     for (int i = 1; i < n; i++)
//     {
//         if (a[i] > a[res])
//         {
//             res = i;
//         }
//     }
//     return res;
// }

// int secondLargest(int a[], int n) {
//     int largest = largestInd(a, n); // here we calling and storing the returned largest element index in array
//     int res = -1; // initially we are storing result to -1, in case if all array elements are same, then we return it as -1

//     for (int i = 0; i < n; i++)
//     {
//         if (a[i] != a[largest])
//         {        
//             if (res == -1)
//             {
//                 res = i;
//             }
//             else if (a[i] > a[res])     
//             {
//                 res = i;         // here we are storing the second largest element index
//             }
//         }
//     }
//     return res;    
// }


// optimized (self made) GFG also: 
int secondLargest(int a[], int n) {
    int secLarge = -1, largest = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] > a[largest])
        {
            // if another largest element is got then we modified our previous largest as 
            // secondLargest element and largest as new largest index i
            secLarge = largest;
            largest = i;
        }
        // when our new a[i] is not greater than largest but greater than second largest 
        // then we do not access other largest elems than second largest in upper code , so we do
        // check for if a[i] is greater than secLarge elem
        else if (a[i] < a[largest])     // we are checking a[i] is not equal to a[largest] (same large elems not allowed)
        {
            if (a[i] > a[secLarge] || secLarge == -1) // have to check it (secLarge == -1) if seclarge is not set in uppercode , -1 is invalid index it can throw error when a[secLarge]
            {
                secLarge = i;
            }
        }
    }
    return secLarge;
}

int main(){
    int a[] = {1,2,365,1774,1474,922};
    int n = 6;      // size of the array
    cout << "Second largest element indext: " << secondLargest(a, n); 
    // that elem can be accessed as a[secondLargest(a, n)]

    return 0;
}