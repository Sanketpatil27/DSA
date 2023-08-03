#include<iostream>
#include<stack>
using namespace std;
 
int checkRedundancy(string str) {
    // will be following same approach as check balenced parenthesis, but as here said valid 
    // expression then also we have to put same logic as balanced parenthesis coz we  have 
    // to do same operations if we encountered a closing bracket, we have to pop till got an 
    // opening bracket,
    // if when we see closing bracket, and top contains the opening bracket then we can say
    // this is unneccessory bracket, as between them there is no operands
    
    // Note: given expression is ** valid ** so don't need parenthesis checker
    stack<char> st;
    
    for(int i = 0; i < str.size(); i++)
    {            

        // if current char is opening parenthesis or any operator then push it
        if(str[i] == '(' || str[i] == '{' || str[i] == '[' ||
            str[i] == '+' || str[i] == '-' || str[i] == '*' ||
            str[i] == '/')
                    st.push(str[i]);
            
            
        // if its an closing one then pop till got opening bracket
        else if(str[i] == ')' || str[i] == '}' || str[i] == ']')  
        {
            // if first stack top contains opening bracket
            // means there is no operator in between, then this is meaningless brackets
            if(st.top() == '(' || st.top() == '[' || st.top() == '{')
                return 1;
            
            // otherwise pop till got any opening bracket
            // given exression is valid so stack can't be empty() while searching
            while(!st.empty() && (st.top() != '(' && st.top() != '{' && st.top() != '['))
                st.pop();
            
            // loop over emasn our stack top contains opening bracket, pop it now
            if(!st.empty())     
                st.pop();
        }
    }

    // if all expression successfully complete means no redundant brackets are theer
    return 0;
}

int main()
{
    // Given a string of balanced expression, find if it contains a redundant parenthesis or not. 
    // A set of parenthesis are redundant if the same sub-expression is surrounded by unnecessary or multiple brackets. 
    // Print Yes if redundant, else No.
    // Note: Expression may contain + , - , *, and / operators. Given expression is valid and no white spaces present.

    string exp = "(a+b+(c+d))";       // not contains meaningless breakets
    // string exp = "((a+b))";       // contains meaningless breakets

    cout << "does given expression contains redundant parenthesis?: " << checkRedundancy(exp);
}