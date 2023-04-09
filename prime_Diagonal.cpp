// leetcode
// You are given a 0-indexed two-dimensional integer array nums.

// Return the largest prime number that lies on at least one of the diagonals of nums. In case, no prime is present on any of the diagonals, return 0.

// Note that:

// An integer is prime if it is greater than 1 and has no positive integer divisors other than 1 and itself.
// An integer val is on one of the diagonals of nums if there exists an integer i for which nums[i][i] = val or an i for which nums[i][nums.length - i - 1]= val.

class Solution {
public:
    
    long long isPrime(long long num) {
        if(num <= 1)
            return false;
        
        if(num < 3) 
            return true;
        
        if(num % 2 == 0  || num % 3 == 0)
            return false;
        
        for(long long i = 5;  i*i <= num; i += 6 ) {
            if(num % i == 0 || num % (i+2) == 0)
                return false;
        }
        
        return true;
    }
    
    int diagonalPrime(vector<vector<int>>& nums) {
        long mx = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            for (int j = 0; j  < nums.size(); j++) {
                long val = nums[i][j];
                
                if(nums[i][i] == val || nums[i][nums.size() - i - 1] == val) {
                    if(isPrime(val))
                        mx = max(mx, val);
                }
            }
        }
        
        return mx;
    }
};
