#include<iostream>
#include<vector>
#include<stack>
using namespace std;
 

bool checkRow(vector<vector<int> >& M, int row, int n)
{
    // row always remain constant
    for(int col = 0; col < n; col++)
    {
        if(M[row][col] == 1)
            return false;
    }
    
    // it will return true if entire row contain 0s
    return true;
}

int checkCol(vector<vector<int> >& M, int col, int n)
{
    int cntOnes = 0;
    for(int row = 0; row < n; row++)
    {
        if(M[row][col] == 1)
            cntOnes++;
    }
    
    return cntOnes;
}

int celebrity(vector<vector<int> >& M, int n) 
{
    // time: O(n^2) space: O(1)
    
    // step1: find row with all 0's
    // celebrity person's rows will have all 0s (coz celebrity knows no-one)
    int i;
    for(i = 0; i < n; i++) {
        // return true if all 0's
        if(checkRow(M, i, n)) {
            // break here coz this can be possible candidate
            break;
        }
    }
    
    // if no celebrity found! (everyone knows any one preson)
    // if there is not single row that contains all 0s
    if(i == n)  
        return -1;
        
    // if i breaks in before ending 'n' means there is row with all 0's
    // now we have to check if on that ith column all should be 1 except the diagonal 
    
    // step2: ensure that the ith person is celebrity by checking its column
    // now we check celebrity preson's column
    // celebrity person's column always have all 1's except the diagonal(the person itself)
    if(checkCol(M, i, n) == n-1)
        return i;       // ith person is celebrity

        
    return -1;
}

// efficient solution:

bool knows(vector<vector<int>> M, int person1, int person2)
{
    // 1 means person1 know person2
    return M[person1][person2] == 1;    
}

int efficient(vector<vector<int> >& M, int n) 
{
    // approach 2: using stack
    // time: O(n) space: O(n)
    
    stack<int> s;
    // step1: push all N persons in stacks
    for(int i = 0; i < n; i++)
        s.push(i);
    
    // step2: pick top 2 persons & check they know each other or not
    while(s.size() > 1)
    {
        int a = s.top();
        s.pop();
        
        int b = s.top();
        s.pop();
        
        // check if a knows b, if yes then a can't be celebrity, discard it & push b again in stack
        if(knows(M, a, b))
            s.push(b);
            
        // if b knows a then it can't be celebrity, a can be so push it again to further check
        else
            s.push(a);
    }
    
    // at last only 1 person will be ramaining in stack, this can be possible celebrity
    // we verify it by: 
    //    i:  celebrity knows no-one
    //    ii: everyone knows celebrity
    
    // i: we check celebrity's row, it should contain all 0's, coz he doesn't know anyone
    if(checkRow(M, s.top(), n))
    {
        // ii: everyone should know celebrity, means celebrity person's column
        //     should contain all 1's except the celebrity person itself (diagonal)
        if(checkCol(M, s.top(), n) == n-1)
            return s.top();     // this is celebrity 
    }
    
    // if no such celebrity found!!
    return -1;
}

int main()
{

    // question: GFG
    // A celebrity is a person who is known to all but does not know anyone at a party. If you go to a party of N people, 
    // find if there is a celebrity in the party or not.
    // A square NxN matrix M[][] is used to represent people at the party such that if an element of row i and column j 
    // is set to 1 it means ith person knows jth person. Here M[i][i] will always be 0.
    // Note: Follow 0 based indexing. return index of celebrity
    
    // Example 1:
    // Input:
    // N = 3
    // M[][] = {{0 1 0},
    //         {0 0 0}, 
    //         {0 1 0}}
    // Output: 1
    // Explanation: 0th and 2nd person both know 1. Therefore, 1 is the celebrity. 

    int N = 3;
    vector<vector<int>> M = {  {0, 1, 0},
                               {0, 0, 0}, 
                               {0, 1, 0}
                            };

    // brute force: time: O(n^2)  space: O(1)           // check notes in notebook
    cout << "Celebrity person index: " << celebrity(M, N);

    // optimized: time: O(n)   space: O(n)
    // this giving TLE In GFG 
    cout << "\nCelebrity person index: " << efficient(M, N);

}