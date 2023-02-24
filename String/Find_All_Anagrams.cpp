// Given two strings s and p, return an array of all the start indices of p's anagrams in s. 
// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
// typically using all the original letters exactly once.

#include<iostream>
#include<vector>

using namespace std;

void solve(string s, string p, vector<int> &ans) {
    vector<int> v1(26, 0);          // to store p chars on its indexes
    vector<int> v2(26, 0);          // to store s chars on its indexes

    for (auto i: p)
        v1[i - 'a']++;              // mark 1 for presece, - 'a' give index of that character on v1

    

    int i = 0, j = 0;               // i work for sliding window, removing element out of window

    while (j < s.size())
    {
        v2[s[j] - 'a']++;                     // mark current char index of s to 1

        if(j-i+1 < p.size())       // to check window size  (j-i+1) is used
            j++;

        if(j-i+1 == p.size()) {     // if window size matches then we check our vectors are equal or not
            if(v1 == v2) {
                ans.push_back(i);
                j++;                    // this take or not?????
            }
        }

        else if(j-i+1 > p.size()) {
            v2[s[i] - 'a']--;                // we remove the elem out of window and increment i & j for next window
            j++;
            i++;
        }
    }
}

int main() {
    string s = "abab";
    string p = "ab";
    vector<int> ans;

    // base case
    if(p.size() > s.size())
            return -1;
        
    solve(s, p, ans);

    cout << "indices of anagrams: " << endl;
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

}