#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> bracketNumbers(string S)
{
    vector<int> ans;
    stack<int> st;

    int bal = 0;

    // push the number of opening tags in stack & while poping
    // print stack top
    for(int i = 0; i < S.size(); i++)
    {
        if(S[i]=='(')
        {
            bal++;
            ans.push_back(bal);
            st.push(bal);
        }
        else if(S[i]==')')
        {
            ans.push_back(st.top());
            st.pop();
        }
    }

    return ans;
}

int main()
{
    // Given a string S, the task is to find the bracket numbers. 
    // Example 1:
    // Input:  S = "(aa(bdc))p(dee)"
    // Output: 1 2 2 1 3 3
    // Explanation: The highlighted brackets in
    // the given string (aa(bdc))p(dee) has been 
    // assigned the numbers as: 1 2 2 1 3 3.

    string s = "(aa(bdc))p(dee)";

    vector<int> ans = bracketNumbers(s);
    for(int i: ans)
        cout << i << " ";

}