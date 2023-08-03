#include <iostream>
using namespace std;

// return the maximum pieces which can be made

int maxPieces(int n, int a, int b, int c) {
    
    if(n == 0) return 0;
    if(n < 0) return -1;
    
    int res = max(maxPieces(n-a, a, b, c),
                  maxPieces(n-b, a, b, c),
                  maxPieces(n-c, a, b, c)
				 );
    
    if (res == -1) return -1;
    
    return res+1;
}

int main() {
// 	rope cutting problem
    int a = 12, b = 11, c = 9;
    int n = 23;     // n is length of the rope 
    
    cout << maxPieces(n, a, b, c);
	return 0;
}