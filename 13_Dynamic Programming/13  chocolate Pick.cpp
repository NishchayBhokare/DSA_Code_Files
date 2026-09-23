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


//Approach 2: using Memorization. TC-O(N*M*M*9) SC-O(N*M*M) + N(recursion stack space.)
int solve(int row, int aCol, int bCol, vector<vector<int>>& grid, vector<vector<vector<int>>>&dp, int n, int m){
        
        if(aCol<0 || aCol>=m || bCol<0 || bCol>=m) return 0; //return -1e8. so that this path will not consider.
        
        if(row == n-1){
            //if both are on same chocolate then return only that value.
            if(aCol == bCol){
                return grid[row][aCol];
            }
            
            //if on different chocolate then add it and then return.
            return (grid[row][aCol] + grid[row][bCol]);
        }
        
        if(dp[row][aCol][bCol] != -1){
            return dp[row][aCol][bCol];
        }
        
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


//Approach 3: Using Tabulation. TC-O(N*M*M*9) SC-O(N*M*M) 
int maxChocolate(vector<vector<int>>& grid) {
        // code here
        
        int n = grid.size(), m=grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        
        int row=0, c1=0, c2=m-1;
        
        
        return solve(row,c1,c2,grid,dp,n,m);
    }
  
  
    int maxChocolate(vector<vector<int>>& grid) {
   
        int n = grid.size(), m=grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,0)));
        
        
        for(int i=0; i<m; i++){
            for(int j=0; j<m; j++){
              if(i==j)  dp[n-1][i][j] = grid[n-1][i];
              else
                 dp[n-1][i][j] = grid[n-1][i] + grid[n-1][j];
            }
        }
        
        //Express all states in for loop, if there are three states, then 3 for loops.
        for(int row=n-2; row>=0; row--){
            
            for(int c1=0; c1<m; c1++){
                
                for(int c2=0; c2<m; c2++){
                    
                    int maxChocos = 0;
                    
                    for(int i=-1; i<=1; i++){
                        for(int j=-1; j<=1; j++){
                            
                          int nc1=c1+i, nc2=c2+j;
                          
                          if(nc1<0 or nc1>=m or nc2<0 or nc2>=m) continue;
                          
                          int currChocos = dp[row+1][nc1][nc2];
                          maxChocos = max(maxChocos,currChocos);
                        }
                    }
                
                    if(c1 == c2)
                        maxChocos += grid[row][c1];
                    
                    else
                        maxChocos += grid[row][c1] + grid[row][c2];
                        
                    dp[row][c1][c2] = maxChocos;
                }
            }
        }

        
        return dp[0][0][m-1];
    }
  
    
//Approach 4: Using space optimization. TC-O(N*M*M) SC-O(N*M)
// --> we can optimize it to 3d->2d array.
int maxChocolate(vector<vector<int>>& grid) {
   
    int n = grid.size(), m=grid[0].size();
    vector<vector<int>>next(m,vector<int>(m,0));
    
    
    for(int i=0; i<m; i++){
        for(int j=0; j<m; j++){
            if(i==j)  next[i][j] = grid[n-1][i];
            else
                next[i][j] = grid[n-1][i] + grid[n-1][j];
        }
    }
    
    
    
    for(int row=n-2; row>=0; row--){
        
        vector<vector<int>>curr(m,vector<int>(m,0));
        
        for(int c1=0; c1<m; c1++){
            
            for(int c2=0; c2<m; c2++){
                
                int maxChocos = 0;
                
                for(int i=-1; i<=1; i++){
                    for(int j=-1; j<=1; j++){
                        
                        int nc1=c1+i, nc2=c2+j;
                        
                        if(nc1<0 or nc1>=m or nc2<0 or nc2>=m) continue;
                        
                        int currChocos = next[nc1][nc2];
                        maxChocos = max(maxChocos,currChocos);
                    }
                }
            
                if(c1 == c2)
                    maxChocos += grid[row][c1];
                
                else
                    maxChocos += grid[row][c1] + grid[row][c2];
                    
                curr[c1][c2] = maxChocos;
            }
        }
        
        next = curr;
    }

    
    return next[0][m-1];
}