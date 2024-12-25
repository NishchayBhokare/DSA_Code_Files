//GFG.
// Partition Array for Maximum Sum

//Approach 1:using memorization. It's similar approach like previous problem. solving question using front partition.
int solve(int i, int n, vector<int>&arr, int &k, vector<int>&dp){

    if(i==n) return 0;
    
    if(dp[i] != -1) return dp[i];
    
    int maxSum = 0, maxVal = INT_MIN;
    for(int ind=i; ind<min(n,i+k); ind++){

        maxVal = max(maxVal,arr[ind]);
        
        int sum = ((ind-i+1) * maxVal) + solve(ind+1, n, arr, k, dp); //calculate maximum sum for previous k elements + next partition.
        maxSum = max(sum, maxSum); 
    }

    return dp[i] = maxSum;
}



int solve(int n, int k, vector<int>& arr){
    
    vector<int>dp(n+1,-1);

    int i=0;
    return solve(i,n,arr,k,dp);
}


//Approach 2: Using Tabulation.
int solve(int n, int k, vector<int>& arr){

vector<int>dp(n+1,0);

for(int i=n-1; i>=0; i--){
    
    int maxSum = 0, maxVal = INT_MIN;
    for(int ind=i; ind<min(n,i+k); ind++){

        maxVal = max(maxVal,arr[ind]);
        
        int sum = ((ind-i+1) * maxVal) + dp[ind+1];
        maxSum = max(sum, maxSum); 
    }

    dp[i] = maxSum;
}

    return dp[0];
}