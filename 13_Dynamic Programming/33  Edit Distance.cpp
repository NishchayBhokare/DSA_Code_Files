//GFG.
//Edit distance.
//Logic is have recursion over both the string from end. if both ith and jth character matche..then 
//decrement both pointers.
//else call three functions - insertion, deletion and repalce.
//here in three functions..we hypothetically doing operations. by just incrementing count.

//Approach 1: using recursion.
int solve(int i, int j, string &s1, string &s2){
    if(j<0) return i+1;
    if(i<0) return j+1;

    if(s1[i] == s2[j]){
        //if character mataches..then no need to do anything just shrink the string.
        //that means..decrement both pointers.

        return 0+solve(i-1, j-1, s1, s2);
    }

    //do insertion.
    int insertCnt = 1+solve(i, j-1, s1, s2); //if we inserted. then decrement j because...now we have
    //inserted mataching character to j. but still we have to match ith character with j. so don't decrement i.

    //do deletion
    int deleteCnt = 1+solve(i-1, j, s1, s2); //if we delete then decrement i to check for next character but don't decremnet j.

    //do replacement.
    int replaceCnt = 1+solve(i-1, j-1, s1, s2); //similarly if we replace character..then decrement both the string.

    int minCnt = min(insertCnt, min(deleteCnt, replaceCnt)); //just take minimum among all these three operations.
    return minCnt;
}


int editDistance(string& s1, string& s2) {
    int n=s1.length(), m=s2.length();

    return solve(n-1,m-1,s1,s2);
}




//Approach 2: using dp memorization. just addition of dp.
int solve(int i, int j, string &s1, string &s2, vector<vector<int>>&dp){
    
    if(j<0) return i+1;
    if(i<0) return j+1;

    if(dp[i][j] != -1) return dp[i][j];

    if(s1[i] == s2[j]){
        //if character mataches..then no need to do anything just shrink the string.
        //that means..decrement both pointers.

    return dp[i][j] = 0+solve(i-1, j-1, s1, s2, dp);
    }

    //do insertion.
    int insertCnt = 1+solve(i, j-1, s1, s2, dp);

    //do deletion
    int deleteCnt = 1+solve(i-1, j, s1, s2, dp);

    //do replacement.
    int replaceCnt = 1+solve(i-1, j-1, s1, s2, dp);

    int minCnt = min(insertCnt, min(deleteCnt, replaceCnt));
    return dp[i][j] = minCnt;
}


int editDistance(string& s1, string& s2) {
    int n=s1.length(), m=s2.length();
    vector<vector<int>>dp(n,vector<int>(m,-1));

    return solve(n-1,m-1,s1,s2,dp);
}


//Approach 3: using tabulation. TC-O(N*M) SC-O(N*M)
int editDistance(string& s1, string& s2) {
    int n=s1.length(), m=s2.length();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    
    //preparing base case.
    for(int i=0; i<=n; i++){ //these are the base cases..if j is zero..then at dp[i][0] will be i. 
            dp[i][0]=i;
    }
    
    for(int j=0; j<=m; j++){ //similarly for j.
            dp[0][j]=j;
    }
    
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            
            if(s1[i-1] == s2[j-1]){
                
                dp[i][j] = 0 + dp[i-1][j-1];
            }
            else{
                
                //do insertion.
                int insertCnt = 1+dp[i][j-1];

                //do deletion
                int deleteCnt = 1+dp[i-1][j];
            
                //do replacement.
                int replaceCnt = 1+dp[i-1][j-1];
            
                int minCnt = min(insertCnt, min(deleteCnt, replaceCnt));
                dp[i][j] = minCnt;
            }
        }
    }
    
    return dp[n][m]; //return final answer.
}