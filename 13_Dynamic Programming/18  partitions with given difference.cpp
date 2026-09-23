//Code studio.
//we have to find subset whose difference s1 - s2 == d and s1 >= s2.
int solve(int ind, int target, vector<int>&arr, vector<vector<int>>&dp){
    if(ind < 0){
        if(target == 0){
            return 1;
        }
        return 0;
    }

    //or
    if(ind == 0){
            
        if(target == 0 and arr[0] == 0) return 2;
        if(target == 0 or target == arr[0]) return 1;
        
        return 0;
    }
      
   

    if(dp[ind][target] != -1) return dp[ind][target];

    //not take.
    int notTake = solve(ind-1, target, arr, dp);

    
    //take.
    int take=0;
    if(arr[ind] <= target) take = solve(ind-1, target-arr[ind], arr, dp);

    int mod = 1e9+7;
    return dp[ind][target] = (notTake+take)%(mod);
}

int countPartitions(int n, int d, vector<int> &arr) {
    //as we know s1+s2 = totalSum.

    //and,
    //s1 - s2 = d.
    //(totalSum-s2) - s2 = d.
    //totalSum-d = 2s2.
    //i.e s2 = (totalSum - d)/2.

    int totalSum = accumulate(arr.begin(),arr.end(),0);

    //the totalSum - d should greater than 0. i.e d<totalSum if not..then return 0.
    //or totalSum - d mod 2 should be zero, to make s1+s2=totalSum.
    if(totalSum-d<0 || (totalSum-d)%2 ) return 0;

    //question boils down to find subsets with this modified target.
    int target = ((totalSum-d)/2);
    vector<vector<int>>dp(n,vector<int>(target+1,-1));

    // return findWays(arr,target);
    return solve(n-1,target,arr,dp);

}


//Approach 2: Tabulation. TC O(N*Target) SC-O(N*Target)
 int countPartitions(vector<int>& arr, int diff) {
    // Code here
    
    int totalSum = accumulate(arr.begin(), arr.end(),0);
    
    if((totalSum - diff) % 2 != 0 or (totalSum-diff) < 0) return 0;
    
    int target = (totalSum - diff)/2;
    
    int n=arr.size();
    
    vector<vector<int>>dp(n+1, vector<int>(target+1,0));
    
    if(arr[0] == 0)
        dp[0][0] = 2;
    
    else dp[0][0] = 1;
    
    if(arr[0] != 0 and arr[0] <= target)
        dp[0][arr[0]] = 1;
        
    
    for(int ind=1; ind<n; ind++){
        
        for(int sum=0; sum<=target; sum++){
            
            //not take
            int notTake = dp[ind-1][sum];
            int take = 0;
            
            if(arr[ind] <= sum)
                take = dp[ind-1][sum-arr[ind]];
                
            dp[ind][sum] += take+notTake;
        }
    }
    
    return dp[n-1][target];
}  


//Approach 3: Space optimization. TC-O(N*Sum) SC-O(Sum).
class Solution {
  public:

  
    int countPartitions(vector<int>& arr, int diff) {
        // Code here
        
        int totalSum = accumulate(arr.begin(), arr.end(),0);
        
        if((totalSum - diff) % 2 != 0 or (totalSum-diff) < 0) return 0;
        
        int target = (totalSum - diff)/2;
        
        int n=arr.size();
        
        vector<int>prev(target+1,0),curr(target+1,0);
        
        if(arr[0] == 0)
            prev[0] = 2;
        
        else 
            prev[0] = 1;
       
        if(arr[0] != 0 and arr[0] <= target)
            prev[arr[0]] = 1;
            
        
        for(int ind=1; ind<n; ind++){
            
            
            for(int sum=0; sum<=target; sum++){
                
                //not take
                int notTake = prev[sum];
                int take = 0;
                
                if(arr[ind] <= sum)
                    take = prev[sum-arr[ind]];
                    
                curr[sum] = take+notTake;
            }
            prev = curr;
        }
        
        return prev[target];
    }
};