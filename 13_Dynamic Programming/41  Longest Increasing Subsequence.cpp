//GFG.

//Logic is simple take and not take. track previous element's index and compare for current element.
//we will either take this current elemnt under consideration..or will not take.
//if we want to take..then please check..current element is greater than previous or not.

//Approach 1: Using recurison.
int solve(int i, int prev, vector<int>&arr, int &n){
    
    if(i == n) return 0;
    
    //notTake case.
    int notTake = 0 + solve(i+1, prev, arr, n);
    
    //take case.
    int take = 0;
    
    if(prev==-1 || arr[i] > arr[prev])
        take = 1 + solve(i+1, i, arr, n);
        
    return max(notTake, take);
}

int longestSubsequence(vector<int>& arr) {
    int i=0, prev=-1, n=arr.size();
    return solve(i,prev,arr,n);
}


//Approach 2: using Memorization. //addition of memorization and slight change in prev..i.e
//as we storing prev index in temp..so just do right shift temp so that -1 will points to 0.
int solve(int i, int prev, vector<int>&arr, int &n, vector<vector<int>>&dp){
    
    if(i == n) return 0;
    
    if(dp[i][prev+1] != -1){ 
        return dp[i][prev+1];
    }
    
    
    //notTake case.
    int notTake = 0 + solve(i+1, prev, arr, n, dp);
    
    //take case.
    int take = 0;
    
    if(prev==-1 || arr[i] > arr[prev])
        take = 1 + solve(i+1, i, arr, n,dp);
    
    return dp[i][prev+1] = max(notTake, take);
}

int longestSubsequence(vector<int>& arr) {
    int i=0, prev=-1, n=arr.size();
    vector<vector<int>>dp(n,vector<int>(n+1,-1));
    return solve(i,prev,arr,n,dp);
}


//Approach 3: using tabulation.
int longestSubsequence(vector<int>& arr) {
    int n=arr.size();
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    
    
    for(int i=n-1; i>=0; i--){
        
        for(int prev=i-1; prev>=-1; prev--){
            
            //notTake case.
            int notTake = 0 + dp[i+1][prev+1];
            
            //take case.
            int take = 0;
            
            if(prev==-1 || arr[i] > arr[prev])
                take = 1 + dp[i+1][i+1];
            
            dp[i][prev+1] = max(notTake, take); 
        }
    }
        
    //   return dp[0][-1+1];
    return dp[0][0];
}
    
//Approach 4: using space optimization.

int longestSubsequence(vector<int>& arr) {
    int n=arr.size();
    vector<int>dp(n+1,0);
    vector<int>currDp(n+1,0);
    
    
    for(int i=n-1; i>=0; i--){
        
        for(int prev=i-1; prev>=-1; prev--){
            
            //notTake case.
            int notTake = 0 + dp[prev+1];
            
            //take case.
            int take = 0;
            
            if(prev==-1 || arr[i] > arr[prev])
                take = 1 + dp[i+1];
            
            currDp[prev+1] = max(notTake, take); 
        }
        //after computing entier row..then only update prevDp to currDp.
        dp = currDp;
    }
    
    return dp[-1+1];
}


//Approach 5: different iterative approach.
//loop from 0 to n and inside that..loop from 0 to i-1. if current ith element is greater than 
//it's previous jth element then take currLen. and update dp[i]th index according to it.
int longestSubsequence(vector<int>& arr) {
    int n=arr.size();
    
    vector<int>dp(n,1);

    int ans=0;
    for(int i=0; i<n; i++){
        int maxCnt = 0;
        for(int j=0; j<i; j++){
            
            if(arr[i] > arr[j]){
                int curr = dp[j] + 1;
                dp[i] = max(dp[i], curr);
            }   
        }
        
        //at the end..after computing..for current index..just store maximum answer.
        ans = max(ans,dp[i]);
    }
    
    return ans;
}