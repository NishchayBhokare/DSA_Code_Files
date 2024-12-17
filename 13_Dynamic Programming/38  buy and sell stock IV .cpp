//GFG.
//Approach is similar like previous question..just here instead of 2 max transactions..we have max k transactions.

// Approach 1: using recurison.
int solve(int i, int buyStatus, int transCnt, int price[], int &n){
    
    if(i==n || transCnt == 0) return 0;
    
    if(buyStatus){
        
        //buy
        int p1 = solve(i+1, !buyStatus, transCnt, price, n) - price[i];
        
        //not buy
        int p2 = solve(i+1, buyStatus, transCnt, price, n);
        
        return max(p1,p2);
    }
    else{
        
        //sell.
        int p1 = price[i] + solve(i+1, !buyStatus, transCnt-1, price, n);
        
        //not sell.
        int p2 = solve(i+1, buyStatus, transCnt, price, n);
        
        return max(p1,p2);
    }
}

int maxProfit(int transCnt, int n, int price[]) {
    
    int i=0, buyStatus=1;
    return solve(i,buyStatus,transCnt, price, n);
}


//Approach 2: using Memorization.
int solve(int i, int buyStatus, int transCnt, int price[], int &n, vector<vector<vector<int>>>&dp){
    
    if(i==n || transCnt==0) return 0;
    
    if(dp[i][transCnt][buyStatus] != -1) return dp[i][transCnt][buyStatus];
    
    if(buyStatus){
        
        //buy
        int p1 = solve(i+1, !buyStatus, transCnt, price, n, dp) - price[i];
        
        //not buy
        int p2 = solve(i+1, buyStatus, transCnt, price, n, dp);
        
        return dp[i][transCnt][buyStatus] = max(p1,p2);
    }
    else{
        
        //sell.
        int p1 = price[i] + solve(i+1, !buyStatus, transCnt-1, price, n, dp);
        
        //not sell.
        int p2 = solve(i+1, buyStatus, transCnt, price, n, dp);
        
        return dp[i][transCnt][buyStatus] =  max(p1,p2);
    }
}

int maxProfit(int transCnt, int n, int price[]) {

int i=0, buyStatus=1, k=transCnt;
vector<vector<vector<int>>>dp(n,vector<vector<int>>(transCnt+1, vector<int>(2,-1)));
//remember size of transcnt will be + 1 on initialization.

return solve(i, buyStatus, transCnt, price, n, dp);
}



//Approach 3: Using tabulation. Just change in variable for k transactions.

int maxProfit(int transCnt, int n, int price[]) {
    
    int i=0, buyStatus=1, k=transCnt;
    vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(transCnt+1, vector<int>(2,0)));
    
    
    for(int i=n-1; i>=0; i--){
        
        for(int transCnt=1; transCnt<=k; transCnt++){
            
            for(int buyStatus=0; buyStatus<=1; buyStatus++){
                
                if(buyStatus){
                    
                    //buy
                    int p1 = dp[i+1][transCnt][!buyStatus] - price[i]; 
                    
                    //not buy
                    int p2 = dp[i+1][transCnt][buyStatus];
                    
                    dp[i][transCnt][buyStatus] = max(p1,p2);
                }
                else{
                    
                    //sell.
                    int p1 = price[i] + dp[i+1][transCnt-1][!buyStatus];
                    
                    //not sell.
                    int p2 = dp[i+1][transCnt][buyStatus];
                    
                    dp[i][transCnt][buyStatus] =  max(p1,p2);
                }
                
            }
        }
    }
    
    return dp[0][k][1];
}


//Approach 4: Using space optimization.  TC-O(N*K*2) SC-O(2K*2 i.e k).
int maxProfit(int transCnt, int n, int price[]) {
    
    int i=0, buyStatus=1, k=transCnt;
    vector<vector<int>>prev(transCnt+1, vector<int>(2,0));
    vector<vector<int>>curr(transCnt+1, vector<int>(2,0));
    
    for(int i=n-1; i>=0; i--){
        
        for(int transCnt=1; transCnt<=k; transCnt++){
            
            for(int buyStatus=0; buyStatus<=1; buyStatus++){
                
                if(buyStatus){
                    
                    //buy
                    int p1 = prev[transCnt][!buyStatus] - price[i]; 
                    
                    //not buy
                    int p2 = prev[transCnt][buyStatus];
                    
                    curr[transCnt][buyStatus] = max(p1,p2);
                }
                else{
                    
                    //sell.
                    int p1 = price[i] + prev[transCnt-1][!buyStatus];
                    
                    //not sell.
                    int p2 = prev[transCnt][buyStatus];
                    
                    curr[transCnt][buyStatus] =  max(p1,p2);
                }
                
            }
            
            prev = curr;
        }
    }
    
    return prev[k][1];
}