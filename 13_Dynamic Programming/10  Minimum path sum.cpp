//Code studio.

// Approach 1: TC-O(N*M) SC-O(N*M)+O(N+M) Using Momorization.
int solve(int row, int col, vector<vector<int>> &grid, 
    vector<vector<int>>&dp){

    if(row==0 && col==0) return grid[row][col];

    if(dp[row][col] != -1)
        return dp[row][col];

    int up = INT_MAX, left = INT_MAX;
    
    //go to up.
    if(row>0) up = solve(row-1,col,grid,dp);

    //go to left.
    if(col>0) left = solve(row,col-1,grid,dp);


    return dp[row][col] = grid[row][col] + min(up,left);
}

int minSumPath(vector<vector<int>> &grid) {
    
    int n=grid.size(), m=grid[0].size();
    vector<vector<int>>dp(n,vector<int>(m,-1));

    return solve(n-1,m-1,grid,dp);
}


//Approach 2: Tabulation. TC-O(N*M) SC-O(N*M)
int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.

    int n = grid.size(), m=grid[0].size();
    vector<vector<int>>dp(n, vector<int>(m,0));

    for(int row=0; row<n; row++){

        for(int col=0; col<m; col++){

            if(row==0 and col==0) 
                dp[0][0] = grid[0][0];
            
            else{

                int up = INT_MAX, left = INT_MAX;

                if(row>0) up = dp[row-1][col];
                if(col>0) left = dp[row][col-1];

                dp[row][col] = grid[row][col] + min(up,left);
            }
        }
    }

    return dp[n-1][m-1];
}


//Approach 3: Space Optimization. TC-O(N*M) SC-O(M+M).
int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.

    int n = grid.size(), m=grid[0].size();
    vector<int>prev(m,0);

    for(int row=0; row<n; row++){

        vector<int>curr(m,0);
        for(int col=0; col<m; col++){

            if(row==0 and col==0) 
                curr[0] = grid[0][0];
            
            else{

                int up = INT_MAX, left = INT_MAX;

                if(row>0) up = prev[col];
                if(col>0) left = curr[col-1];

                curr[col] = grid[row][col] + min(up,left);
            }
        }

        prev = curr;
    }

    return prev[m-1];
}



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
