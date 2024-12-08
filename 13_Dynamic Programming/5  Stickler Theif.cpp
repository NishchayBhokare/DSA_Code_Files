//GFG. nothing but maximum sum of non adjacent elements.
//Simple approach which we used in problem like..substrings in strings.
    
//Approach 1: Using Memorization.
//TC-O(N) SC-O(N)
int solve(int n, vector<int>&dp, vector<int>&arr){
    
    if(n == 0)
        return arr[0];
        
    if(n == 1)
        return max(arr[0],arr[1]); //this is catch..if n is 1..then return max of value from 0 or 1.
    
    if(dp[n] != -1) //nth value is already calcualted then return it.
        return dp[n];
        
    int take = INT_MIN;   
    if((n-2) >= 0)  //go for take..make sure index lies inside array.
        take = solve(n-2, dp, arr) + arr[n];  //taking current arr[n] and calling for n-2 i.e nonadjacent. 
    
    int notTake = solve(n-1, dp, arr); //not taking curr arr[n] so calling only n-1.
    
    return dp[n] = max(take, notTake); //store maximum value in dp[n].
}

int findMaxSum(vector<int>& arr) {
    int n = arr.size();
    vector<int>dp(n,-1);
    return solve(n-1, dp, arr);
}


//Approach 2: Tabulation. //bottom up approach.
//TC-O(N) SC-O(N) 
int findMaxSum(vector<int>& arr) {
    int n = arr.size();
    vector<int>dp(n,-1);
    
    dp[0] = arr[0];
    dp[1] = max(arr[0],arr[1]); //starting cases.
    
    for(int i = 2; i<n; i++){ //loop from second index.
        
        int take = INT_MIN;
        
        if((i-2) >= 0)  
            take = dp[i-2] + arr[i];  
        
        
        int notTake = dp[i-1];
        
        dp[i] = max(take,notTake);
    }
    
    return dp[n-1];
}

//Approach 3: space optimization.
//TC-O(N) SC-O(1)
int findMaxSum(vector<int>& arr) {
    int n = arr.size();
    
    int prevOfPrev = arr[0];
    int prev = max(arr[0],arr[1]); //as we required only n-1 and n-2..so create varaible for it.
    
    for(int i = 2; i<n; i++){
        
        int take = INT_MIN;
        
        if((i-2) >= 0)  
            take = prevOfPrev + arr[i]; //take is previous of current previous and arr[i]
            
        int notTake = prev; //not take is just take previous.

        int curr = max(take,notTake); //get max from both.
        prevOfPrev = prev; //update prevofprev.
        prev = curr; //update prev too.
    }
    
    return prev;
}



//Approach 4: using Recursion. Tc-O(2^n) SC-O(N)
//It gives TLE.
int solve(int n, vector<int>&arr){
    
    if(n == 0)
        return arr[0];
        
    if(n == 1)
        return max(arr[0],arr[1]);
        
    int take = INT_MIN;
        
    if((n-2) >= 0)  
        take = solve(n-2, arr) + arr[n];    
    
    int notTake = solve(n-1, arr);
    

    return max(take, notTake);
}

int findMaxSum(vector<int>& arr) {
    int n = arr.size();
    return solve(n-1, arr);
}