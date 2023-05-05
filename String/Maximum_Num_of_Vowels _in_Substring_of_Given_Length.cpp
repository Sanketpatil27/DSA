class Solution {
public:

    bool ifVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    int maxVowels(string s, int k) {
        int cnt = 0;
        int mxcnt = 0;
                
        for(int i = 0; i < s.size(); i++) {
            
            // if previous window affect to count means contain vowel
            if(i >= k && ifVowel(s[i-k]))
                cnt--;

            if(ifVowel(s[i])) 
                cnt++;
            
            mxcnt = max(cnt, mxcnt);
        }

        return mxcnt;
    }
};
