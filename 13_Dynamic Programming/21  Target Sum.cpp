//Code studio.
//we can solve this question by just calling 18th question function.
//if you observe carefully we can divide subsets in s1 and s2 here in s1 is all addition and 
//s2 is all substraction values so we can simply call that function too.



//Approach 1: using recursion.
int solve(int ind, int target, vector<int>&arr){

    if(ind == 0){
        //we don't need to return if target==0 then return 1 because..we have to apply addition,substraction on all elements.

        int count=0; //if index is zero. then check..current value of target with array index value.
        if((target + arr[ind]) == 0) count++; //if we add array index value in target, if addition equals to zero then increment count.
        if((target - arr[ind]) == 0) count++; //same for check with substractiing array value.
 
        return count; //finally return count.
    }

    //pick with +
    int pickPlus = solve(ind-1, target+arr[ind], arr);

    //pick With -
    int pickMinus = solve(ind-1, target-arr[ind], arr);

    return (pickPlus+pickMinus);
}

int targetSum(int n, int target, vector<int>& arr) {
    
    return solve(n-1,target,arr);
}

//Approacch 2: Using Memorization, using map. we can't use here unordered_map they don't have hash function for pair.
int solve(int ind, int target, vector<int>&arr, map<pair<int,int>,int>&dp){

    if(ind == 0){
        int count=0;
        if((target + arr[ind]) == 0) count++;
        if((target - arr[ind]) == 0) count++;

        return count;
    }

    if(dp.find({ind,target}) != dp.end()) 
        return dp[{ind,target}];  

    //pick with +
    int pickPlus = solve(ind-1, target+arr[ind], arr, dp);

    //pick With -
    int pickMinus = solve(ind-1, target-arr[ind], arr, dp);

    return dp[{ind,target}] = (pickPlus+pickMinus);
}

int targetSum(int n, int target, vector<int>& arr) {
    map<pair<int,int>,int>dp;
    return solve(n-1,target,arr,dp);
}




//Approach 3: using vector..but little complex.
int solve(int ind, int target, vector<int>&arr, vector<vector<int>>&dp, int sum){

    if(ind == 0){
        int count=0;
        if((target + arr[ind]) == 0) count++;
        if((target - arr[ind]) == 0) count++;

        return count;
    }

    if(dp[ind][target+sum] != -1) 
        return dp[ind][target+sum];  

    //pick with +
    int pickPlus =solve(ind-1, target+arr[ind], arr, dp, sum);

    //pick With -
    int pickMinus = 0;
    pickMinus = solve(ind-1, target-arr[ind], arr, dp, sum);


    return dp[ind][target+sum] = (pickPlus+pickMinus);
}

int targetSum(int n, int target, vector<int>& arr) {
    int sum=0;
    for(auto i:arr) sum+=i;

    int m = 2*(abs(target)+sum)+1; //consider

    vector<vector<int>>dp(n,vector<int>(m,-1));
    return solve(n-1,target,arr,dp,abs(target)+sum);
}