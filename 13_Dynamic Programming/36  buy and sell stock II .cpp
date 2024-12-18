//GFG.
//Unlimited transaction.
//Approach 1: iterative approach. normal iterative appraoch.
int maximumProfit(vector<int> &prices) {
    
    int profit = 0, buyPrice = prices[0], n=prices.size(); //considering we buy first element.
    for(int i=1; i<n; i++){
        
        if(prices[i] < prices[i-1]){ //if current price is lesser than previous price. then this is time
        //to sell stock on previous price.
            
            profit += prices[i-1] - buyPrice; //so consider profit till previous price by substracting buyprice.
            
            buyPrice = prices[i]; //now again buy on current price.
        }
    }
    
    profit += prices[n-1] - buyPrice; //once loop over..we need to sell our last buy..so sell it on n-1 price.
    
    return profit; 
}
    

//Approach 2: recursive approach.
//logic is we will maintain two variables one is index and another is status of buy. it will be either 0, 1.
int solve(int i, int buy, vector<int> &prices, int &n){
    
    if(i==n) return 0;
    
    if(buy){ //if it's one ..then we can buy or not buy stock.
        
        //buy now
        int p1 = solve(i+1, !buy, prices, n) - prices[i]; //if we buy..then make sure..substract buying price from 
        //whatver answer we're getting.
        
        //don't buy
        int p2 = solve(i+1, buy, prices, n); //if don't want to buy..then simply call function for next index.
        
        return max(p1, p2); //return max profit of both.
    }
    else{ //if it's zero..then we can sell or not sell stock.
        
        //sell now.
        int p1 = prices[i] + solve(i+1, !buy, prices, n); //similarly..now here..make sure to add selling price to the next index answer.
        
        //don't sell now.
        int p2 = solve(i+1, buy, prices, n);
        
        return max(p1, p2);
    }
}  

int maximumProfit(vector<int> &prices) {
    
    int buy=1, n = prices.size();
    return solve(0 , buy, prices,  n);

}
    
    
// Approach 3: using Memorization.. just uses of dp.
 int solve(int i, int buy, vector<int> &prices, int &n, vector<vector<int>>&dp){
    
    if(i==n) return 0;
    
    if(dp[i][buy] != -1){
        return dp[i][buy];
    }
    
    if(buy){
        
        //buy now
        int p1 = solve(i+1, !buy, prices, n, dp) - prices[i];
        
        //don't buy
        int p2 = solve(i+1, buy, prices, n, dp);
        
        return dp[i][buy] = max(p1, p2);
    }
    else{
        
        //sell now.
        int p1 = prices[i] + solve(i+1, !buy, prices, n, dp);
        
        //don't sell now.
        int p2 = solve(i+1, buy, prices, n, dp);
        
        return dp[i][buy] = max(p1, p2);
    }
}  

int maximumProfit(vector<int> &prices) {
    
    int buy=1, n = prices.size();
    vector<vector<int>>dp(n, vector<int>(2,-1));
    return solve(0 , buy, prices,  n, dp);
}
    


//Approach 4: using space optimization. Tc-O(N*2);
int maximumProfit(vector<int> &prices) {
    
    int buy=1, n = prices.size();
    vector<vector<int>>dp(n+1, vector<int>(2,-1)); //create n+1 array size.
    
    
    dp[n][1]=dp[n][0]=0; //base condition.
    
    for(int i=n-1; i>=0; i--){ //now looping from back.
        
        for(int buy=0; buy<=1; buy++){
            
            if(buy){
                
                //buy now
                int p1 = dp[i+1][!buy] - prices[i]; //instead of !buy..we can simply right 0 also.
                
                //don't buy
                int p2 = dp[i+1][buy];
                
                dp[i][buy] = max(p1, p2);
            }
            else{  
                
                //sell now.
                int p1 = prices[i] + dp[i+1][!buy];
                
                //don't sell now.
                int p2 = dp[i+1][buy];
                
                dp[i][buy] = max(p1, p2);
            }  
                        
        }    
    }
    
    return dp[0][1];      
}


//Approach 5: Using space optimization.
int maximumProfit(vector<int> &prices) {

int buy=1, n = prices.size();

vector<int>prev(2,0), curr(2,0); //using two arrays of size 2.


prev[1]=prev[0]=0;

for(int i=n-1; i>=0; i--){
    
    for(int buy=0; buy<=1; buy++){
        
        if(buy){
            
            //buy now
            int p1 = prev[!buy] - prices[i]; //instead of !buy..we can simply right 0 also.
            
            //don't buy
            int p2 = prev[buy];
            
            curr[buy] = max(p1, p2);
        }
        else{  
            
            //sell now.
            int p1 = prices[i] + prev[!buy];
            
            //don't sell now.
            int p2 = prev[buy];
            
            curr[buy] = max(p1, p2);
        } 
        
    }    
    prev = curr;
}

return prev[1];      
}