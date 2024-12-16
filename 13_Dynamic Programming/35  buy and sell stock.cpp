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