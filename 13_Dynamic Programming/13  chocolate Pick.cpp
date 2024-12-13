//GFG.
//Logic is we will together move alice and bob. 

//Approach 1: Using Recursion. TC-O(3^n * 3*m 3*m) * 9, SC-O(N).
 int solve(int row, int aCol, int bCol, vector<vector<int>>& grid, int n, int m){
    
    //if any of it get's out of bound..return 0.    
    if(aCol<0 || aCol>=m || bCol<0 || bCol>=m) return 0;
    
    if(row == n-1){
        //if both are on same chocolate then return only that value.
        if(aCol == bCol)
            return grid[row][aCol];
        
        //if on different chocolate then add it and then return.
        return (grid[row][aCol] + grid[row][bCol]);
    }
    
    
    //Explore all paths for alice and bob.
    int maxCount = 0;
    for(int i=-1; i<=1; i++){ //first loop for alice.
        for(int j=-1; j<=1; j++){ //second for bob.
            
            int currCount = solve(row+1, aCol+i, bCol+j, grid, n, m);
            maxCount = max(currCount,maxCount);
        }
    }
    
    
    //before including current values..check whether they both alice and bob
    //stands of same column or not..if yes..then return only one value.
    if(aCol == bCol)
        return (maxCount + grid[row][aCol]);
    
    else //or return both values of alice and bob.
        return (maxCount + grid[row][aCol] + grid[row][bCol]);
    
}

int solve(int n, int m, vector<vector<int>>& grid) {
    
    int row=0, aCol=0, bCol=m-1;
    
    return solve(row, aCol, bCol, grid, n, m);
}


//Approach 2: using Memorization. TC-O(N*M*M) SC-O(N*M*M) + N(recursion stack space.)

int solve(int row, int aCol, int bCol, vector<vector<int>>& grid, vector<vector<vector<int>>>&dp, int n, int m){
    
    if(aCol<0 || aCol>=m || bCol<0 || bCol>=m) return 0;
    
    if(row == n-1){
        //if both are on same chocolate then return only that value.
        if(aCol == bCol)
            return grid[row][aCol];
        
        //if on different chocolate then add it and then return.
        return (grid[row][aCol] + grid[row][bCol]);
    }
    
    if(dp[row][aCol][bCol] != -1){
        return dp[row][aCol][bCol];
    }
    
    //Explore all paths for alice and bob.
    int maxCount = 0;
    for(int i=-1; i<=1; i++){ //first loop for alice.
        for(int j=-1; j<=1; j++){ //second for bob.
            
            int currCount = solve(row+1, aCol+i, bCol+j, grid, dp, n, m);
            maxCount = max(currCount,maxCount);
        }
    }
    
    
    //before including current values..check whether they both alice and bob
    //stands of same column or not..if yes..then return only one value.
    int totalCount;
    if(aCol == bCol)
        totalCount = (maxCount + grid[row][aCol]);
    
    else //or return both values of alice and bob.
        totalCount = (maxCount + grid[row][aCol] + grid[row][bCol]);
    
    //finally return answer after storing into the dp.
    return dp[row][aCol][bCol] = totalCount;
    
}

int solve(int n, int m, vector<vector<int>>& grid) {

    int row=0, aCol=0, bCol=m-1;
    vector<vector<vector<int>>>dp(n, vector<vector<int>>(m,vector<int>(m,-1)) );
    
    return solve(row, aCol, bCol, grid, dp, n, m);
}



//Writing tabulation..but giving wrong answer..will check.
  int solve(int n, int m, vector<vector<int>>& grid) {

        int row=0, aCol=0, bCol=m-1;
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(m,vector<int>(m,0)) );
        
        
        //writing base case.
        for(int i=0; i<m; i++){
            for(int j=0; j<m; j++){
              if(i==j)  dp[0][i][j] = grid[n-1][i];
              else
                 dp[0][i][j] = grid[n-1][i] + grid[n-1][j];
            }
        }
        
        
        for(int row=n-2; row>=0; row--){
            
            
            for(int aCol=0; aCol<m; aCol++){
                for(int bCol=0; bCol<m; bCol++){
                    int maxCount = 0;
                    
                    for(int i=-1; i<=1; i++){ //first loop for alice.
                        for(int j=-1; j<=1; j++){ //second for bob
                        
                             if(aCol+i >=0 && aCol+i<m && bCol+j>=0 && bCol+j<m){
                                 
                                int val = 0;
                                if(aCol == bCol) val = grid[row][bCol];
                                else val = grid[row][aCol] + grid[row][bCol];
                                
                                val+=dp[row+1][aCol+i][bCol+j];
                                
                                maxCount = max(val,maxCount);
                             }
                        }     
                    }
                    
                    //finally return answer after storing into the dp.
                    dp[row][aCol][bCol] = maxCount;
                }
            }
        }
        
        return dp[0][0][m-1];
    }