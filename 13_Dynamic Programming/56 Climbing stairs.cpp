//Approach: Memorization. TC-O(N*3) SC-O(N)
class Solution {
public:

    long long solve(int ind, vector<int>&costs, vector<int>&dp, int &n){

        if(ind == n) return 0;

        if(dp[ind]!= -1) return dp[ind];

        long long minCost = INT_MAX;
        for(int step=1; step<=3; step++){

            int nextStep = ind+step;
            if(nextStep<=n){
                long long currCost = costs[nextStep-1] + 1LL*(nextStep - ind)*(nextStep - ind) + solve(nextStep,costs,dp,n);
           
                minCost = min(minCost, currCost);
            }  
        }

        return dp[ind]=minCost;
    }

    int climbStairs(int n, vector<int>& costs) {
  
        vector<int>dp(n,-1);
        return solve(0,costs,dp,n);
    }
};

//Approch: Tabulation. TC - O(N*3) SC - O(N)
class Solution {
public:

    int climbStairs(int n, vector<int>& costs) {
  
        vector<int>dp(n+1,0);
        
        for(int ind=n-1; ind>=0; ind--){
            long long minCost = INT_MAX;

            for(int step=1; step<=3; step++){

                int nextStep = ind+step;

                if(nextStep<=n){
                    long long currCost = costs[nextStep-1] + 1LL*(nextStep - ind)*(nextStep - ind) + dp[nextStep];
            
                    minCost = min(minCost, currCost);
                }  
            }

            dp[ind]=minCost;
        }

        return dp[0];
    }
};