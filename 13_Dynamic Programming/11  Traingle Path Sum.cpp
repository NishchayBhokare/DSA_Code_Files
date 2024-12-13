//Code Studio.
//logic is for all previous question...we have applied recursion and dp from destination node.
//but here destiantion can be multiple..that is last row is itself destination..so for this..we will
//start from source node..because it is single.


//TC-O(2^N) SC-O(N) Using Recursion.
int solve(int row, int col, vector<vector<int>>& triangle, int n){

	if(row==n-1) return triangle[row][col];

	//go down.
	int down = solve(row+1,col,triangle,n);

	//go diagonal down.
	int diagonal = solve(row+1,col+1,triangle,n);

	int cost = triangle[row][col] + min(down,diagonal);

	return cost;
}

int minimumPathSum(vector<vector<int>>& triangle, int n){
	return solve(0,0,triangle,n);
}


//TC-O(N*N) SC-O(N) Using Memorization.
int solve(int row, int col, vector<vector<int>>& triangle,
	vector<vector<int>>&dp, int n){

	if(row==n-1) return triangle[row][col];

	if(dp[row][col] != -1) return dp[row][col];

	//go down.
	int down = solve(row+1,col,triangle,dp,n);

	//go diagonal down.
	int diagonal = solve(row+1,col+1,triangle,dp,n);

	return dp[row][col] = triangle[row][col] + min(down,diagonal);
}

int minimumPathSum(vector<vector<int>>& triangle, int n){
	vector<vector<int>>dp(n,vector<int>(n,-1));
	return solve(0,0,triangle,dp,n);
}