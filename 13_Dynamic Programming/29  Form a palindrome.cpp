//GFG.
//Form a palindrome or minimum insertion to make string palindrome.

//we will find longest palindromic string. and the size of remaning characters will be the
//minimum insertion required. Dry run on multiple examples..u will get.

//Approach 1: using memeorization.

int solve(int i, int j, string &str1, string &str2, vector<vector<int>>&dp){

    if(i<0 || j<0) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    if(str1[i] == str2[j]){
        return dp[i][j] = 1+solve(i-1, j-1, str1, str2, dp);
    }

    int Lcnt = solve(i-1,j,str1,str2,dp);

    int Rcnt = solve(i,j-1,str1,str2,dp);

    return dp[i][j] = max(Lcnt, Rcnt);
}

int findMinInsertions(string &str1) {
    
    int n=str1.length();
    vector<vector<int>>dp(n,vector<int>(n,-1));

    string str2 = str1;
    reverse(str2.begin(), str2.end());

    int lcs = solve(n-1,n-1,str1,str2,dp); //get length of longest common palindromic sequence.

    return (n-lcs); //and finally return n-lcs..that is length minus common palidrommic length.
    //which is nothing but..remaining characters which are not palindromic sequence.
}