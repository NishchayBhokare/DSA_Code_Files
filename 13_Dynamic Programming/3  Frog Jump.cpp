//Code studio.

Approach 1: Recursive approach. 
int solve(int n, vector<int>&heights){

    if(n == 0)
        return 0;
    
    //go by 1 step previous and also calcualte current n index answer.
    int leftMin = solve(n-1, heights) + abs(heights[n]-heights[n-1]);

    int rightMin = INT_MAX;

    //similarly go by 2 step previous and also calculate current n index answer.
    if(n>1)
        rightMin = solve(n-2, heights) + abs(heights[n]-heights[n-2]);

    return min(leftMin,rightMin);
}

int frogJump(int n, vector<int> &heights)
{
    return solve(n-1, heights);
}



Approach 2: Memorization Approach. 
// TC-O(N) SC-O(N)
int solve(int n, vector<int>&heights, vector<int>&dp){

    if(n == 0)
        return 0;
    
    if(dp[n] != -1) //if value at nth index is not equal to -1. then we solved this subproblem.
    //so no need to call further..just return value at that index.
        return dp[n];

    int leftMin = INT_MAX, rightMin = INT_MAX;

    leftMin = solve(n-1, heights, dp) + abs(heights[n]-heights[n-1]);

    if(n > 1)
        rightMin = solve(n-2, heights, dp) + abs(heights[n]-heights[n-2]);

    return dp[n] = min(leftMin,rightMin); //take minimum from left and right and store it in dp array and return it.
}

int frogJump(int n, vector<int> &heights)
{
    vector<int>dp(n,-1); //use dp array with maximum index which is nothing but n.
    dp[n-1] = solve(n-1, heights,dp);

    return dp[n-1];
}



Appraoch 3: Tabulization approach. bottom up approach i.e base case to n.
//TC-O(N) SC-O(N)
int frogJump(int n, vector<int> &heights)
{
    vector<int>dp(n,-1);
    
    dp[0]=0;

    for(int i = 1; i<n; i++){ //go from 1 to n-1.

        int first = dp[i-1] + abs(heights[i] - heights[i-1]); 
        //take previous i-1 answer from dp. and find current answer for i.

        int second = INT_MAX;
        if(i>1) second = dp[i-2] + abs(heights[i] - heights[i-2]);
        //similarly with i-2.

        dp[i] = min(first, second); //then store minimum difference in ith index in dp.
    }

    return dp[n-1]; //and finally return value at n-1 in dp.
}



Approach 4: Using Space Optimization.
//Space optimization approach 
int frogJump(int n, vector<int> &heights)
{
    int prevOfPrev = 0; //creating two varaibles which stores answer of n-1 and n-2 index.
    int prev = 0;

    for(int i = 1; i<n; i++){ //start with 1st index to n-1.

        int first = prev + abs(heights[i] - heights[i-1]);//take n-1 answer from prev variable. + current answer

        int second = INT_MAX;
        if(i>1) second = prevOfPrev + abs(heights[i] - heights[i-2]);
        //similarly..take n-2 answer from prevofPrev variable + current answer
        
        int curr = min(first,second); //get minimum in current.
        prevOfPrev = prev; //point prevofprev to prev
        prev = curr; //and prev to curr.
    }

    return prev; //at the end..we will stand of n-1 as prev..so return prev.
}