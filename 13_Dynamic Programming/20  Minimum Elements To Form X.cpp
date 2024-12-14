//Code studio.

//We have to find number of elements required to form x.
//Approach 1: using Recursion. TC- O(exponential) can't calculate SC-O(Target);
int solve(int ind, int x, vector<int>&num){

    // if(x==0) return 0 //optional..because..this will get's handle at index equals to 0.

    if(ind == 0){ //at base case.
        if((x%num[ind]) == 0){ //if array number is divisible to x and remainder is zero..then return quotient that is 
        //how much times..we need to add num[ind] to become x. and if x is already zero..then division will be zero..so will return 0.
            return x/num[ind];
        }      
        return 1e9; //else return 0.
    }

    int notTake = solve(ind-1, x, num); //not take condition.
    
    int take = 1e8;
    if(x >= num[ind])
        take= 1+solve(ind, x-num[ind], num); //if you are taking current value..then don't decrement index.
        //jus alter the x.


    return min(take,notTake); //return minimum count of value from take and not take.
}

int minimumElements(vector<int> &num, int x)
{
    int ind = num.size()-1;
    int ans =  solve(ind,x,num);

    if(ans == 1e8) return -1;
    return ans;
}



//Approach 2: using DP Memorization TC-O(N*X) SC-O(N*X)+(X)
int solve(int ind, int x, vector<int>&num, vector<vector<int>>&dp){

    // if(x==0) return 0 //optional..because..this will get's handle at index equals to 0.

    if(ind == 0){
        if((x%num[ind]) == 0){
            return x/num[ind];
        }      
        return 1e9;
    }

    if(dp[ind][x] != -1) return dp[ind][x]; //if already calcualte then simply return.

    //not take condition.
    int notTake = solve(ind-1, x, num, dp);
    
    //take condition.
    int take = 1e9;
    if(x >= num[ind])
        take= 1+solve(ind, x-num[ind], num, dp);


    return dp[ind][x] = min(take,notTake);
}

int minimumElements(vector<int> &num, int x)
{
    int n = num.size();
    vector<vector<int>>dp(n,vector<int>(x+1,-1));

    int ans = solve(n-1,x,num,dp);

    if(ans >= 1e9) return -1;
    return ans;
}
