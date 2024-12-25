//GFG.

//I will just tell u that..in this question..we are solving this question from 1 ballon left to burst
//to entire ballon needs to burst..because there are dependcy on each other..so we're doing from bottom.
//that is from single ballon case.

 //Using Recursion.
int solve(int i, int j, vector<int>&arr){
    
    if(i > j) return 0;
    
    int maxCoins = 0;
    for(int ind=i; ind<=j; ind++){
        
        //that's why during multiplication instead of ind-1..we're taking i-1 and j+1 i.e start index and end index.
        //when only one ballon will be there..then arr[i-1] will be 1 and arr[j+1] will be 1.
        int coins = (arr[i-1] * arr[ind] * arr[j+1]) +
                    solve(i,ind-1, arr) + solve(ind+1, j, arr); 
            
        maxCoins = max(coins, maxCoins);
    }
    
    return maxCoins;
}

int maxCoins(vector<int> &arr) {
    int i=1, j=arr.size();
    
    arr.push_back(1);
    arr.insert(arr.begin(), 1);
    
    return solve(i,j,arr);
}



//Using Memorization.
int solve(int i, int j, vector<int>&arr, vector<vector<int>>&dp){
    
    if(i > j) return 0;
    
    if(dp[i][j] != -1) return dp[i][j];
    
    int maxCoins = 0;
    for(int ind=i; ind<=j; ind++){
        
        int coins = (arr[i-1] * arr[ind] * arr[j+1]) +
                    solve(i,ind-1, arr, dp) + solve(ind+1, j, arr, dp);
            
        maxCoins = max(coins, maxCoins);
    }
    
    return dp[i][j] = maxCoins;
}

int maxCoins(vector<int> &arr) {
    int i=1, j=arr.size(), n=arr.size();
    vector<vector<int>>dp(n+1, vector<int>(n+1,-1));
    
    arr.push_back(1);
    arr.insert(arr.begin(), 1);
    
    return solve(i,j,arr,dp);
}


//Using tabulation.
    int maxCoins(vector<int> &arr) {
    int n=arr.size();
    vector<vector<int>>dp(n+2, vector<int>(n+2, 0));
    
    arr.push_back(1);
    arr.insert(arr.begin(), 1);
    
    
    for(int i=n; i>=1; i--){
        
        for(int j=i; j<=n; j++){
            
            int maxCoins = 0;
            for(int ind=i; ind<=j; ind++){
                
                int coins = (arr[i-1] * arr[ind] * arr[j+1]) +
                            dp[i][ind-1] + dp[ind+1][j];
                    
                maxCoins = max(coins, maxCoins);
            }
            
            dp[i][j] = maxCoins;
        }
    }
    
    
    return dp[1][n];
}