#include<iostream>
#include<deque>
#include<algorithm>     // for sort function
using namespace std;
 
//Function to return the minimum cost of connecting the ropes.
long long minCost(long long arr[], long long n) {

    // we sort array and insert in queue, so we can get min length rope on front of deque
    sort(arr, arr+n);
    deque<long long> dq(arr, arr+n);

    long long total_cost = 0;
    long long curr_cost = 0;
    
    // size > 1 coz getting 2 items at a time
    while(dq.size() > 1)
    {
        // we get the first 2 ropes addition (coz they are minimum on front)
        long long first = dq.front();
        dq.pop_front();

        long long second = dq.front();
        dq.pop_front();

        curr_cost = first + second;
        total_cost += curr_cost;

        // now insert the current cost while maintaining the sorted order of deque
        auto itr = dq.begin();
        for(itr = dq.begin(); itr != dq.end(); ++itr)
            if(*itr > curr_cost)
                break;

        // insert function insert elem before iterator
        dq.insert(itr, curr_cost);
    }
    
    // this will be the minimum total_cost
    return total_cost;
}

int main()
{
    // There are given N ropes of different lengths, we need to connect these ropes into one rope. 
    // The cost to connect two ropes is equal to sum of their lengths. 
    // The task is to connect the ropes with minimum cost. Given N size array arr[] contains the lengths of the ropes. 

    // Input:
    // n = 5
    // arr[] = {4, 2, 7, 6, 9}

    // Output: 
    // 62 

    // Explanation:
    // First, connect ropes 4 and 2, which makes
    // the array {6,7,6,9}. Cost of
    // this operation 4+2 = 6. Next, add ropes 
    // 6 and 6, which results in {12,7,9}. 
    // Cost of this operation 6+6 = 12.
    // Then, add 7 and 9, which makes the array {12,16}. 
    // Cost of this operation 7+9 = 16. And
    // finally, add these two which gives {28}.
    // Hence, the total cost is 6 + 12 + 16 + 
    // 28 = 62.

    int n = 5;
    // long long arr[n] = {4, 3, 2, 6};                // op: 29
    long long arr[n] = {4, 2, 7, 6, 9};                // op: 62

    // time: O(nlongn) for sorting + traversing + O(n) for searching sorted position of current cost
    // expected time is: O(nlongn)  so we should we priority queue to optimize this solution
    cout << "Minimum Cost to connect ropes: " << minCost(arr, n);  
}