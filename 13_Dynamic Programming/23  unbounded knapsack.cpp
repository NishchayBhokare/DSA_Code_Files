//Code studio.

//It's similar to knapsack problem 19 but the additional case is, we can pick one weight multiple
// times with its' profit. like question 22. 

//Approadch 1: Using Recursion.
int solve(int ind, int w, vector<int> &profit, vector<int> &weight){
    // if(ind == 0){
    //     if(weight[ind] <= w){
    //         int times = w/weight[ind];
    //         return (profit[ind]*times);
    //     }
    //     return 0;
    // }

    // or simly we can write like this also.
    if(ind==0)
        return (w/weight[0])*profit[0];


    //not take.
    int notTake = 0 + solve(ind-1,w,profit,weight);

    //take.
    int take = 0;
    if(weight[ind] <= w) 
        take = profit[ind] + solve(ind, w-weight[ind], profit, weight);
        //not decrementing index because we want to take this profit as max as possible till weight is greater than present weight in array.

    return max(take,notTake);
}


int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){

    return solve(n-1,w,profit,weight);
}



//Approach 2: Using Memorization.
int solve(int ind, int w, vector<int> &profit, vector<int> &weight, vector<vector<int>>&dp){

    // if(w==0) return 0;

    // if(ind == 0){
    //     if(weight[ind] <= w){
    //         int times = w/weight[ind];
    //         return (profit[ind]*times);
    //     }
    //     return 0;
    // }

    //or we can add these base case.
    if(ind==0)
        return (w/weight[0])*profit[0];

    if(dp[ind][w] != -1) return dp[ind][w];

    //not take.
    int notTake = 0 + solve(ind-1,w,profit,weight,dp);

    //take.
    int take = 0;
    if(weight[ind] <= w) 
        take = profit[ind] + solve(ind, w-weight[ind], profit, weight,dp);


    return dp[ind][w] = max(take,notTake);
}


int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    
    vector<vector<int>>dp(n,vector<int>(w+1,-1));
    return solve(n-1,w,profit,weight,dp);
}