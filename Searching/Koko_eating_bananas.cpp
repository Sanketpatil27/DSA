#include<bits/stdc++.h>

using namespace std;
 

// neive approach is try all the bananas that koko can eat from range [1 - max(piles)]
// and check the hours required for eat all bananas with that banana per hour, if less or equal to h then return i

// hourlyBanana is count that koko can eat hourly
int findHours(vector<int> piles, int hourlyBanana) {
    int reqhours = 0;       // require hours for eating all baanans

    for(int i = 0; i < piles.size(); i++) 
        // ceil is used to get  3.5 hr to 4 hours (for that double value is required)
        reqhours += ceil((double) piles[i] / hourlyBanana);         
        // it give hours to eat bananas at pile[i] (ex: hourly = 3 , piles[i] = 6 so 2 hours require for eating bananas at pile[i])
    
    return reqhours;
}

int neive(vector<int> piles, int h) {
    int mxBanana = *max_element(piles.begin(), piles.end());        // max_element function requires O(n) time

    for (int i = 1; i <= mxBanana; i++)
    {
        int totalHours = findHours(piles, i);

        if(totalHours <= h)
            return i;
    }
    
    return -1;
}




int minEatingSpeed(vector<int>& piles, int h) {
        // to eat all bananas from piles we either chooes lowest count of banana from 1
        // or can choose highest count of banabas from pile 

        // case1: minimum banana can eat: we can start from 1 banana per hours not less than that 

        // case2: maximum banana can eat: we take high banana count from piles don't need to get higher than this 

        // so first we find count of max bananas & min bananas from piles
        int mxBananas = INT_MIN;
        int mnBananas = 1;

        for(int bananas: piles) 
            mxBananas = max(mxBananas, bananas);   
        
        // now we have range from minimum bananas to max Bananas per hour so we use searching
        // ans store the count of min bananas that can Koko eat/hour to eat all in *h hours
        int low = mnBananas;
        int high = mxBananas;    // we can also use: *max_element(piles.begin(),piles.end());
        int ans = 0;             

        while(low <= high) {
            // it calculates time to eat all bananas
            long long hour = 0;   // int type giving error on large data while adding in if condition

            // mid is the target bananas / hour that koko can choose eat
            int mid = low + (high - low) / 2;       

            for(int banana: piles) {
                // if current pile contain > bananas than we target 
                if(banana > mid) {
                    // if target to eat 3 banana/h & current pile has 6 bananas then increment hour by
                    // hour += (divide bananas from mid)
                    
                    // to get ceil value we have to cast dividation to double (point values)
                    hour += ceil((double) banana / mid);
                }
                // if current banana is <= mid then it can be eaten in 1 hours
                else 
                    hour++;
            }

            //now if hour > h then we have to increase the target bananas per hour to eat all within h
            if(hour > h) 
                low = mid + 1;

            // if hour <= mid then we can further try to minimize banabas per hour
            // before store the ans as target bananas satisfies the condition
            else {
                ans = mid;
                high = mid - 1;
            }
        }

        return ans;
    }

int main()
{
    vector<int> piles = {3, 6, 7, 11};              // ans for this if h = 8 is 4
    // vector<int> piles = {30, 11, 23, 4, 20};              // ans for this if h = 5 is 30
    int h = 8;                                      // hours till koko has to eat bananas

    // for neive, time: O(max(piles) * h)
    cout << "minimum bananas per hour Koko can eat to eat all bananas within h hours: " << neive(piles, h) << endl;

    // for efficient solution, time: O(max(piles) * h)
    cout << "minimum bananas per hour Koko can eat to eat all bananas within h hours: " << minEatingSpeed(piles, h) << endl;
}