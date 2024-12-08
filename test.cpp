#include<bits/stdc++.h>
using namespace std;

int find(int n, int k, vector<int>&dp, vector<int>&heights){

    if(n == 0)  return 0;

    if(dp[n] != -1)
        return dp[n];

    int minSteps = INT_MAX;

    for(int i = 1; i<=k; i++){
        if((n-i) >= 0){
            int steps = find(n-i,k,dp,heights) + abs(heights[n] - heights[n-i]);

            minSteps = min(steps, minSteps);
        }
    }

    return dp[n] = minSteps;
}

// int solve(int n, int k, vector<int>&heights){

//     vector<int>dp(n,-1);
//     dp[n] = find(n-1,k,dp,heights);
//     for(auto i:dp)
//         cout<<i<<" ";
//     cout<<endl;
//     return dp[n];
// }

int solve(int n, int k, vector<int>&heights){

    vector<int>dp(n,-1);
    dp[0] = 0;

    for(int i = 1; i<n; i++){
        int minSteps = INT_MAX;

        for(int j = 1; j<=k; j++){
            if((i-j) >=0 ){
                int steps = dp[i-j] + abs(heights[i] - heights[i-j]);
                minSteps = min(steps, minSteps);
            }
        }

        dp[i] = minSteps;
    }

    return dp[n-1];
}

int solve(int n, int k, vector<int>&heights){

    list<int>ls(k);
    ls[0] = 0;

    for(int i = 1; i<n; i++){
        int minSteps = INT_MAX;

        for(int j = 1; j<=k; j++){
            if((i-j) >=0 ){
                int steps = ls[i-j] + abs(heights[i] - heights[i-j]);
                minSteps = min(steps, minSteps);
            }
        }

        ls.push_back(minSteps)
    }

    return ls[n-1];
}

int main(){
    vector<int>heights = {15,10,20,30,10,15,20};
    int n = 7, k=3;
    cout<<solve(n, k, heights); 
}