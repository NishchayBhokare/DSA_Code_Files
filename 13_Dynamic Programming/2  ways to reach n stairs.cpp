//GFG.
//It is just similar like nth fibonacii number.
//we have to calculate ways to reach nth stairs..

APPROACH 1: using Memorization. 
// TC-O(N) SC-O(N)

int solve(int n, vector<int>&dp){
    
    if(n <= 1){
        return 1;
    }
        
    if(dp[n] != -1)
        return dp[n];
    
    return dp[n] = solve(n-1, dp) + solve(n-2, dp);
}

int countWays(int n) {
    
    vector<int>dp(n+1,-1);
    
    dp[n] = solve(n,dp);
    
    return dp[n];
}




APPROACH 2: using tabulation.
// TC-O(N) SC-O(N)

int countWays(int n) {
    
    vector<int>dp(n+1,-1);
    
    dp[0] = dp[1] = 1;
    
    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    
    return dp[n];
}




APPROACH 3: using space optimization.
// TC-O(N) SC-O(1)
int countWays(int n) {
    
    int prevOfPrev = 1;
    int prev = 1;
    
    for(int i=2; i<=n; i++){
        
        int curr = prev + prevOfPrev;
        
        prevOfPrev = prev;
        prev = curr;
    }
    
    return prev;
}