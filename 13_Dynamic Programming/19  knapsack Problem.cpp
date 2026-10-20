//GFG.

//Knapsack problem in short is..we have to collect maximum value within given capacity.
//after below solution, I have added solution for ind < 0. instead of handling all this condition for ind==0.

//Approach 1: using recursion.
//TC-O(2^NW)
 int solve(int ind, int capacity, vector<int>&val, vector<int>&wt){
        
        if(ind == 0){
            //take
            if(capacity >= wt[ind]) return val[ind]; //if capacity is still there to pick new value then pick it.
            
            //not take
            return 0; //else return 0.
        }
        
        //not take.
        int notTake = 0 + solve(ind-1, capacity,val,wt);
        
        //take.
        int take = 0;
        if(capacity >= wt[ind]) take = val[ind] + solve(ind-1, capacity-wt[ind], val,wt);

        return max(take,notTake); //return max of both..as we have to collect maximum possible value.
    }
    
    
    int knapSack(int capacity, vector<int> &val, vector<int> &wt) {
        int n=val.size();

        return solve(n-1,capacity,val,wt);
    }
    
    

    //Approach 2: using memorization.
    // TC-O(N*W) SC-O(N*W) + 0(N)

    int solve(int ind, int capacity, vector<int>&val, vector<int>&wt, vector<vector<int>>&dp){
        
        if(ind == 0){
            //take
            if(capacity >= wt[ind]) return val[ind];
            
            //not take
            return 0;
        }

        // or 
        // if(ind == 0){
            
        //     if(wt[ind] <= W)
        //         return val[ind];
        //     return 0;    
        // }

        if(dp[ind][capacity] != -1) return dp[ind][capacity]; //if already calculate answer for 
        //dp of index with capacity then return that value.
        
        //not take.
        int notTake = 0 + solve(ind-1, capacity,val,wt,dp);
        
        //take.
        int take = 0;
        if(capacity >= wt[ind]) take = val[ind] + solve(ind-1, capacity-wt[ind], val,wt,dp);


        return dp[ind][capacity] = max(take,notTake);
    }
    
    
    int knapSack(int capacity, vector<int> &val, vector<int> &wt) {
        
        int n=val.size();
        vector<vector<int>>dp(n,vector<int>(capacity+1,-1));
        
        return solve(n-1,capacity,val,wt,dp);
    }



//Memorization solution.

    class Solution {
  public:
    
    int solve(int ind, int W, vector<int>&val, vector<int>&wt, vector<vector<int>>&dp){
        
        if(ind < 0 or W<=0)
            return 0;
        
        if(dp[ind][W] != -1)
            return dp[ind][W];
        
        int notTake = solve(ind-1, W, val, wt, dp);
        
        int take = 0;
        if(wt[ind] <= W){
            take = val[ind] + solve(ind-1, W-wt[ind], val, wt, dp);
        }
        
        return dp[ind][W] = max(take,notTake);
    }
  
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        
        int n = val.size();
        int ind = n-1;
        vector<vector<int>>dp(n,vector<int>(W+1,-1));
        
        return solve(ind, W, val, wt, dp);
    }
};



//now tabulation approach.
int knapsack(int W, vector<int> &val, vector<int> &wt) {
        
    int n = val.size();
    vector<vector<int>>dp(n+1,vector<int>(W+1,0)); //create n+1 and w+1 array. 
    
    for(int ind=1; ind<=n; ind++){ //creating for 1 based indexing, so that we don't need to handle base case.
        for(int w=0; w<=W; w++){
            
            int notTake = dp[ind-1][w];
    
            int take = 0;
            if(wt[ind-1] <= w){
                take = val[ind-1] + dp[ind-1][w-wt[ind-1]];
            }
            
            dp[ind][w] = max(take,notTake);
        }
    }
    
    return dp[n][W];
}


//Space optimization. 
int knapsack(int W, vector<int> &val, vector<int> &wt) {
    
    int n = val.size();

    vector<int>curr(W+1,0), prev(W+1,0);
    
    for(int ind=1; ind<=n; ind++){
        
        for(int w=0; w<=W; w++){
            
            int notTake = prev[w];
    
            int take = 0;
            if(wt[ind-1] <= w){
                take = val[ind-1] + prev[w-wt[ind-1]];
            }
            
            curr[w] = max(take,notTake);
        }
        prev = curr;
    }
    
    return curr[W];
}