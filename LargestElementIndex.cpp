#include <bits/stdc++.h>
using namespace std;

// complexity is O(n^2),coz each element is traversed two times in worst case scenerio, without using that self modified session

// int getLargest(int a[], int n) {
//     for (int i = 0; i < n; i++) {
//         bool flag = true;       // it means current element is the largest element
//         for (int j = i+1; j < n; j++) {   // j=i+1 coz when loop breaks, it has checken elements till i, has mast smaller, so we check from where the loops break(self modified)
//             if (a[j] > a[i]) {
//                 flag = false;       // it means other largest element is found
//                 break;              // it will break the current loop to check next elements
//             }
//         }
//         if (flag == true)   // it will execute when upper loop is complete and flag remains true means current is largest element
//             return i;
//     }
//     return -1;          // it will not execute coz, a[] has atleast one greater element 
// }


// O(n) complexity traversing only one time(self made) ->
// int getLargest(int a[], int n) {
//     int mx = a[0], ind = 0;
//     for (int i = 0; i < n; i++) {
//         mx = max(a[i], mx);
//         if(a[i] == mx) {     // should use: >  int this condition?
//             ind = i;
//         }
//     }
//     return ind;
// }        // one catche is it return last greater elem index if similiar greater numbers


// GeeksForGeeks Solution O(n) complexity traversing only one time(self made) ->
int getLargest(int a[], int n) {
    int res = a[0];     // initially we setting largest elem to first elem
    
    for (int i = 1; i < n; i++)     // starting from 1 coz 0 is already setten to res initially
        if (a[i] > a[res])
            res = i;
        // or res = max(res, a[i])
    return res;
}

int main(){
    int a[] = {1,2,35,74,74,22};
    int n = 6;      // size of the array
    cout << getLargest(a, n);

    return 0;
}
