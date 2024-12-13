//Code studio.
//we have to find subset whose difference s1 - s2 == d and s1 >= s2.
int solve(int ind, int target, vector<int>&arr, vector<vector<int>>&dp){
    if(ind < 0){
        if(target == 0){
            return 1;
        }
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

    int totalSum = 0;
    for(auto i:arr) totalSum+=i;

    //the totalSum - d should greater than 0. i.e d<totalSum if not..then return 0.
    //or totalSum - d mod 2 should be zero, to make s1+s2=totalSum.
    if(totalSum-d<0 || (totalSum-d)%2 ) return 0;

    //question boils down to find subsets with this modified target.
    int target = ((totalSum-d)/2);
    vector<vector<int>>dp(n,vector<int>(target+1,-1));

    // return findWays(arr,target);
    return solve(n-1,target,arr,dp);

}