//Code studio.
//Basically we have to find..number of instances of string t present in string s.
//so return that count.

//Approach 1: using recursion.
//Approach is call recursion for f(n-1,m-1) then if string i and string j matches.(i is for s and j is for t)
//then call two function..in one function..we're considering we have taken matched string.
//and decrementing both i and j. 
//in second function we're considering we have not taken matched string. so just decrementing i, not j.
//why we're doing in second call becuase..there can be other subsequence will be there in s1. so to match that.
//we should'n decrement index j. which points to t. as we have to caculate number of multiple subsequences in present in s1 of t.

//in else condition if string not matches. then decrement only i and call function again.
//in base case. if at any point. j less than 0 that means..we have matched whole string so return 1.
//but if j is greater than 0 but i is less than 0 that means we're not able to match the string so return 0.


int solve(int i, int j, string &s, string &t){

    if(j<0) return 1;
    if(i<0) return 0;

    //we can write base case like this also.
    // if(i<0 || j<0){
        
    //     if((i<0 && j<0) || (i>=0 && j<0)) return 1;
    //     return 0;
    // }

    if(s[i] == t[j]){

        //call two function..first take this character and decrment both index. or
        //don't take this matching character and just decrement i index.

        //taking.
        int takeMatch = solve(i-1,j-1,s,t);
        int notTakeMatch = solve(i-1,j,s,t); 
        return (takeMatch + notTakeMatch); //take addition of both.
    }
    else{

        int notTakeNotMatch = solve(i-1,j,s,t);
        return notTakeNotMatch;
    }
}

int numDistinct(string s, string t) {
    int n=s.length(), m=t.length();
    return solve(n-1, m-1, s, t);
}



//Approach 2: using memorizatoin. Just converted above code into the memorization.
int solve(int i, int j, string &s, string &t, vector<vector<int>>&dp){

    if(j<0) return 1;
    if(i<0) return 0;


    if(dp[i][j] != -1) return dp[i][j];


    if(s[i] == t[j]){

        int takeMatch = solve(i-1,j-1,s,t,dp);
        int notTakeMatch = solve(i-1,j,s,t,dp);
        return dp[i][j] = (takeMatch + notTakeMatch);
    }
    else{

        int notTakeNotMatch = solve(i-1,j,s,t,dp);
        return dp[i][j] = notTakeNotMatch;
    }
}

int numDistinct(string s, string t) {
    int n = s.length(), m = t.length();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return solve(n-1,m-1,s,t,dp);
}



//Approach 3: using tabulation.
int numDistinct(string s, string t) {
    int n=s.length(), m=t.length();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));

    //preparing base cases.
    for(int i=0; i<=n; i++) //if j is 0. then for any i just put 1.
        dp[i][0]=1;

    for(int j=1; j<=m; j++) //if j is not zero and i is zero..then for any j just put 0.
    //because..we are not able to match stirng.
        dp[0][j]=0;

    //loop from index 1 (by considering 1 based indexing.) because we're comapring i-1, j-1 so.
    for(int i=1; i<=n; i++){
        
        for(int j=1; j<=m; j++){
            if(s[i-1] == t[j-1]){ //matching //just replace recursion in tabulation by additing recursion expression.

                int takeMatch = dp[i-1][j-1]; //instead of calling for recursion..just take previous answer we have stored.
                int notTakeMatch = dp[i-1][j];
                dp[i][j] = (takeMatch + notTakeMatch);
            }
            else{ //not matching.
                int notTakeNotMatch = dp[i-1][j];
                dp[i][j] = notTakeNotMatch;
            }
        }
    }
    return dp[n][m]; //answer will be stored at last index of n and m. because we're coming from 0,0 to n,m
}