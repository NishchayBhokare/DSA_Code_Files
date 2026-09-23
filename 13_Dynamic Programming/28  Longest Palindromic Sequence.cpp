//GFG.

//Approach 1: Using Memorization, in place, without using second string.
class Solution {
  public:
    
    int solve(int ind1, int ind2, string s, vector<vector<int>>&dp){
        
        if(ind1 > ind2) return 0;
        
        if(ind1 == ind2) return 1;
        
        if(dp[ind1][ind2] != -1)
            return dp[ind1][ind2];
        
        if(s[ind1] == s[ind2]){
            return dp[ind1][ind2] = 2 + solve(ind1+1, ind2-1, s, dp);
        }
        else{
            
            int left = solve(ind1+1, ind2, s, dp);
            int right = solve(ind1, ind2-1, s, dp);
            
            return dp[ind1][ind2] = max(left, right);
        }
    }
  
    int longestPalinSubseq(string &s) {
        
        int n = s.size();
        int ind1=0, ind2=s.size()-1;
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(ind1,ind2,s,dp);
    }
};

//The question is similar like longest common subsequence 25.
//just we need to create another string by reversing given string.
//then quesiton will boils down to find longest common subsequence..and that subsequence will
//be our palindrome for sure.. because..we have reversed the stirng.

//Approach 2: using Memorization. 
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