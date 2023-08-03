#include<iostream>
#include<stack>
using namespace std;

int prec(char ch)
{
    // we have to always push bracket '(' without seeing any top
    if(ch == '(' || ch == ')' || ch == '[' || ch == ']' || ch == '{' || ch == '}')
        return 0;
        
    if(ch == '+' || ch == '-')
        return 1;
        
    if(ch == '*' || ch == '/')
        return 2;
        
    if(ch == '^')
        return 3;
}

// still incomplete for more brackets like [] {}
string infixToPostfix(string s) {
    stack<char> st;
    string ans = "";
    int topPrec;        // store precedance of top of stack & current operator
    int chPrec;   
    
    for(int i = 0; i < s.size(); i++)
    {
        char ch = s[i];             // current character 
        
        // if current char is operator then do this:
        if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '(' ||
            ch == ')' || ch == '{' || ch == '}' || ch == '[' || ch == ']')
        {
            topPrec = st.empty() ? -1 : prec(st.top());
            chPrec = prec(ch);
            
            // always push opening bracket without seeing top of stack
            if(s.empty() || ch == '(' || ch == '{' || ch == '[')
                st.push(ch);
                
            
            // if its closing bracket then pop till opening bracket & add operators
            else if(ch == ')')
            {
                while(st.top() != '(')
                {
                    ans += st.top();
                    st.pop();
                }
                
                // now our stack top will be on opening bracket (
                // so pop it without adding to answer
                st.pop();
            }
            
            // current operator precedance high then push in stack
            // if current operator prec equal then also don't push directly, first pop
            else if(chPrec > topPrec)
                st.push(ch);
            
            else
            {
                while(!st.empty() && prec(st.top()) >= chPrec)
                {
                    // first add current operator then remove it from stack
                    ans += st.top();
                    st.pop();
                }
                
                // now insert current operator in stack
                st.push(ch);
            }
        }
        
        // if current character is not operator then add it in ans
        else
            ans += ch;
    }
    
    // at last if stack not empty then pop all operators from it & add it in ans
    while(!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    
    return ans;
}


int main()
{
    string expression = "a+b*(c^d-e)^(f+g*h)-i";        // o/p:  abcd^e-fgh*+^*+i-
    // string postfix = 
    cout << "Infix To Postfix conversion: " << infixToPostfix(expression);
}