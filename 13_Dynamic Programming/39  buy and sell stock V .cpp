//GFG
//Similar to question two..buy and sell stock just addition of condition..cooldown..i.e we cannot
// buy immediately next day, instead we can buy after one day of selling stock.

//Approach 1: using recurison.
long long solve(int i, int buyStatus, vector<long long>&prices, int &n){
    
    if(i>=n) return 0;
    
    if(buyStatus){
        
        //buy stock.
        int p1 = solve(i+1, !buyStatus, prices, n) - prices[i];
        
        //don't buy
        int p2 = solve(i+1, buyStatus, prices, n);
        
        return max(p1, p2);
    }
    else{
        
        //sell stock.
        int p1 = prices[i] + solve(i+2, !buyStatus, prices, n); //this is the condition.
        
        //don't sell.
        int p2 = solve(i+1, buyStatus, prices, n);
        
        return max(p1, p2);
    }
}

long long maximumProfit(vector<long long>&prices, int n) {
    
    long long i=0, buyStatus = 1;
    return solve(i, buyStatus, prices, n);
}


// Approach 2:Using memorization.
long long solve(int i, int buyStatus, vector<long long>&prices, int &n, 
        vector<vector<int>>&dp){
    
    if(i>=n) return 0;
    
    if(dp[i][buyStatus] != -1) return dp[i][buyStatus];
    
    if(buyStatus){
        
        //buy stock.
        int p1 = solve(i+1, !buyStatus, prices, n, dp) - prices[i];
        
        //don't buy
        int p2 = solve(i+1, buyStatus, prices, n, dp);
        
        return dp[i][buyStatus] = max(p1, p2);
    }
    else{
        
        //sell stock.
        int p1 = prices[i] + solve(i+2, !buyStatus, prices, n, dp);
        
        //don't sell.
        int p2 = solve(i+1, buyStatus, prices, n, dp);
        
        return dp[i][buyStatus] = max(p1, p2);
    }
}

long long maximumProfit(vector<long long>&prices, int n) {
    
    long long i=0, buyStatus = 1;
    vector<vector<int>>dp(n,vector<int>(2,-1));
    return solve(i, buyStatus, prices, n, dp);
}


//Approach 3: using tabulation.
long long maximumProfit(vector<long long>&prices, int n) {
    
    long long i=0, buyStatus = 1;
    vector<vector<int>>dp(n+2,vector<int>(2,0));
    
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
                int p1 = prices[i] + dp[i+2][!buyStatus];
                
                //don't sell.
                int p2 = dp[i+1][buyStatus];
                
                dp[i][buyStatus] = max(p1, p2);
            }
            
        }
            
    }
    
    return dp[0][1];
}
    
    
//Approach 4: Using space optimization.
long long maximumProfit(vector<long long>&prices, int n) {
    
    long long i=0, buyStatus = 1;
    
    vector<int>prevOfPrev(2,0); //required prevofprev..when we are accessing data for next of next day.
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
                int p1 = prices[i] + prevOfPrev[!buyStatus];
                
                //don't sell.
                int p2 = prev[buyStatus];
                
                curr[buyStatus] = max(p1, p2);
            }
            
            prevOfPrev=prev;
            prev = curr;
        }
            
    }
    
    return prev[1];
}