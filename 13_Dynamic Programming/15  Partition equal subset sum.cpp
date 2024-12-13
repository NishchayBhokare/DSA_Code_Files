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
		if(sum-arr[0] == 0) return true;
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

	vector<vector<int>>dp(n,vector<int>(sum+1,-1));

	if(sum%2 != 0) return false;

	return solve(n-1,arr,dp,sum/2);
}