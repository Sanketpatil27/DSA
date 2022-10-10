/*
You are given an array/list 'ARR' of 'N' positive integers and an integer 'K'. Your task is
to check if there exists a subset in 'ARR' with a sum equal to 'K'.
Note: Return true if there exists a subset with sum equal to 'K'. Otherwise, return false.
For Example:
If 'ARR' is {1,2,3,4) and 'K' 4, then there exists 2 subsets with sum = 4. 
These are {1,3} and {4}. Hence, return true.
no of total subsets are equal to 2^no.of elems in 

// ans of this code founds only subarrays not subsets!, So it's checks for subarrays
*/

#include<iostream>
using namespace std;

bool subsetSumToK(int n, int k, int a[]) {
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int s = 0;
            for (int m = i; m <= j; m++) {
                if(s > m) {
                    s = 0;
                }
                else if (s == k)
                {
                    return true;
                }
                s += a[m];
            }
            if(s == k) 
                return true;
        }
    }
    return false;
}

int main()
{
    int n = 4; int k = 172; 
    int a[] = {8 ,59 ,58 ,79 ,44 ,7 ,65, 69, 60, 51};
    cout << subsetSumToK(n, k, a);
}