//GFG.
//for this question, tabulation approach is natural.

//Appraoch 1: using tabulation TC-O(N*TotalSum) SC-O(N*TotalSum)
class Solution {
  public:
    int minDifference(vector<int>& arr) {

        int n = arr.size();
        int totalSum = accumulate(arr.begin(),arr.end(),0);
        vector<vector<int>>dp(n,vector<int>(totalSum+1,0));
        
        for(int i=0; i<n; i++){
            dp[i][0] = 1;
        }
        
        dp[0][arr[0]] = 1;
        
        for(int i=1; i<n; i++){
            
            for(int target = 1; target<=totalSum; target++ ){
                
                //not tkae
                int notTake = dp[i-1][target];
                
                int take = 0;
                
                if(arr[i]<=target) 
                    take = dp[i-1][target-arr[i]];
                
                dp[i][target] = take or notTake;
            }
        }
        
        
        int minAbsDiff = INT_MAX;
        
        for(int sum=0; sum<=totalSum/2; sum++){ 
			//why total Sum/2. If you could se absolute difference from 0 to total sum.
			//then after totalSum/2. abs diff is getting repeated, that menas.
			//absolute diff of at sum = 0 and at sum = totalSum is same and so on.

            if(dp[n-1][sum] == 1){
                int s1 = sum;
                int s2 = totalSum - sum;
                
                minAbsDiff = min(minAbsDiff, abs(s1-s2));
            }
        }
        
        return minAbsDiff;
    }
};


//Approach 2: TC-O(N*K) it seems K*(N*K) but it's not as we're using, dp array so it will get fill for most of the states.
class Solution {
public:

    int solve(int ind, int target,
              vector<int>& arr,
              vector<vector<int>>& dp) {

        if(target == 0)
            return 1;

        if(ind == 0)
            return arr[0] == target;

        if(dp[ind][target] != -1)
            return dp[ind][target];

        int notTake = solve(ind - 1, target, arr, dp);

        int take = 0;

        if(arr[ind] <= target) {
            take = solve(ind - 1,target - arr[ind],arr,dp);
        }

        return dp[ind][target] = (take || notTake);
    }

    int minDifference(vector<int>& arr) {

        int n = arr.size();

        int totalSum =
            accumulate(arr.begin(), arr.end(), 0);

        vector<vector<int>> dp(n,vector<int>(totalSum + 1, -1));

        int minAbsDiff = INT_MAX;

        for(int sum1 = 0;sum1 <= totalSum / 2;sum1++) {

            if(solve(n - 1, sum1, arr, dp)) { //calling for every sum from 0 to totalSum/2

                int sum2 = totalSum - sum1;

                minAbsDiff =min(minAbsDiff, abs(sum1 - sum2));
            }
        }

        return minAbsDiff;
    }
};




//Approach 3: below approach of memorization is not natural.

//We have to find array parition which has..minimum absolute diffrence in it.

//Approach 1: using memorization. create all possible sum can be possible and store it in 
//dp array with their level index.
//at the end..traverse last row..of dp. so that we will get all possbile sum which can be genreate from given array.

//now we have to calculate min diff from one parition to second pairtion.
//so current values for every index in last row of dp..will consider as first parition value.
//and second partiion value will be totalsum - first partitionsum.
//then store the minimum absoulte difference among all possible paritions.

void solve(int ind,int currSum, vector<int>& arr, vector<vector<int>>&dp, int n){

	if(ind == n-1){
		dp[ind][currSum]=currSum;
		return;
	}

	if(dp[ind][currSum] != -1) return;

	//not take.
	solve(ind+1,currSum,arr,dp,n);

	//take
	solve(ind+1,currSum+arr[ind], arr,dp,n);

	dp[ind][currSum] = currSum;
}

int minDifference(vector<int>& arr) {
	int n = arr.size();

	int totalSum = accumulate(arr.begin(),arr.end(),0);

	vector<vector<int>>dp(n,vector<int>(totalSum+1,-1));

	int currSum = 0, ind = 0;
	solve(ind,currSum,arr,dp,n);

	int minDiff = INT_MAX;
	for(int first:dp[n-1]){
		if(first == -1) continue;

		int second = totalSum-first;
		int currDiff = abs(first-second);

		minDiff = min(minDiff, currDiff);
	}

	return minDiff;
}