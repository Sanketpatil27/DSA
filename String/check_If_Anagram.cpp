// check if string is anagram of another string (anagram means permutation of another string)

#include<bits/stdc++.h>

using namespace std;


bool solve(string &a, string &b) {
    // the idea is to add char index of a string and substract char index of b string 
    // at last if vector all elems are 0 then they must be anagrams, 0 means equalized values

    vector<int> v(26, 0);           // vecotr to store all character on their index, initially all 0

    for (int i = 0; i < a.size(); i++)
    {
        v[a[i] - 'a']++;        // this formula returns the index of that char
        v[b[i] - 'a']--;
    }
    
    for(auto i: v)          // check all elems are 0 or not
        if(i != 0) 
            return false;
    
    return true;
}

int main() {
    string a  = "listen";
    string b  = "silent";

    // neive solution to sort both arrays and check if equal, after sorting both becomes 
    // root of their permutation string ex: acb becomes abc (abc is root of acb)
    // takes time: O(nlogn)     because sorting

    if(a.size() != b.size()) {        // for anagram they must be equal sized
        cout << "No, Not an anagrams of each other length is different!" << endl;
        return -1;
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    if(a == b)
        cout << "Yes both are anagrams of each other!" << endl;
    else
        cout << "No, Not an anagrams of each other!" << endl;

    // better approach
    cout << solve(a, b);
}