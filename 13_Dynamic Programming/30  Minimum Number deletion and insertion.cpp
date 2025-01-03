//Code Studio.

//Logic is, if we observe carefully the number of deletion will be lcs - length of s1.
//insertion will be lcs - length of s2. so just i did that..nothing fancy.

//Approach 1: using Recursion.
int getLCS(int i, int j, string &s1, string &s2) {

    if(i<0 || j<0) return 0;

    if(s1[i] == s2[j]){
        return 1+getLCS(i-1,j-1,s1,s2);
    }


    //if not same..then call two functions.
    int Lcnt = getLCS(i,j-1,s1,s2);
    int Rcnt = getLCS(i-1,j,s1,s2);

    return max(Lcnt,Rcnt);
}

int canYouMake(string &s1, string &s2){
    int n=s1.length(), m=s2.length();

    int lcsCnt = getLCS(n-1, m-1, s1, s2);

    int numberOfDeletion = n-lcsCnt;
    int numberOfInsertion = m-lcsCnt;
    return (numberOfDeletion + numberOfInsertion);
}


//Approach 2: using Memorization.
int getLCS(int i, int j, string &s1, string &s2, vector<vector<int>>&dp) {

    if(i<0 || j<0) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    if(s1[i] == s2[j]){
        return dp[i][j] = 1+getLCS(i-1,j-1,s1,s2,dp);
    }


    //if not same..then call two functions.
    int Lcnt = getLCS(i,j-1,s1,s2,dp);
    int Rcnt = getLCS(i-1,j,s1,s2,dp);

    return dp[i][j] = max(Lcnt,Rcnt);
}

int canYouMake(string &s1, string &s2){
    int n=s1.length(), m=s2.length();

    vector<vector<int>>dp(n,vector<int>(m,-1));

    int lcsCnt = getLCS(n-1, m-1, s1, s2, dp);

    int numberOfDeletion = n-lcsCnt;
    int numberOfInsertion = m-lcsCnt;
    return (numberOfDeletion + numberOfInsertion);
}



//Using hypothetically deleting and inserting characters.
int solve(int i, int j, string &s1, string &s2, vector<vector<int>>&dp){
    
    if(i<0) return j+1;
    if(j<0) return i+1;

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
    // int replaceCnt = 1+solve(i-1, j-1, s1, s2, dp);

    int minCnt = min(insertCnt,deleteCnt);
    return dp[i][j] = minCnt;
}

int canYouMake(string &s1, string &s2){
    int n=s1.length(), m=s2.length();
    vector<vector<int>>dp(n,vector<int>(m,-1));
    return solve(n-1, m-1, s1, s2, dp);
}