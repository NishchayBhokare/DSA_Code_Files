//GFG.

//Knapsack problem in short is..we have to collect maximum value within given capacity.

//Approach 1: using recursion.
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
    int solve(int ind, int capacity, vector<int>&val, vector<int>&wt, vector<vector<int>>&dp){
        
        if(ind == 0){
            //take
            if(capacity >= wt[ind]) return val[ind];
            
            //not take
            return 0;
        }
        
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
