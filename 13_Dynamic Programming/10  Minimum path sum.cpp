//code studio.

//Using Recursion.
int solve(int row, int col, vector<vector<int>> &grid){

    if(row==0 && col==0) return grid[row][col];

    int up = INT_MAX, left = INT_MAX;
    
    //go to up.
    if(row-1 >= 0) up = solve(row-1,col,grid);

    //go to left.
    if(col-1 >=0) left = solve(row,col-1,grid);

    int cost = grid[row][col] + min(up,left);
    return cost;
}

int minSumPath(vector<vector<int>> &grid) {
    
    int n=grid.size(), m=grid[0].size();

    return solve(n-1,m-1,grid);
}


//Using Momorization.
int solve(int row, int col, vector<vector<int>> &grid, 
    vector<vector<int>>&dp){

    if(row==0 && col==0) return grid[row][col];

    if(dp[row][col] != -1)
        return dp[row][col];

    int up = INT_MAX, left = INT_MAX;
    
    //go to up.
    if(row-1 >=0) up = solve(row-1,col,grid,dp);

    //go to left.
    if(col-1 >=0) left = solve(row,col-1,grid,dp);


    return dp[row][col] = grid[row][col] + min(up,left);
}

int minSumPath(vector<vector<int>> &grid) {
    
    int n=grid.size(), m=grid[0].size();
    vector<vector<int>>dp(n,vector<int>(m,-1));

    return solve(n-1,m-1,grid,dp);
}

