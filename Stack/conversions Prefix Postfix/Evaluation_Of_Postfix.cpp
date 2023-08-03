#include<iostream>
#include<stack>
using namespace std;
 
int evaluatePostfix(string s)
{
    stack<int> st;
    
    for(int i = 0; i < s.size(); i++)
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
                case '+':  st.push(op2 + op1);
                            break;
                case '-':  st.push(op2 - op1);
                            break;
                case '*':  st.push(op2 * op1);
                            break;
                case '/':  st.push(op2 / op1);
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
    string postfix = "231*+9-";       // single integers are there  o/p: -4
    cout << "Evaluation of PostFix: " << evaluatePostfix(postfix);
}