//Code Studio.
//logic is for all previous question...we have applied recursion and dp from destination node.
//but here destiantion can be multiple..that is last row is itself destination..so for this..we will
//start from source node..because it is single.

//Approach 1: TC-O(N*N) SC-O(N+N*N(dp)) Using Memorization.
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


//Approach 2: TC-O(N*M) SC-O(N*M)
class Solution {
  public:
    int minPathSum(vector<vector<int>>& triangle) {
        int n = triangle.size(); 
        vector<vector<int>>dp(n,vector<int>(n,0));
    	
    	
    	for(int i=0; i<n; i++){
    	   dp[n-1][i] = triangle[n-1][i];
    	}
    	      
    	for(int row=n-2; row>=0; row--){
	        for(int col=row; col>=0; col--){
                    
                int down = INT_MAX, diagonal = INT_MAX;
                
                down = dp[row+1][col];
                diagonal =  dp[row+1][col+1];
                
                dp[row][col] = triangle[row][col] + min(down,diagonal);
	        }
    	}
    	return dp[0][0];
    }
};


//Approach 3: Tabulation, space optimization. TC-O(N*M) SC-O(N)
class Solution {
  public:
    int minPathSum(vector<vector<int>>& triangle) {
        int n = triangle.size(); 

        vector<int>front(n,0);
        
    	for(int i=0; i<n; i++){
    	   front[i] = triangle[n-1][i];
    	}
    	      
    	for(int row=n-2; row>=0; row--){
    	    
    	    vector<int>curr(row+1,0);
    	    
	        for(int col=row; col>=0; col--){
                    
                int down = INT_MAX, diagonal = INT_MAX;
                
                down = front[col];
                diagonal =  front[col+1];
                
                curr[col] = triangle[row][col] + min(down,diagonal);
	        }
	        
	        front = curr;
    	}
    	
    	return front[0];
    }
};


//Approach 4: TC-O(2^N) SC-O(N) Using Recursion.
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
