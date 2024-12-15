//GFG. 
//cannot do usine dp memorization.

//Approach 1: gives TLE recursive.
int solve(int i, int j, string &str1, string &str2, int count){
    if(i<0 || j<0) return count;

    
    if(str1[i] == str2[j]){
        count = solve(i-1, j-1, str1, str2, count+1);
    }

    int Lcnt = solve(i-1, j, str1, str2, 0);
    int Rcnt = solve(i, j-1, str1, str2, 0);

    return max({count, Lcnt, Rcnt});
}  

int lcs(string &str1, string &str2){
    int n=str1.size(), m=str2.size(), count=0;
    return solve(n-1, m-1, str1, str2, count);
}   


//Approach 2: optimised approach using dp.
 int longestCommonSubstr(string& str1, string& str2) {

    //considering 1 based indexing because we're doing i-1. so store str[i-1] elements in dp[i].
    int n=str1.size(), m=str2.size(), count=0;
    
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    
    for(int i=1; i<=n; i++){ 
        for(int j=1; j<=m; j++){
            
            if(str1[i-1] == str2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1]; //if string is equal then take..previous count also.
                
                count = max(count, dp[i][j]);
            }
            // else dp[i][j]=0; //this is not required as dp have all cells zero.
            
        }
    }
    
    return count;
}