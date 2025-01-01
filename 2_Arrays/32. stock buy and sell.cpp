//GFG. 

//Approach 1: Simple approach TC-O(N) SC-O(1)
int stockBuySell(vector<int> &arr) {
    int n=arr.size(), buyPrice=arr[0], totalProfit=0; //buy at 0th index price.
    
    for(int i=1; i<n; i++){
        
        if(arr[i] < arr[i-1]){ //check current element lesser than previous or not.
            int sellPrice = arr[i-1]; //if yes..then we need to sell at previous price. because. we have to maximize our profit.
            
            int currProfit = sellPrice - buyPrice; //current profit will be selling price - buy price.
            totalProfit += currProfit; //take total profit.
            
            buyPrice = arr[i]; //buying now on this value.
        }
    }
    
    int lastSellPrice = arr[n-1]; //also store last selling price - buy price.
    totalProfit += lastSellPrice - buyPrice;
    
    return totalProfit;

}


//Approach 2:TC-O(N) SC-(1) Very simple approach.
//If you observe carefully. we don't need to keep buy and sell price. 
//we can loop from 0 to n-1. if current price lesser than next price. then store answer equals to next greater price - current price.
//this is working but not intiuative..also not much understandbale.
int stockBuySell(vector<int> &arr) {
    
    int ans=0;
    for(int i=0;i<arr.size()-1;i++){
        if(arr[i+1]>arr[i])ans+=arr[i+1]-arr[i];
    }
    return ans;
}