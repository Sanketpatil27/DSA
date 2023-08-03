#include<iostream>
using namespace std;
 
int findSteps(int n, int cnt)
{
    if(n <= 0)
        return cnt;

    if(n % 2 == 0)
        return findSteps(n/2, cnt+1);
    else
        findSteps(n-1, cnt+1);
}

int main()
{
    // leetcode problem.  if n is even then divide by 2, if n odd then reduce 1 from it
    int n = 16;     // o/p: 5 for n = 16

    int cnt = 0;
    cout << "No. Of steps to reduce n to 0 are: " << findSteps(n, cnt);
}