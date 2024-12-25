//GFG.
//Matrix chain multiplication.
//Here is detail approach.
//see suppose we have four alphabets..A B C D.
//how you are going to multiply it. if someone told u to do this.
//then it will be (AB)(CD)  or A(BCD) or (ABC)(D). there are teh compbination.
//and we have to figure out. number of minimum multiplcation among all possible ways.

 //Approach 1:using recursive approach. TC - exonential Sc-o(N*N) + O(N-stack space).
int solve(int i, int j, vector<int>&arr){
    if(i==j) return 0;
    
    int minSteps = INT_MAX;
    for(int k=i; k<j; k++){ //why k is less than j i.e j-1 because..in second part after validating k less than j.
    //we have to call function for k+1,j.

        int steps = (arr[i-1] * arr[k] * arr[j]) + solve(i,k,arr) + solve(k+1,j,arr); //multiplication for current block(i,j,k)
        ///and loop for left part and right part.
        minSteps = min(steps, minSteps);
    }
    
    return minSteps;
}



//Approach 2: memorization. Tc-O(N*N*N) SC-O(N*N + N).
int matrixMultiplication(vector<int> &arr) {
    int i=1, j=arr.size()-1;
    return solve(i,j,arr);
}

    int solve(int i, int j, vector<int>&arr, vector<vector<int>>&dp){
    if(i==j) return 0;
    
    if(dp[i][j] != -1) return dp[i][j];
    
    int minSteps = INT_MAX;
    for(int k=i; k<j; k++){
        
        int steps = (arr[i-1] * arr[k] * arr[j]) + solve(i,k,arr,dp) + solve(k+1,j,arr,dp);
        minSteps = min(steps, minSteps);
    }
    
    return dp[i][j]=minSteps;
}

int matrixMultiplication(vector<int> &arr) {
    int n=arr.size(), i=1, j=arr.size()-1;
    
    vector<vector<int>>dp(n,vector<int>(n,-1));
    return solve(i,j,arr,dp);
}


//Approach 3: Using tabulation. TC-O(N*N*N) SC-O(N*N)
int matrixMultiplication(vector<int> &arr) {
    int n=arr.size();
    
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    
    // for(int i=1; i<n; i++) dp[i][i]=0; //optional..as we already maked all positions as 0.
    
    for(int i=n-1; i>=1; i--){
        for(int j=i+1; j<=n-1; j++){
            int minSteps = INT_MAX;
            
                for(int k=i; k<j; k++){
                
                int steps = (arr[i-1] * arr[k] * arr[j]) + dp[i][k] + dp[k+1][j];
                minSteps = min(steps, minSteps);
            }
            
            dp[i][j] =  minSteps;
        }
    }
    
    return dp[1][n-1];
}