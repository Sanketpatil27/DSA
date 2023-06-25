// You are given an integer array bloomDay, an integer m and an integer k.
// You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.
// The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.
// Return the minimum number of days you need to wait to be able to make m bouquets from the garden. 
// If it is impossible to make m bouquets return -1.

// Example 1:

// Input: bloomDay = [1,10,3,10,2], m = 3, k = 1
// Output: 3
// Explanation: Let us see what happened in the first three days. x means flower bloomed and _ means 
//              flower did not bloom in the garden.
// We need 3 bouquets each should contain 1 flower.
// After day 1: [x, _, _, _, _]   // we can only make one bouquet.
// After day 2: [x, _, _, _, x]   // we can only make two bouquets.
// After day 3: [x, _, x, _, x]   // we can make 3 bouquets. The answer is 3.


#include<bits/stdc++.h>
using namespace std;
 

int minDays(vector<int>& bloomDay, int m, int k) {
    // this problem approach same as split array to minimum from max sum posibitilies 

    // we have to make m bouquets with usign k adjecent flowers
    
    // here the negative case is if our m(bouquets) * k(adjecent) > given total bouquets (n) then 
    // we can't form m bouqets with k adjecent flowers there must be lack of flowers
    // ex: total flowers = [f1, f2, f3, f4] we have to make m=2 bouquets with k=3 adject flowers
    // so we can one make 1 bouquets(f1,f2,f3) then only remain one flower that is f4, now we can't
    // make another 1 bouquet with that 1 flower we need 2 more 
    // it cann't be used coz multiplication giving overflow for larger case
    // int n = bloomDay.size();
    // if(m * k > n)
    //     return -1;

    // we can find range from which our minimum 1 flower can bloom & to bloom all flowers we 
    // need maximum day from that all flowers can bloom withing that day

    // to find min day & max day
    int minDay = INT_MAX;
    int maxDay = INT_MIN;

    for(int i: bloomDay) {
        minDay = min(minDay, i);
        maxDay = max(maxDay, i);
    }

    // now we have range from minDay to maxDay so we use binary search to minimize total days 
    // to make m bouquets
    int low = minDay;
    int high = maxDay;
    int ans = -1;

    while(low <= high) {
        int adjacent = 0;                   // initially we haven't taken any flower
        int bouquets = 0;                   // total bouquets we form

        int mid = low +(high-low) / 2;      // mid is minimum day that we have choosen as target

        for(int i: bloomDay) {
            
            // if current flower require more bloom days than we have set then don't include it
            if(i <= mid) {                
                if(adjacent + 1 <= k) 
                    adjacent++;
                
                // means we have taken needed adjacent flowers to make 1 bouquet
                // so make next boquet & and take current flower in that
                else {
                    bouquets++;         
                    adjacent = 1;
                }
            }
            
            // if current flower can't bloom in target days then we reseat our adjacent
            // coz this breaks to take *adjacent* flowers, before this check if we make 1 bouquet
            else {
                if(adjacent == k)
                    bouquets++;
                adjacent = 0;
            }
        }

        // case: [1,10,3,10,2]
        // check possibility that we take last flower & we need only 1 adjacent so we can't 
        // check that in traversing array coz it end's at last flower
        if(adjacent == k)
            bouquets++;

        // if we make required bouquets with our target day's then try to minimize target days
        // & find if there any less days can make m bouquets but we have to store this target
        // coz it can be the answer as it satisfy to make m bouquets
        if(bouquets >= m) {     // there can be more than m bonquets, more bouquets not a problem
            ans = mid;
            high = mid - 1;
        }
        
        // if we enable to make m bouquets in our target days then we have to increase target days
        // to make more bouquets
        else 
            low = mid + 1;
    }

    return ans;
}

int main()
{
    vector<int> bloomDay = {1, 10, 3, 10, 2};
    int m = 3, k = 1;

    cout << "minimum days to make m bouquates: " << minDays(bloomDay, m, k);
}