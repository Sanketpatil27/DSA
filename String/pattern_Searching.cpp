// return the index where we find the pattern 
// this is improved neive approach for the pattern contain all distinct characters
// time : O(n) we since pattern contains different chars         space: O(1)

#include<bits/stdc++.h>

using namespace std;


int main() {
    string txt = "ABCABCDABCD";
    string bat = "ABCD";  

    // we traverse all txt and find if bat matches or not 
    int n = txt.length();
    int m = bat.length();

    for (int i = 0; i <= n-m; )
    {
        int j;
        for (j = 0; j < m; j++)
            if(bat[j] !=  txt[i+j])     // if not match then break
                break;
        
        if (j == m)     // means all characters mathes 
            cout << i << " ";

        if(j == 0)
            i++;        // if first character itself not match then we increment i

        else
            i = (i+j);  // means our match breaks in middle of pattern then we move to that index for new search
    }    
}
