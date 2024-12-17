//GFG.

//best time to buy and sell stock question.
int maximumProfit(vector<int> &prices) {
    int profit = 0, mini = prices[0]; //storing first stoack price is as minimum..and considering we have buy it.
    
    for(int i=1; i<prices.size(); i++){ //now iterating from first index.
        
        int cost = prices[i] - mini; //calculating new profit or cost.
        
        profit = max(profit, cost); //store max profit.
        
        mini = min(mini, prices[i]); //update mini.
    }
    
    return profit; //finally return profit.
}


//Using Dp. Max one trnscation is possible. 
int solve(int i, int buy, vector<int> &prices, int &n, vector<vector<int>>&dp, int &maxAns,
    int transCnt){

    if(i==n || transCnt == 0) return 0;
    
    if(dp[i][buy] != -1){
        return dp[i][buy];
    }
    
    if(buy){
        
        //buy now
        int p1 = solve(i+1, !buy, prices, n, dp, maxAns, transCnt) - prices[i];
        
        //don't buy
        int p2 = solve(i+1, buy, prices, n, dp, maxAns, transCnt);
        
        dp[i][buy] = max(p1, p2);
        return max(maxAns, dp[i][buy]);
    }
    else{
        
        //sell now.
        int p1 = prices[i] + solve(i+1, !buy, prices, n, dp, maxAns, transCnt-1);
        
        //don't sell now.
        int p2 = solve(i+1, buy, prices, n, dp, maxAns, transCnt);
        
        dp[i][buy] = max(p1, p2);
        return max(maxAns, dp[i][buy]);
    }
}  

    int maximumProfit(vector<int> &prices) {
    
    int buy=1, n = prices.size(), maxAns=0, transCnt=1;
    vector<vector<int>>dp(n, vector<int>(2,-1));
    return max( maxAns,solve(0 , buy, prices,  n, dp, maxAns, transCnt) );
}


//Approach 2: most optimized. using space optimization.
int maximumProfit(vector<int>&price){
            
    int i=0, n=price.size(), transCnt = 1, buyStatus = 1;
    
    vector<vector<int>>prev(2, vector<int>(2,0)); //creating 2d vector for prev and current.
    vector<vector<int>>curr(2, vector<int>(2,0));
    //we have elminate field for n..because that is not required. we will consider only this prev and curr
    //previous row and current row. whole n is not required.
    
    
    for(int i=n-1; i>=0; i--){
        for(buyStatus=0; buyStatus<=1; buyStatus++){
            
            if(buyStatus){
    
                //buy
                int p1 = prev[!buyStatus][transCnt] - price[i];
                
                //not buy
                int p2 = prev[buyStatus][transCnt];
                
                curr[buyStatus][transCnt] = max(p1, p2);
            }
            else{
                
                //sell
                int p1 = price[i] + prev[!buyStatus][transCnt-1];
                
                //not sell
                int p2 = prev[buyStatus][transCnt];
                
                curr[buyStatus][transCnt] = max(p1, p2);
            }
            
            
            prev = curr;
        }
    }
    
    //this indexes will be the last index of every loop..so just return that.
    //buyCnt will loop till 1 and transCnt will loop till 2.
    return prev[1][1];
}