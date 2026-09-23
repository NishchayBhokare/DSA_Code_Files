//code studio.
//Approaches is similar like previous question...only one change..that is we will divide sum/2 then 
//we will take divided sum as target..and will check..is there any subset equals to target or not.
//if we found one subset..then abviously..second subset will be there.
//so question boils down to find subset which sum equals to sum/2. 

//Approach 1: using recursion. TC-2^n
bool solve(int ind, vector<int>&arr, int sum){
	if(ind == 0){
		if(sum-arr[0] == 0) return true;
		return false;
	}

	if(sum==0) return true;

	//not take
	bool notTake = solve(ind-1,arr,sum);

	//take
	bool take = false;
	if(arr[ind] <= sum){
		take = solve(ind-1,arr,sum-arr[ind]);
	}
	

	return (take || notTake);
}

bool canPartition(vector<int> &arr, int n)
{	
	int sum=0;
	for(auto i:arr) sum+=i;

	if(sum%2 != 0) return false;

	return solve(n-1,arr,sum/2);
}



//Approach 2: using memorization. TC-N*target. SC-N*Target.
bool solve(int ind, vector<int>&arr, vector<vector<int>>&dp, int sum){
	if(ind == 0){
		if(arr[0] == sum) return true;
		return false;
	}

	if(sum==0) return true;

	if(dp[ind][sum] != -1) return dp[ind][sum];

	//not take
	bool notTake = solve(ind-1,arr,dp,sum);

	//take
	bool take = false;
	if(arr[ind] <= sum){
		take = solve(ind-1,arr,dp,sum-arr[ind]);
	}
	

	return dp[ind][sum] = (take || notTake);
}

bool canPartition(vector<int> &arr, int n)
{	
	int sum=0;
	for(auto i:arr) sum+=i;
	// int sum = accumulate(arr.begin(), arr.end(),0);

	vector<vector<int>>dp(n,vector<int>(sum+1,-1));

	if(sum%2 != 0) return false;

	return solve(n-1,arr,dp,sum/2);
}


//Approach 3: Using tabulation. TC-N*target. SC-N*Target.
class Solution {
  public:
   
 
    bool equalPartition(vector<int>& arr) {
        // code here
        int sum = accumulate(arr.begin(), arr.end(),0);
        if(sum%2 != 0) return 0;
        
        int n = arr.size();
        int target = sum/2;
        
        vector<vector<int>>dp(n,vector<int>(target+1,0));
        
        //first base case.
        for(int i=0; i<n; i++){
            dp[i][0] = 1;
        }
        
        if(arr[0] <= target)
            dp[0][arr[0]]=1;
                
        //we done with sum = 0.
        
        for(int ind=1; ind<n; ind++){
            for(int val=1; val<=target; val++){
                
                //take
                int take =0;
                if(val>=arr[ind])
                    take = dp[ind-1][val-arr[ind]];
                
                //not take
                int notTake = dp[ind-1][val];
                
                dp[ind][val] = take or notTake;
            }
        }
        
        
        return dp[n-1][target];
    }
};


//Approach 4: Using space optimization. TC-O(N*target) SC-O(target)
class Solution {
  public:
   
 
    bool equalPartition(vector<int>& arr) {
        // code here
        int sum = accumulate(arr.begin(), arr.end(),0);
        if(sum%2 != 0) return 0;
        
        int n = arr.size();
        int target = sum/2;
        
        vector<int>prev(target+1,0);

        prev[0] = 1;
        
        if(arr[0] <= target)
            prev[arr[0]]=1;
                
        //we done with sum 0.
        
        for(int ind=1; ind<n; ind++){
            
            vector<int>curr(target+1,0);
            curr[0] = 1;
            for(int val=1; val<=target; val++){
                
                //take
                int take =0;
                if(val>=arr[ind])
                    take = prev[val-arr[ind]];
                
                //not take
                int notTake = prev[val];
                
                curr[val] = take or notTake;
            }
            
            prev = curr;
        }
        
        
        return prev[target];
    }
};