#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<string> generate(int N)
{
    vector<string> ans;
	queue<string> q;
	
	q.push("1");
	
	
	for(int i = 0; i < N; i++)
	{
	    string curr = q.front();
	    ans.push_back(curr);
	    q.pop();                        // remove item front Queue
	    
	    q.push(curr+"0");
	    q.push(curr+"1");
	}

	return ans;
}

int main()
{
    int n = 10;
    vector<string> ans = generate(n);

    for(string i: ans)
        cout << i << " ";
}