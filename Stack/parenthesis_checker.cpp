#include<iostream>
#include<stack>
using namespace std;
 
bool checkPair(char top, char curr)
{
    if(top == '(' && curr == ')')
        return true;
    
    if(top == '[' && curr == ']')
        return true;
    
    if(top == '{' && curr == '}')
        return true;

    return false;       // as not any pair match
}


bool validParenthesis(string parenthesis)
{
    stack<char> s;

    for(int i = 0; i < parenthesis.size(); i++)
    {
        // if current parenthesis is opening 
        if(parenthesis[i] == '(' || parenthesis[i] == '{' || parenthesis[i] == '[')
            s.push(parenthesis[i]);
        
        // if its an closing one then 
        else if(parenthesis[i] == ')' || parenthesis[i] == '}' || parenthesis[i] == ']')  
        {
            // if there is any closing parenthesis occurs then first check if there's opening pair should be on top of stack
            // we poping here so we have to check if its underflow!!
            if(!s.empty() && checkPair(s.top(), parenthesis[i]))
                s.pop();            // then pop it, as we closed one pair
            else 
               return false;
        }
    }

    // after all these operations if all opened brackets are closed then only, we can say valid parenthesis 
    if(!s.empty())
        return false;

    return true;
}

int main()
{
    
    string parenthesis = "(([{[]}]))";

    // time: O(n)      space: O(n)  for storing brackets in stack
    if(validParenthesis(parenthesis))
        cout << "given parenthesis are valid" << endl;
    else
        cout << "given parenthesis not valid" << endl;
}