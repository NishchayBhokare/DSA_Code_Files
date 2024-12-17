//GFG.
//Code is similar like previous..we're just tracking transcation count also.
//if transaction count becomes 0 then return 0. and when we sell stock..then decrement transaction cnt by 1.

//Recursive solution. 
int solve(int i, int transCnt, int buyStatus, vector<int>&price, int &n){
    if(i == n || transCnt = 0) return 0;
    
    if(buyStatus){
        
        //buy
        int p1 = solve(i+1, transCnt, !buyStatus, price, n) - price[i];
        
        //not buy
        int p2 = solve(i+1, transCnt, buyStatus, price, n);
        
        return max(p1, p2);
    }
    else{
        
        //sell
        int p1 = price[i] + solve(i+1, transCnt-1, !buyStatus, price, n);
        
        //not sell
        int p2 = solve(i+1, transCnt, buyStatus, price, n);
        
        return max(p1, p2);
    }
}

int maxProfit(vector<int>&price){
    
    int i=0, n=price.size(), transCnt = 2, buyStatus = 1;
    
    return solve(i, transCnt, buyStatus, price, n);
}


//Approach 2: using Memorization. here we're using 3d dp. to store transaction count. which is third field.
 int solve(int i, int transCnt, int buyStatus, vector<int>&price, int &n, 
vector<vector<vector<int>>>&dp){

    if(i == n || transCnt == 0) return 0;
    
    if(dp[i][buyStatus][transCnt] != -1)
        return dp[i][buyStatus][transCnt];
    
    if(buyStatus){
        
        //buy
        int p1 = solve(i+1, transCnt, !buyStatus, price, n, dp) - price[i];
        
        //not buy
        int p2 = solve(i+1, transCnt, buyStatus, price, n, dp);
        
        return dp[i][buyStatus][transCnt] = max(p1, p2);
    }
    else{
        
        //sell
        int p1 = price[i] + solve(i+1, transCnt-1, !buyStatus, price, n, dp);
        
        //not sell
        int p2 = solve(i+1, transCnt, buyStatus, price, n, dp);
        
        return dp[i][buyStatus][transCnt] = max(p1, p2);
    }
}

int maxProfit(vector<int>&price){
    
    int i=0, n=price.size(), transCnt = 2, buyStatus = 1;
    
    vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
    //first initilise 3d vector..inside that..2 d vector and inside that 1 d vector.
    //remember this.
    
    return solve(i, transCnt, buyStatus, price, n, dp);
}


//Approach 3: using Tabulation. Tc-O(N*2*3). SC-O(N*2*3).
int maxProfit(vector<int>&price){
    int i=0, n=price.size(), transCnt = 2, buyStatus = 1;
    
    vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3, 0))); //size will be n+1. 
    
    for(int buyStatus = 0; buyStatus<=1; buyStatus++){ //this is optional..because we already..marked all places as 0.
    //but to know more for u.. i have written.
    //our base in memorization is, for i==n and transCnt==0 return 0. so now, here it means..
    //for dp[n][for any buystatus][and transCnt is 0] = 0. so loop for any bustatus i.e from 0 to 1.
        dp[n][buyStatus][0] = 0;
    }
    
    for(int i=n-1; i>=0; i--){ //loop from n-1.
        
        for(int transCnt=1; transCnt<=2; transCnt++){
            
            for(buyStatus=0; buyStatus<=1; buyStatus++){
                
                if(buyStatus){
        
                    //buy
                    int p1 = dp[i+1][!buyStatus][transCnt] - price[i];
                    
                    //not buy
                    int p2 = dp[i+1][buyStatus][transCnt];
                    
                    dp[i][buyStatus][transCnt] = max(p1, p2);
                }
                else{
                    
                    //sell
                    int p1 = price[i] + dp[i+1][!buyStatus][transCnt-1];
                    
                    //not sell
                    int p2 = dp[i+1][buyStatus][transCnt];
                    
                    dp[i][buyStatus][transCnt] = max(p1, p2);
                }
                
            }
        }
    }
    
    //this indexes will be the last index of every loop..so just return that.
    //i looping till 0, buyCnt will loop till 1 and transCnt will loop till 2.
    return dp[0][1][2];
}


//Approach 4: using space optimization. TC-O(N*2*3) SC-O(6) i.e constant.
int maxProfit(vector<int>&price){
            
    int i=0, n=price.size(), transCnt = 2, buyStatus = 1;
    
    vector<vector<int>>prev(2, vector<int>(3,0)); //creating 2d vector for prev and current.
    vector<vector<int>>curr(2, vector<int>(3,0));
    //we have elminate field for n..because that is not required. we will consider only this prev and curr
    //previous row and current row. whole n is not required.
    
    
    for(int i=n-1; i>=0; i--){
        
        for(int transCnt=1; transCnt<=2; transCnt++){
            
            for(buyStatus=0; buyStatus<=1; buyStatus++){
                
                if(buyStatus){
        
                    //buy
                    int p1 = prev[!buyStatus][transCnt] - price[i];
                    
                    //not buy
                    int p2 = prev[buyStatus][transCnt];
                    
                    curr[buyStatus][transCnt] = max(p1, p2);
                }
                else{
                    
                    //sell
                    int p1 = price[i] + prev[!buyStatus][transCnt-1];
                    
                    //not sell
                    int p2 = prev[buyStatus][transCnt];
                    
                    curr[buyStatus][transCnt] = max(p1, p2);
                }
                
                
                prev = curr;
            }
        }
    }
    
    //this indexes will be the last index of every loop..so just return that.
    //buyCnt will loop till 1 and transCnt will loop till 2.
    return prev[1][2];
}

