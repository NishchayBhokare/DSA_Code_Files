//GFG.

//The question is similar like longest common subsequence 25.
//just we need to create another string by reversing given string.
//then quesiton will boils down to find longest common subsequence..and that subsequence will
//be our palindrome for sure.. because..we have reversed the stirng.

//Approach 1: using Memorization. 
int solve(int i, int j, string &s1, string &s2, vector<vector<int>>&dp){
    
    if(i<0 || j<0) return 0;

    if(dp[i][j] != -1)
        return dp[i][j];

    //if character matches.
    if(s1[i] == s2[j])
        return dp[i][j] = 1+solve(i-1, j-1, s1, s2, dp);

    //also do left and right call.
    int Lcnt = solve(i,j-1, s1, s2, dp);

    //also do right call.
    int Rcnt = solve(i-1,j, s1, s2, dp);

    // return dp[i][j] = max(count, max(Lcnt,Rcnt));
    return dp[i][j] = max(Lcnt,Rcnt);
}

int longestPalinSubseq(string &s) {
    string s1=s;

    reverse(s.begin(),s.end());
    string s2=s;

    int n=s.size();

    vector<vector<int>>dp(n,vector<int>(n,-1));

    return solve(n-1,n-1,s1,s2,dp);
}