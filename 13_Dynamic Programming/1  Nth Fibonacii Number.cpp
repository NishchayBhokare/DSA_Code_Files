//GFG. 
//Basically we're storing result of subproblems..so that we further not need to solve those subproblems
//for which we already solved.

APPROACH 1: Using Memorization technique. Top Down Approach. N to base case.
// TC-O(N) SC-O(N+N i.e N)

int solve(int n, vector<int>&dp){
    
    if(n <= 1)
        return n;

        
    if(dp[n] != -1) //if we not found solution for this subproblem..then go and find it.
        return dp[n]; //if we found..that means..dp[n] will have other than -1 value.
        //so no need to solve it again..so return this value.
        
    
    return dp[n] = solve(n-1, dp) + solve(n-2, dp); //store answer in dp array.
}

int nthFibonacci(int n) {
    
    vector<int>dp(n+1,-1); //initialise array with maximum size which can be needed to solve problem.
    //here max size is from 0 to N so initialising array with n+1.

    dp[n] = solve(n,dp);
    
    return dp[n]; //returning final resulat.
}
    
    
    

APPROACH 2: Using Tabulation Technique. Bottom Up Appraoch. base case to N.
// TC-O(N) SC-O(N)
//In memorization technique as we going from top down..and then while returning store answer in vector.
//here we will go bottom up..from base case to top.
//so first store fib of 0 and 1 in dp array.
//loop over 2 to n and store value in dp[i].
int nthFibonacci(int n) {
    
    vector<int>dp(n+1,-1);
    dp[0] = 0;
    dp[1] = 1;
    
    for(int i = 2; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2]; //get value from previous two and store it in dp array
    }
    
    return dp[n]; //return value of it.
}
    

APPROACH 3: With O(1) extra space.
// TC-O(N) SC-O(1)
//The Most optimised way. as we know..if we go from base to top..then there is no need to store value in dp.
//just take two varaibles..and use it..for lat position value and last of last position value.
int nthFibonacci(int n) {
    
    if(n == 1 or n == 0) return n;
    
    int prevOfPrev = 0; //storing first value as 0
    int prev = 1; //second value as 1.
    
    for(int i = 2; i<=n; i++){
        int curr = prev + prevOfPrev; //get addition of last two values and store it into the varaible.
        
        prevOfPrev = prev; //update preofprev to prev..for next iteration.
        prev = curr; //also update prev to curr.
    }
    
    return prev; //return finally curr..or return prev.
}