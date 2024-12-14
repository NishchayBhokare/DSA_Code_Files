//Code studio.

//We have to find..number of ways to make coin x by using given array elements.

//Approach 1: using recursion.
long solve(int ind, int value, int *arr){
    if(value==0) return 1;

    if(ind == 0){
        if((value%arr[0]) == 0) return 1; //basically if array element is divisble to value and remainder is 0 then
        //this is one more way to make coin x. so return 1.
        return 0; //else zero.
    }

    if(ind <0){
        if(value == 0) return 1;
        return 0;
    }


    //not take.
    long notTake = solve(ind-1, value, arr);

    //take
    long take = 0;
    if(arr[ind]<= value) take=solve(ind, value-arr[ind], arr); //we can use current arrya elements as many times as we want.
    //but one condition is..it should be lesser than equal value.

    return (take+notTake);
}

long countWaysToMakeChange(int *arr, int n, int value)
{
  return solve(n-1,value,arr);
}


//Approach 2: using Memorization. TC-O(N*T) SC-O(N*T(target))
long solve(int ind, int value, int *arr, vector<vector<long>>&dp){
    if(value==0) return 1;

    if(ind == 0){
        if((value%arr[0]) == 0) return 1;
        return 0;
    }


    if(dp[ind][value]!= -1) return dp[ind][value];


    //not take.
    long notTake = solve(ind-1, value, arr,dp);

    //take
    long take = 0;
    
    if(arr[ind]<= value) take=solve(ind, value-arr[ind], arr,dp);

    // int mod = 1e9+7;
    return dp[ind][value] = (take+notTake);
}

long countWaysToMakeChange(int *arr, int n, int value)
{
  vector<vector<long>>dp(n, vector<long>(value+1,-1));
  return solve(n-1,value,arr,dp);
}