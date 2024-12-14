//code studio.

//Approach 1: using recursion. As we have to count all the subsets with sum k. so,we have to 
//make sure about base cases.
int solve(int ind,int k, vector<int>&arr){

	if(ind < 0){ //move till index less than 0.
        if(k==0) return 1; //if value of k is zero..then return 1.
        return 0; //else zero.
    }


//or we can right like this also because..array elements are from 0.
    // if(ind == 0){ //if we reach till last ind. i.e 0
	// 	if(k == 0 && arr[0] == 0) return 2;  //now check...if k is already 0 and this base case index in arr equals to 0.
    //     //then there are two susbsets of k.
	// 	if(arr[0] == k || k==0  ) return 1; //else check...if last element equals to k or..if k is 0 already zero then return 1.
	// 	return 0;
	// }


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
