//Code studio.
//Similar like 8th question, just addition of is safe function..which checks..current row col has value -1 or not.
//because in given grid there are values either 0 or -1. -1 shows blcoker to travel.

// Approach 1: Using Recursion. TC-O(2^n)
bool isSafe(int row, int col, vector< vector< int> > &mat){

    if(row>=0 && col>=0 && mat[row][col] != -1)
        return true;
    
    return false;
}

int solve(int row, int col, vector< vector< int> > &mat){

    if(row==0 && col==0) return 1;

    if(!isSafe(row,col,mat)) return 0;

    
    //move up.
    int up = solve(row-1,col,mat);

    //move left.
    int left = solve(row,col-1,mat);

    return (up+left);
}

int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    
    return solve(n-1,m-1,mat);
}


//Approach 2: Optimised Approach. Using Memorization TC-O(N*M) SC-O(N*M + pathLength(n-1+m-1))
int mod = 1e9+7;
bool isSafe(int row, int col, vector< vector< int> > &mat){

    if(row>=0 && col>=0 && mat[row][col] != -1)
        return true;
    
    return false;
}

int solve(int row, int col, vector< vector< int> > &mat, 
    vector<vector<int>>&dp){

    if(row==0 && col==0) return 1;

    if(!isSafe(row,col,mat)) return 0;

    if(dp[row][col] != -1) return dp[row][col];
    
    //move up.
    int up = solve(row-1,col,mat,dp);

    //move left.
    int left = solve(row,col-1,mat,dp);

    return dp[row][col] = (up+left)%mod;
}

int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    vector<vector<int>>dp(n,vector<int>(m,-1));
    return solve(n-1,m-1,mat,dp);
}


//Approach 3: Using Tabulation. TC-O(N*M) SC-O(N*M)
class Solution {
  public:
  
    int uniquePaths(vector<vector<int>> &grid) {
      
        
        int n=grid.size(), m=grid[0].size();
        
        if(n==1 and m==1 and grid[0][0]==1)
            return 0;
            
        vector<vector<int>>dp(n,vector<int>(m,0)); //dp array.
        
        
        for(int row=0; row<n; row++){
            for(int col=0; col<m; col++){
                
                if(grid[row][col] == 1) dp[row][col]=0;
                
                else if(row==0 and col==0) dp[row][col] = 1;
                
                else{
                
                    if(row>0) dp[row][col] += dp[row-1][col];
                    if(col>0) dp[row][col] += dp[row][col-1];
                
                }
            }
        }
        
        
        return dp[n-1][m-1];
    }
};


//Approach 4: Using tabulation without memeory space.
class Solution {
  public:
  

    int uniquePaths(vector<vector<int>> &grid) {
      
        
        int n=grid.size(), m=grid[0].size();
        
        if(n==1 and m==1 and grid[0][0]==1)
            return 0;
            
        vector<int>prev(m,0);
        
        prev[0] = 1;
        
        for(int row=0; row<n; row++){
            vector<int>curr(m,0);
            for(int col=0; col<m; col++){
                
                if(grid[row][col] == 1) curr[col]=0; //or continue
                
                else if(row==0 and col==0) curr[col] = 1;
                
                else{
                    
                    int up = 0, left = 0;
                    if(row>0) up = prev[col];
                    if(col>0) left = curr[col-1];
                    
                    curr[col] += up + left;
                }
                
            }
            
            prev = curr;
        }
        
        
        return prev[m-1];
    }
};