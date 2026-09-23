//GFG.

//Approach 1: using recursion.
//we're traversing from n-1 to 0. and if current value at index is less than target then take that value and 
//substract it. at the end..if at any point..target becomes zero then return true.
//if ind == 0 then this is last index..so check..target should be equal to arr[0].
//also..we have used here take, not take conecept.
//TC-O(N*K) 
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

    //or we can add this condition to..
    // if(ind<0 or target<0) return 0;

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




//Approach 3: Tabulation. TC-O(N*Target) SC-O(N*target)
class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
  
        int n = arr.size();
        
        vector<vector<bool>>dp(n,vector<bool>(sum+1,0));
        
        for(int i=0; i<n; i++)
            dp[i][0] = true; //for every index on zeroth pos. if target is zero then answer is true.
            //cause target zero will be available from every index.
        
        if(arr[0] <= target)
            dp[0][arr[0]] = true; //on zeroth index, for arr[0] val target. answer will be true.
        //means if target is 3 and arr[0] is also three, then dp[0][3] will be 1. as 3 indicating target val.
        
        
        for(int ind=1; ind<n; ind++){
            
            for(int target=1; target<=sum; target++){
                
                
                bool notTake = dp[ind-1][target];
                bool take = false;
                
                if(arr[ind] <= target){
                    take = dp[ind-1][target-arr[ind]];
                }
                
                dp[ind][target] = (take or notTake);
            }
        }
        
        
        return dp[n-1][sum];
    }
};

//Approach 4: Space Optimization. TC-O(N*Target) SC-O(2target)
class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {

        int n = arr.size();

        vector<bool> prev(sum+1,0);

        prev[0] = true;

        prev[arr[0]] = true;


        for(int ind=1; ind<n; ind++){
            vector<bool>curr(sum+1,0);
            curr[0]  = true;
            
            for(int target=1; target<=sum; target++){


                bool notTake = prev[target];
                bool take = false;

                if(arr[ind] <= target){
                    take = prev[target-arr[ind]];
                }

                curr[target] = (take or notTake);
            }
            prev = curr;
        }


        return prev[sum];
    }
};