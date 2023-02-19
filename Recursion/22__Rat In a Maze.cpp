//Rat in maze problem: In this problem we have to find possible solution to reach rat at its destination
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//TC - O((3N^2)),  SC- O(L * X), L = length of the path, X = number of paths.

int isSafe(int x, int y, vector<vector<int>> &maze, int n, vector<vector<int>> &visited) //function for checking current index is safe to move or not.
{   
    //Checking main three conditions, 
    //i) checking x and y should greater than 0 and less than n. 
    //ii) checking maze of x and y should 1 i.e eligible to move. 
    //iii) checking visited of x and y should be 0, i.e it should not be visited previously.
    if ( (x >= 0 and x < n) && (y >= 0 and y < n) && (maze[x][y] == 1) && (visited[x][y] == 0) ) 
        return 1;

    else
        return 0;
}

void solve(vector<vector<int>> &maze, int n, int x, int y, vector<vector<int>> &visited, vector<string> &ans, string path)
{
    // Base case
    if ((x == n - 1) and (y == n - 1)) //checking whether x is reached to destination or not. if reached then current path will be our possible ans.
    {
        ans.push_back(path); //if reached then push path in ans vector and return.
        return;
    }

    visited[x][y] = 1; //as we visited xth,yth index then change visited of x and y to 1. i.e visited.

    // can we go down?
    int newX = x + 1; //As we go down, x gets increment.
    int newY = y; //y will be same.
    if (isSafe(newX, newY, maze, n, visited)) //checking whether newX and newY position is safe to move or not.
    {
        path.push_back('D'); //now pushing D into path as we move down.
        solve(maze, n, newX, newY, visited, ans, path); //and calling solve function for new x and y.
        path.pop_back(); //as we backtrack, we need to pop the current position to restore previous path.
    }

    // can we go left?
    newX = x;
    newY = y - 1;
    if (isSafe(newX, newY, maze, n, visited))
    {
        path.push_back('L');
        solve(maze, n, newX, newY, visited, ans, path);
        path.pop_back();
    }

    // can we go right?
    newX = x;
    newY = y + 1;
    if (isSafe(newX, newY, maze, n, visited))
    {
        path.push_back('R');
        solve(maze, n, newX, newY, visited, ans, path);
        path.pop_back();
    }

    // can we go Up?
    newX = x - 1;
    newY = y;
    if (isSafe(newX, newY, maze, n, visited))
    {
        path.push_back('U');
        solve(maze, n, newX, newY, visited, ans, path);
        path.pop_back();
    }

    visited[x][y] = 0; //At the end when we're returning, visited of x and y should mark as not visited i.e 0 cause we are returning from current index.
}


vector<string> findPath(vector<vector<int>> &maze, int n) //first function
{
    vector<string> ans; //creating ans vector for storing possible string of path.

    if (maze[0][0] == 0 or maze[n - 1][n - 1] == 0) //checking whether source or destination is itself 0 or not if 0 then simply return empty answer because, we dont have either starting position or ending position.
        return ans;

    vector<vector<int>> visited = maze;
    // Creating 2D visited vector to check index is visited or not.
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            visited[i][j] = 0; //Initializing visited vector by 0 i.e 0 -> not visited.
        }
    }

    string path = ""; //to store current path.
    int srcX = 0, srcY = 0; //source x and y.
    solve(maze, n, srcX, srcY, visited, ans, path); //calling solve function.
    sort(ans.begin(), ans.end()); //sorting answer to get in lexicographically order.
    return ans; //returning ans 2d vector.
}