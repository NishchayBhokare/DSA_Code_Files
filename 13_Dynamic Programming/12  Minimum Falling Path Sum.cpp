//Code studio.
//the path on which we can traverse is, left bottom direction diagonal..right bottom direction diagonal and normal diagonal

//Approach 1: Memorization. from last row to first row..as none of the node is source node and detination node.
//TC-O(N*M) SC-O(N)
int solve(int row, int col, vector<vector<int>> &vec,
    vector<vector<int>> &dp, int n){

    if(col<0 || col>=n) return INT_MAX;

    if(row == 0) return vec[row][col];

    if(dp[row][col] != -1) return dp[row][col];


    int up=solve(row-1,col,vec,dp,n);
    
    int leftD=solve(row-1,col-1,vec,dp,n);

    int rightD=solve(row-1,col+1,vec,dp,n);

    return dp[row][col] = vec[row][col] + min(up,min(leftD,rightD));
}

int minFallingPathSum(vector<vector<int>> &vec, int n) {
    int minSum = INT_MAX;
    int row=n-1;
    
    vector<vector<int>>dp(n,vector<int>(n,-1));

    for(int col=0; col<n; col++){
        int pathSum = solve(row,col,vec,dp,n);
        minSum = min(minSum,pathSum);
    }
    return minSum;
}


//Apporhac 2: using tabulation.
//TC-O(N*M) SC-O(N)
int minFallingPathSum(vector<vector<int>> &vec, int n) {
    int minSum = INT_MAX;
    vector<vector<int>>dp(n,vector<int>(n,-1));

    for(int i=0; i<n; i++)
        dp[0][i]=vec[0][i];

    for(int row=1; row<n; row++){
        for(int col=0; col<n; col++){ //very simple via tabulatiom.

            int up=INT_MAX, leftD=INT_MAX, rightD=INT_MAX;

            up=dp[row-1][col];
            
            if(col-1>=0) leftD=dp[row-1][col-1];

            if(col+1<n) rightD=dp[row-1][col+1];

            dp[row][col] = vec[row][col] + min(up,min(leftD,rightD));
        }
    }

    for(auto i:dp[n-1])
        minSum = min(i,minSum);

    return minSum;
}



//This belowe approaches are from start row to end row..

// //Using Recursion.
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