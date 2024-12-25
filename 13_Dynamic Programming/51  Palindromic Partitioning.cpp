//GFG.

//Approach is basically we're doing front partitioning..if till current index..string is palindrome.
//then make parition on this index...in this way..we're working.

//Approach 1: using recursion.
bool checkPalindrome(int i, int j, string &s){
    
    while(i<j){
        
        if(s[i++] != s[j--]) return false;
    }
    return true;
}

int solve(int i, int &n, string &s){
    
    if(i == n) return 0;
    
    int minCnt = INT_MAX;
    
    for(int ind = i; ind<n; ind++){
        
        if(checkPalindrome(i,ind,s)){
            
            int cnt = 1 + solve(ind+1,n,s);
            minCnt = min(minCnt, cnt);
        }
    }

    return minCnt;
}

int palindromicPartition(string &s) {
    
    int i=0, n=s.length();
    
    return solve(i,n,s) - 1;
}


//Approach 2: using Memorization. TC-O(N3) SC-O(N)
//as only index i is vaiable so make one d dp. and store values into it.
int solve(int i, int &n, string &s, vector<int>&dp){
    
    if(i == n) return 0;
    
    if(dp[i] != -1) return dp[i];
    
    int minCnt = INT_MAX;
    
    for(int ind = i; ind<n; ind++){
        
        if(checkPalindrome(i,ind,s)){
            
            int cnt = 1 + solve(ind+1,n,s,dp);
            minCnt = min(minCnt, cnt);
        }
    }

    return dp[i] = minCnt;
}

int palindromicPartition(string &s) {
    
    int n=s.length(), i=0;
    vector<int>dp(n+1,-1);

    return solve(i,n,s,dp) - 1; //doing -1. because at index == n-1 we done parition..which is no use.
    //beause consider stirng having one element 'a' so i will be 0. so doing parition for n-1 i.e 1-1 i.e 0 is not required.
    //so substract 1 from answer.
}



//Approach 3: using tabulation.
int palindromicPartition(string &s) {
    
    int n=s.length();
    vector<int>dp(n+1,0);

    
    for(int i=n-1; i>=0; i--){
        int minCnt = INT_MAX;
        
        for(int ind = i; ind<n; ind++){
            
            if(checkPalindrome(i,ind,s)){
                
                int cnt = 1 + dp[ind+1];
                minCnt = min(minCnt, cnt);
            }
        }

        dp[i] = minCnt;
    }
    
    return dp[0]-1;
}