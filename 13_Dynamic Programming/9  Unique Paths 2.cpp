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

