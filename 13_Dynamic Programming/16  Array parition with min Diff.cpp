//code studio -> 
//We have to find array parition which has..minimum absolute diffrence in it.

//Approach 1: using memorization. create all possible sum can be possible and store it in 
//dp array with their level index.
//at the end..traverse last row..of dp. so that we will get all possbile sum which can be genreate from given array.

//now we have to calculate min diff from one parition to second pairtion.
//so current values for every index in last row of dp..will consider as first parition value.
//and second partiion value will be totalsum - first partitionsum.
//then store the minimum absoulte difference among all possible paritions.
void solve(int ind,int currSum, vector<int>& arr, vector<vector<int>>&dp, int n){

	if(ind >= n){
		return;
	}
	
	if(dp[ind][currSum] != -1) return; //if already generated for given index and sum. then don't do again just
    //return whatever u stored.

	//not take.
	solve(ind+1,currSum,arr,dp,n);

	//take
	dp[ind][currSum] = currSum+arr[ind]; //store current sum in dp array.
	solve(ind+1,currSum+arr[ind], arr,dp,n);

}

int minSubsetSumDifference(vector<int>& arr, int n)
{	
	int totalSum = 0;
	for(auto i:arr) totalSum+=i;

	vector<vector<int>>dp(n,vector<int>(totalSum+1,-1));
	
	int currSum = 0, ind = 0;
	solve(ind,currSum,arr,dp,n); //generate all possible sum.

	int minDiff = INT_MAX;
	for(int first:dp[n-1]){ //now traverse over last row to get all possbile generated sum.
		if(first == -1) continue;

		int second = totalSum-first; //calculate second parition sum by substracting first from totalsum.
		int currDiff = abs(first-second); //take abosulte dif.

		minDiff = min(minDiff, currDiff); //and store min abosulte dif in mindiff.
	}

	return minDiff; //then return final answer.
}