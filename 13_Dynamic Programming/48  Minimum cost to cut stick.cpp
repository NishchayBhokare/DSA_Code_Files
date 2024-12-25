//leetcode.

//Little difficult question..not understood much.

//Approach 1: using recursion.
int solve(int i, int j,vector<int>&cuts){

    if(i>j) return 0;

    int mini=INT_MAX;

    for(int ind=i; ind<=j; ind++){

        int cost = cuts[j+1] - cuts[i-1] + solve(i, ind-1, cuts) + 
            solve(ind+1,j,cuts);

        mini = min(cost, mini);
    }
    
    return mini;
}
int minCost(int n, vector<int>& cuts) {
    int cSize=cuts.size();
    cuts.insert(cuts.begin(),0);
    cuts.push_back(n);
    sort(cuts.begin(), cuts.end());

    return solve(1,cSize,cuts);
}



//Approach 2:using memorization.
int solve(int i, int j,vector<int>&cuts, vector<vector<int>>&dp){

    if(i>j) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int mini=INT_MAX;

    for(int ind=i; ind<=j; ind++){

        int cost = cuts[j+1] - cuts[i-1] + solve(i, ind-1, cuts,dp) + 
            solve(ind+1,j,cuts,dp);

        mini = min(cost, mini);
    }
    
    return dp[i][j] = mini;
}
int minCost(int n, vector<int>& cuts) {
    int cSize=cuts.size();
    cuts.insert(cuts.begin(),0);
    cuts.push_back(n);
    sort(cuts.begin(), cuts.end());
    vector<vector<int>>dp(cSize+1, vector<int>(cSize+1,-1));

    return solve(1,cSize,cuts,dp);
}


//Approach 3: Using tabulation.
 //Using tabulation.
int minCost(int n, vector<int>& cuts) {
    int cSize=cuts.size();
    cuts.insert(cuts.begin(),0);
    cuts.push_back(n);
    sort(cuts.begin(), cuts.end());
    vector<vector<int>>dp(cSize+2, vector<int>(cSize+2,0));


    for(int i=cSize; i>=1; i--){
        for(int j=i; j<=cSize; j++){

            int mini=INT_MAX;

            for(int ind=i; ind<=j; ind++){

                int cost = cuts[j+1] - cuts[i-1] + dp[i][ind-1] + 
                    dp[ind+1][j];

                mini = min(cost, mini);
            }
            
            dp[i][j] = mini;
        }
    }
    return dp[1][cSize];
}