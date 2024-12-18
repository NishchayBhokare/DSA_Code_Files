//GFG. 
//Just addition of trasnaction fee k. so  just decrement profit by k on every transaction.

//Approach 1:recursive approach.
long long solve(int i, int buyStatus, vector<int>&prices, int &n, int &k){

    if(i==n) return 0;
    
    if(buyStatus){
        
        //buy stock.
        int p1 = solve(i+1, !buyStatus, prices, n, k) - prices[i];
        
        //don't buy
        int p2 = solve(i+1, buyStatus, prices, n, k);
        
        return max(p1, p2);
    }
    else{
        
        //sell stock.
        int p1 = prices[i] - k + solve(i+1, !buyStatus, prices, n, k) ; //this is the condition when we cutting transaction fee.
        
        //don't sell.
        int p2 = solve(i+1, buyStatus, prices, n, k);
        
        return max(p1, p2);
    }
}

long long maximumProfit(vector<int>& prices, int k) {
    int i=0, buyStatus = 1, n=prices.size();
    return solve(i, buyStatus, prices, n, k);
}





// Approach 2:Using memorization.
long long solve(int i, int buyStatus, vector<int>&prices, int &n, 
        vector<vector<int>>&dp, int &k){
    
    if(i==n) return 0;
    
    if(dp[i][buyStatus] != -1) return dp[i][buyStatus];
    
    if(buyStatus){
        
        //buy stock.
        int p1 = solve(i+1, !buyStatus, prices, n, dp, k) - prices[i];
        
        //don't buy
        int p2 = solve(i+1, buyStatus, prices, n, dp, k);
        
        return dp[i][buyStatus] = max(p1, p2);
    }
    else{
        
        //sell stock.
        int p1 = prices[i] - k + solve(i+1, !buyStatus, prices, n, dp, k);
        
        //don't sell.
        int p2 = solve(i+1, buyStatus, prices, n, dp, k);
        
        return dp[i][buyStatus] = max(p1, p2);
    }
}

long long maximumProfit(vector<int>&prices, int k) {
    
    int i=0, buyStatus = 1, n=prices.size();
    vector<vector<int>>dp(n,vector<int>(2,-1));
    return solve(i, buyStatus, prices, n, dp, k);
}




// Approach 3: using tabulation.
    long long maximumProfit(vector<int>&prices, int k) {
    
    int i=0, buyStatus = 1, n=prices.size();
    vector<vector<int>>dp(n+1,vector<int>(2,0));
    
    for(int i=n-1; i>=0; i--){
        
        for(int buyStatus=0; buyStatus<=1; buyStatus++){
            
                if(buyStatus){
                //buy stock.
                int p1 = dp[i+1][!buyStatus] - prices[i];
                
                //don't buy
                int p2 = dp[i+1][buyStatus];
                
                dp[i][buyStatus] = max(p1, p2);
            }
            else{
                
                //sell stock.
                int p1 = prices[i] - k + dp[i+1][!buyStatus];
                
                //don't sell.
                int p2 = dp[i+1][buyStatus];
                
                dp[i][buyStatus] = max(p1, p2);
            }
            
        }
            
    }
    
    return dp[0][1];
}
    



//Approach 4: space optimization.
    long long maximumProfit(vector<int>&prices, int k) {
    
    int i=0, buyStatus = 1, n=prices.size();
    vector<int>prev(2,0);
    vector<int>curr(2,0);
    
    for(int i=n-1; i>=0; i--){
        
        for(int buyStatus=0; buyStatus<=1; buyStatus++){
            
                if(buyStatus){
                //buy stock.
                int p1 = prev[!buyStatus] - prices[i];
                
                //don't buy
                int p2 = prev[buyStatus];
                
                curr[buyStatus] = max(p1, p2);
            }
            else{
                
                //sell stock.
                int p1 = prices[i] - k + prev[!buyStatus];
                
                //don't sell.
                int p2 = prev[buyStatus];
                
                curr[buyStatus] = max(p1, p2);
            }
            
        }
        prev = curr;    
    }
    
    return prev[1];
}