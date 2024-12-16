//GFG.

//Appraoch 1: using recursion. TC-O(2^n + 2^m) SC-O(N+M)
//there are two condition:
//if character of i and j is same..then move for next character and call function.
//i.e. decrement i and j. and call solve function again.

//if character is not matached..then we will call two functions..in which we will decrement first array index.
//and in second call we will increment second array index..so that we will wont miss any character.
int solve(int i, int j, string&str1, string&str2){

    if(i<0 || j<0) return 0; //terminating conditon.

    //same character condition.
    if(str1[i] == str2[j]){
      return 1+solve(i-1, j-1, str1, str2);
    }

    //different character condition.
    //in this situation call two recursive calls so that we cannot 
    //mismatached any character from both the string.

    int first = solve(i-1,j,str1,str2);
    int second = solve(i,j-1,str1,str2);

    return max(first, second); //return max from first and second.
}

int getLCSLength(string & str1, string & str2) {
    int i=str1.length(),j=str2.length();
    return solve(i-1,j-1,str1,str2);
}


//Approach 2: using memorization. TC-O(N*M) SC-O(N*M)+N+M
int solve(int i, int j, string&str1, string&str2, vector<vector<int>>&dp){

    if(i<0 || j<0) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    //same character condition.
    if(str1[i] == str2[j]){
      return dp[i][j] = 1+solve(i-1, j-1, str1, str2, dp);
    }


    //different character condition.
    //in this situation call two recursive calls so that we cannot 
    //mismatached any character from both the string.

    int first = solve(i-1,j,str1,str2,dp);
    int second = solve(i,j-1,str1,str2,dp);

    return dp[i][j] = max(first, second); //return max from first and second.
}


int getLCSLength(string& str1, string& str2) {
    int n = str1.size(), m=str2.size();

    vector<vector<int>>dp(n,vector<int>(m,-1));
    return solve(n-1,m-1,str1,str2, dp);
}


//Approach 3: tabulation.
int getLCSLength(string & str1, string & str2) {
  int n=str1.size(), m=str2.size(), count=0;
  vector<vector<int>>dp(n+1,vector<int>(m+1,0));
  for(int i=1; i<=n; i++){ 
      for(int j=1; j<=m; j++){
          
          if(str1[i-1] == str2[j-1]){
              dp[i][j] = 1 + dp[i-1][j-1]; //if string is equal then take..previous count also.
              
              count = max(count, dp[i][j]);
          }
          else if(dp[i-1][j] > dp[i][j-1]){
            dp[i][j] = dp[i-1][j];
          }
          else
            dp[i][j] = dp[i][j-1]; 
      }
  }

//we can write elese part like this also.
// else{
//         dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
//     }
  return count;
}