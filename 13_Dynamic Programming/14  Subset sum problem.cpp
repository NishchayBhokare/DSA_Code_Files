//GFG.

//Approach 1: using recursion.
//we're traversing from n-1 to 0. and if current value at index is less than target then take that value and 
//substract it. at the end..if at any point..target becomes zero then return true.
//if ind == 0 then this is last index..so check..target should be equal to arr[0].
//also..we have used here take, not take conecept.
bool solve(int ind, int target, vector<int>&arr){
    if(target == 0) return true;
    
    if(ind==0){
        if(arr[0] == target) return true;
        return false;
    }


    //Not take
    bool notTake = solve(ind-1,target,arr);

    //Take
    bool take = false;
   
    if(arr[ind] <= target){
        take = solve(ind-1,target-arr[ind],arr);
    }

    if(take || notTake) return true;
    return false;
}

bool isSubsetSum(int target, vector<int> &arr) {
    int n = arr.size();
        
    vector<vector<int>>dp(n,vector<int>(target+1,-1));
    return solve(n-1,target,arr,dp);
}


//Approach 2:Optimised Approach using memorization. TC-N*target. SC-N*Target.
bool solve(int ind, int target, vector<int>&arr, vector<vector<int>>&dp){
    if(target == 0) return true;
    
    if(ind==0){
        if(arr[0] == target) return true;
        return false;
    }

    if(dp[ind][target] != -1) return dp[ind][target];

    //Not take
    bool notTake = solve(ind-1,target,arr,dp);

    //Take
    bool take = false;
    if(arr[ind] <= target){
        take = solve(ind-1,target-arr[ind],arr,dp);
    }

    return dp[ind][target] = take || notTake;

}

bool isSubsetSum(vector<int>& arr, int target) {
        int n = arr.size();
        
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return solve(n-1,target,arr,dp);
        
}