//GFG.


//Approach 1: using recursion.
int mod = 1003;
int solve(int i, int j, string &s, bool isTrue){
    
    if(i==j){
        if(isTrue){
            if(s[i] == 'T') return 1;
            return 0;
        }
        else{
            
            if(s[i] == 'F') return 1;
            return 0;
        }
    }
    
    
    int ways = 0; //we have to return sum of total ways.
    for(int k=i+1; k<=j-1; k=k+2){
        
        int leftTrue = solve(i,k-1,s,true); //check how many count of true expression is there in left part.
        int leftFalse = solve(i,k-1,s,false); //similarly check for false in left part.
        
        int rightTrue = solve(k+1,j,s,true); //vice versa in right part
        int rightFalse = solve(k+1,j,s,false);

        //below's are the ways for k '&' or k '|' or k '^'
        if(s[k] == '&'){
            
            if(isTrue)
                ways = (ways+(leftTrue * rightTrue))%mod;
                
            else
                ways = (ways + (leftTrue * rightFalse)%mod + (leftFalse * rightTrue)%mod 
                        + (leftFalse * rightFalse)%mod)%mod;
        }
        
        else if(s[k] == '|'){
            
            if(isTrue){
                ways = (ways + (leftTrue * rightFalse)%mod + (leftFalse * rightTrue)%mod 
                        + (leftTrue * rightTrue)%mod)%mod;
            }
            
            else
                ways = (ways + (leftFalse * rightFalse))%mod;
                
        }
        else{
            //s[i] == '^' xor. //T^T = F, T^F=T, F^T=T, F^F=F.
            
            if(isTrue)
                ways = (ways + (leftTrue * rightFalse)%mod + (leftFalse * rightTrue)%mod)%mod;   
            
            else
                ways = (ways + (leftTrue * rightTrue)%mod + (leftFalse * rightFalse)%mod)%mod;
        }
    }
    
    return ways;
}

int countWays(int n, string s){
    
    int i=0, j=n-1;
    bool isTrue = true;
    
    return solve(i,j,s,isTrue);
}




//Approach 2: using memorization.
int mod = 1003;
int solve(int i, int j, string &s, int isTrue, vector<vector<vector<int>>>&dp){
    
    if(i==j){
        if(isTrue){
            if(s[i] == 'T') return 1;
            return 0;
        }
        else{
            
            if(s[i] == 'F') return 1;
            return 0;
        }
    }
    
    if(dp[i][j][isTrue] != -1) return dp[i][j][isTrue];
    
    
    int ways = 0;
    for(int k=i+1; k<=j-1; k=k+2){
        
        int leftTrue = solve(i,k-1,s,1,dp);
        int leftFalse = solve(i,k-1,s,0,dp);
        
        int rightTrue = solve(k+1,j,s,1,dp);
        int rightFalse = solve(k+1,j,s,0,dp);

        if(s[k] == '&'){
            
            if(isTrue)
                ways = (ways+(leftTrue * rightTrue))%mod;
                
            else
                ways = (ways + (leftTrue * rightFalse)%mod + (leftFalse * rightTrue)%mod 
                        + (leftFalse * rightFalse)%mod)%mod;
        }
        
        else if(s[k] == '|'){
            
            if(isTrue){
                ways = (ways + (leftTrue * rightFalse)%mod + (leftFalse * rightTrue)%mod 
                        + (leftTrue * rightTrue)%mod)%mod;
            }
            
            else
                ways = (ways + (leftFalse * rightFalse))%mod;
                
        }
        else{
            //s[i] == '^' xor. //T^T = F, T^F=T, F^T=T, F^F=F.
            
            if(isTrue)
                ways = (ways + (leftTrue * rightFalse)%mod + (leftFalse * rightTrue)%mod)%mod;   
            
            else
                ways = (ways + (leftTrue * rightTrue)%mod + (leftFalse * rightFalse)%mod)%mod;
        }
    }
    
    return dp[i][j][isTrue] = ways;
}


int countWays(int n, string s){
    
    int i=0, j=n-1;
    bool isTrue = 1;
    vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(n+1, vector<int>(2,-1)));
    
    return solve(i,j,s,isTrue,dp);
}