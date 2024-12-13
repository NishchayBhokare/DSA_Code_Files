//GFG. 
//for memorization..just start from destination to source...and store number of paths can be possible for every row and col.
//if already this path is calculated for current row and col..then return that path count.
//In question they told us to move right and down..but as we moving from destination to source..so we're moving
//up and left.

//Approach 1: Using Memorization Top down approach.
int solve(vector<vector<int>>&dp,int row, int col, int m, int n){

	if(row == 0 && col == 0){
		return 1;
	}

	if(row<0 || col<0)
		return 0;
	
	if(dp[row][col] != -1) //if already calculated return it.
		return dp[row][col];

	//go to up.
	int up = solve(dp,row-1,col,m,n);

	//go to left.
	int left = solve(dp,row,col-1,m,n);

	return dp[row][col] = up+left;
}
    
int NumberOfPath(int m, int n)
{
    int row = m-1, col = n-1;
    vector<vector<int>>dp(m,vector<int>(n,-1));
    return solve(dp,row,col,m,n);
}


//Approach 2:using tabulation.
//Tabulation.
int uniquePaths(int m, int n) {

	vector<vector<int>>dp(m,vector<int>(n,0));
	
	for(int row = 0; row<m; row++){
		for(int col=0; col<n; col++){

			if(row==0 && col==0) dp[row][col]=1	;
			else{
				int up = 0, left = 0;
				if(row>0)up = dp[row-1][col];
				if(col>0) left = dp[row][col-1];

				dp[row][col] = up+left;
			}	
		}
	}

	return dp[m-1][n-1];
}


//Approach 3:Using Recursion.
int solve(int row, int col, int m, int n){

	if(row == 0 && col == 0){
		return 1;
	}

	if(row<0 || col<0)
		return 0;

	//go to up.
	int left = solve(row-1,col,m,n);

	//go to left.
	int right = solve(row,col-1,m,n);

	return (left+right);
}

int NumberOfPath(int m, int n) {
	int row = m-1, col = n-1;
	return solve(row,col,m,n);
}
