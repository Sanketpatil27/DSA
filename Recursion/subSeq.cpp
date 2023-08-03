#include<iostream>
using namespace std;
 
void subSeq(string str, string sub, int i)
{
    if (i == str.size())
    {
        cout << sub << endl;
        return;
    }
    
    // first we don't take 
    subSeq(str, sub, i+1);

    // then we take it
    subSeq(str, sub+str[i], i+1);
}


int main()
{
    string str = "abc";

    cout << "Subsequences of given string: \n";
    int i = 0;      // iterator for traversing string
    subSeq(str, "", i);
}