#include<iostream>
#include<stack>
using namespace std;
 
// very similar as postfix, diff is we traverse string from right to left, and sequence is Operand1 Operator Operand2 here
int evaluatePrefix(string s)
{
    stack<int> st;
    int n = s.size();

    for(int i = n-1; i >= 0; i--)
    {
        if(s[i] == '*' || s[i] == '-' || s[i] == '+' || s[i] == '/')
        {
            // pop last two operands and calculate them, (operand2  operator operand1)
            int op1 = st.top();   // convert to integer
            st.pop();
            
            int op2 = st.top();
            st.pop();
            
            switch(s[i]) 
            {
                case '+':  st.push(op1 + op2);
                            break;
                case '-':  st.push(op1 - op2);
                            break;
                case '*':  st.push(op1 * op2);
                            break;
                case '/':  st.push(op1 / op2);
            }
        }
        
        // if current is operand then, push it as it is
        else
            st.push(s[i] - '0');        // first convert to int then push
    }

    // at last answer lies on top of stack
    return st.top();
}

int main()
{
    string prefix = "-*234";       // single integers are there  o/p: 2

    cout << "Evaluation of PreFix: " << evaluatePrefix(prefix);
}