//code studio.

//Approach 1: using recursion. As we have to count all the subsets with sum k. so,we have to 
//make sure about base cases.
int solve(int ind,int k, vector<int>&arr){

	if(ind < 0){ //move till index less than 0.
        if(k==0) return 1; //if value of k is zero..then return 1.
        return 0; //else zero.
    }


// or we can right like this also because..array elements are from 0.
    if(ind == 0){ //if we reach till last ind. i.e 0
		if(k == 0 && arr[0] == 0) return 2;  //now check...if k is already 0 and this base case index in arr equals to 0.
        //then there are two susbsets of k.
		if(arr[0] == k || k==0  ) return 1; //else check...if last element equals to k or..if k is 0 already zero then return 1.
		return 0;
	}

	//OR
	if(ind == 0){
		int cnt = 0;
		if(k == 0) cnt++; //if k is zero then increment count.
		
		if(k == arr[0]) cnt++; //and if k=arr[0] k equals to arr[0] then increment cnt.
		return cnt;
	}


	int notTake = solve(ind-1,k,arr);

	int take = 0;
	if(arr[ind]<=k) take = solve(ind-1,k-arr[ind],arr);

	return (notTake+take);
}

int findWays(vector<int>& arr, int k)
{
	int n=arr.size();
	return solve(n-1,k,arr);

}



//Approach 2: using dp. 
int solve(int ind,int k, vector<int>&arr, vector<vector<int>>&dp){
	
	if(ind < 0){ //move till index less than 0.
        if(k==0) return 1; //if value of k is zero..then return 1.
        return 0; //else zero.
    }

	if(dp[ind][k] != -1) return dp[ind][k]; //if already we calculated answer for this index and sum then return that anwer.


	int notTake = solve(ind-1,k,arr,dp);

	int take = 0;
	if(arr[ind]<=k) take = solve(ind-1,k-arr[ind],arr,dp);

	int mod = 1e9+7;
	return dp[ind][k] = (notTake+take)%(mod);
}

int findWays(vector<int>& arr, int k)
{
	int n=arr.size();

	vector<vector<int>>dp(n,vector<int>(k+1,-1));
	return solve(n-1,k,arr,dp);

}


//Approach 3: Tabulation method. TC-O(N*target) SC(N*target)
 int perfectSum(vector<int>& arr, int target) {

	int n = arr.size();

	vector<vector<int>>dp(n+1,vector<int>(target+1,0));

	dp[0][0]=1; //on index 0 if sum is zero then cnt is 1.
	
	
	for(int i=1; i<=n; i++){
		
		for(int t=0; t<=target; t++){
			
			int notTake = dp[i-1][t];
			
			int take = 0;
			if(arr[i-1]<=t) //i-1 because i index is based here.
				take = dp[i-1][t-arr[i-1]];
	
	
			dp[i][t] = take+notTake;
		}
	}
	
	return dp[n][target];
}


//Appraoch 4: Most optimised approach. TC-O(N*target) Tabulation method. TC-O(N*target) SC(target)
int perfectSum(vector<int>& arr, int target) {

        int n = arr.size();

        
        
        vector<int>prev(target+1,0), curr(target+1,0);
        prev[0]=1;
        
        
        for(int i=1; i<=n; i++){
            
            for(int t=0; t<=target; t++){
                
                int notTake = prev[t];
                
                int take = 0;
                if(arr[i-1]<=t)
                    take = prev[t-arr[i-1]];
        
        
                curr[t] = take+notTake;
            }
            
            prev = curr;
        }
        
        return curr[target];
    }