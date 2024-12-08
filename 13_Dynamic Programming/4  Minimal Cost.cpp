//GFG 
//Extension of frog jump question.

Approach 1: using Memorization. 
// TC-O(N) SC-O(N)

int solve(int n, int k, vector<int>&dp, vector<int>&heights){

    if(n == 0)  return 0;

    if(dp[n] != -1)
        return dp[n]; //if we already calculated minimum value for n..then don't calculate.

    int minSteps = INT_MAX;

    for(int i = 1; i<=k; i++){ //just change is instead of leftmin & rightmin..we're looping till k.
    //and getting minimum answer for current index in minSteps.

        if((n-i) >= 0){ //by n-i, checking index lies in array index or not.
            int steps = solve(n-i,k,dp,heights) + abs(height[n] - height[n-i]);

            minSteps = min(steps, minSteps); //take min steps
        }
    }

    return dp[n] = minSteps; //return final answer. i.e dp[n];
}


int minimizeCost(int k, vector<int>& heights) {
    
    int n = heights.size();
    
    vector<int>dp(n,-1);
    return dp[n-1] =solve(n-1,k,dp,heights);
}


Approach 2: Tabulation 
// TC-O(N) SC-O(N)
 int minimizeCost(int k, vector<int>& heights) {
    int n = heights.size();
    
    vector<int>dp(n,-1);
    dp[0] = 0;

    for(int i = 1; i<n; i++){ //loop from 1 to n.
        int minSteps = INT_MAX;

        for(int j = 1; j<=k; j++){ //loop for k steps. to check minimum of all steps.
            if((i-j) >=0 ){
                int steps = dp[i-j] + abs(heights[i] - heights[i-j]);
                minSteps = min(steps, minSteps); //store in minSteps.
            }
        }

        dp[i] = minSteps;
    }

    return dp[n-1]; //return dp[n-1].
}


//Here we cannot optimise space...like we can try to create dp of size k..and then push
//only previous k elemnets. but at worst case.. if k == n then sc will same O(N).
//so no need of such solutions.