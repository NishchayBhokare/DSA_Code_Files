//Whenever a problem asks you to count the number of structures of a particular height, try asking:
1. What are the possible configurations of the left and right substructures?
2. What conditions must those substructures satisfy?
3. How many ways can each configuration be formed?
4. Are there different arrangements that need to be counted separately?
This is a recurring pattern in tree DP and combinatorics.

// TC-O(H) SC-O(1)
class Solution {
  public:
    long long solve(int h, vector<long long>&dp){
        long long mod=1e9+7;
        
        if(h==0) return 1;
        if(h==1) return 1;
        
        if(dp[h] != -1) return dp[h];
        
        long long bothEqual = (solve(h-1,dp)%mod * solve(h-1,dp)%mod)%mod;
        long long leftSmall = (solve(h-2,dp)%mod * solve(h-1,dp)%mod)%mod;
        long long rightSmall = (solve(h-1,dp)%mod * solve(h-2,dp)%mod)%mod;
        
        return dp[h] = (bothEqual+leftSmall+rightSmall)%mod;
    }
  
    int countBT(int h) {
        // code here
        
        vector<long long>dp(h+1,-1);
        
        return solve(h,dp);
    }
};