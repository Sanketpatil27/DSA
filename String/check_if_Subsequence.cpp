// check if string is subsequence of other string
#include<iostream>

using namespace std;


// recursive: time = space = O(m+n)   where m & n are sizes of both strings
bool solve(string &s, string &p, int i, int j) {
    if(i == s.size()) 
        return true;

    if(j == p.size())
        return false;

    if(s[i] != p[j])
        return solve(s, p, i, j+1);
    else
        return solve(s, p, i+1, j+1);        
}


int main() {
    string p = "geeksforgeeks";
    string s = "gfg";

    int i = 0;      // to traverse s
    int j = 0;      // for p

    while(j < p.size() && i < s.size()) {
        if(p[j] == s[i]) 
            i++;
        
        j++;
    }

    // Time O(n+m)
    if (i == s.size())
        cout << "Yes s is subsequence of p" << endl;

    else
        cout << "No it's not a subsequence" << endl;


    cout << solve(s, p, 0, 0);
}