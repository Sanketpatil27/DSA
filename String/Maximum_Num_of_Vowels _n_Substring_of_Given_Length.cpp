class Solution {
public:
    int maxVowels(string s, int k) {
        set<int> vowels = {'a', 'e', 'i', 'o', 'u'};
        int cnt = 0;
        int mxcnt = 0;
        
        for(int i = 0; i < k; i++) 
            if(vowels.find(s[i]) != vowels.end()) 
                cnt++;
        
        mxcnt = max(mxcnt, cnt);

        for(int i = k; i < s.size(); i++) {
            
            // if previous window affect to count means contain vowel
            if(vowels.find(s[i-k]) != vowels.end()) 
                cnt--;

            if(vowels.find(s[i]) != vowels.end()) 
                cnt++;
            
            mxcnt = max(cnt, mxcnt);
        }

        return mxcnt;
    }
};
