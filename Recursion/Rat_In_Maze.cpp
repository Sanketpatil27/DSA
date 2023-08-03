// GFG problem

#include<bits/stdc++.h>

using namespace std;

bool isSafe(int x, int y, vector<vector<int>> &maze, vector<vector<int>> visited, int n) {

    // we check that current position is valid for moving or not
    // place should not blocked, not visited & not out of maze 
    // (place check last coz it can invalid so first check x and y bounds)
    if((x >= 0 && x < n && y >= 0 && y < n) && maze[x][y] == 1 || visited[x][y] == 0) 
        return true;

    return false;  
}

void solve(int x, int y, vector<string> &ans, vector<vector<int>> &visited, string path, int n, vector<vector<int>> &maze) {
    if(x == n-1 && y == n-1) {
        ans.push_back(path);
        return;
    }

    visited[x][y] = 1;       // mark current position as checked to don't come again there

    // we have 4 choices to check for 4 directions D, L, R, U
    
    // first checking for *down*, only x(row) will increament
    int newx = x+1;         
    int newy = y;

    if(isSafe(newx, newy, maze, visited, n)) {
        path.push_back('D');
        solve(newx, newy, ans, visited, path, n, maze);
        path.pop_back();        // backtrack
    }

    // check for left
    newx = x;
    newy = y-1;

    if(isSafe(newx, newy, maze, visited, n)) {
        path.push_back('L');
        solve(newx, newy, ans, visited, path, n, maze);
        path.pop_back();        // backtrack
    }

    // check for right
    newx = x;
    newy = y+1;

    if(isSafe(newx, newy, maze, visited, n)) {
        path.push_back('R');
        solve(newx, newy, ans, visited, path, n, maze);
        path.pop_back();        // backtrack
    }

    // check for Up
    newx = x-1;
    newy = y;

    if(isSafe(newx, newy, maze, visited, n)) {
        path.push_back('U');
        solve(newx, newy, ans, visited, path, n, maze);
        path.pop_back();        // backtrack
    }

    visited[x][y] = 0;
}

void findPath(vector<vector<int>> &maze, int n, vector<string> &ans) {
    int srcx = 0;
    int srcy = 0;

    vector<vector<int>> visited;

    for(int i = 0; i < n; i++) 
        for(int j = 0; j < n; j++) 
            visited[i][j] = 0;      // mark all path initially as unvisited
    
    string path = "";

    solve(srcx, srcy, ans, visited, path, n, maze);
}

int main() {
    int n = 4;
    vector<vector<int>> maze = {    {1, 0, 0, 0},
                                    {1, 1, 0, 1}, 
                                    {1, 1, 0, 0},
                                    {0, 1, 1, 1}
                                };

    if(maze[0][0] == 0)
        return -1;      // rat can't move 

    vector<string> ans;

    findPath(maze, n, ans);

    for(auto i: ans) 
        cout << i << " ";
}