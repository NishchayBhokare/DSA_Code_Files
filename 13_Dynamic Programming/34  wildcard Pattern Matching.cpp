//GFG. 
//we have to match string s1 with s2. if it's match we have to return true else false.

//basically the trickest part are one base case and * case condition.
//for * case. we're doing two things.
//1) we're considering as * is nothing..that means..* matches with nothing in second string.
//so just decrement * string index i.e j--.
//2) we're considering as * matches with one character from second string so decrement second string index
// i.e i. why i, why not j. because..we can match multiple sequences of string with *. so we're doing this in this second function.

//for base case.. there is catch..suppose if character array string is empty but specail character array is still having character.
//so we have to make sure..special character array must have only *. which will be consider as nothing.

//Approach 1: recursive approach. 
bool solve(int i, int j, string &txt, string &pat){
    
    if(i < 0  && j < 0) return true; //if both are empty then return true.
    
    if(j < 0) return false; //if pattern array is empty but txt array is not..then return false.
    
    if(i<0 && j>=0){ //these is the condition..if special character having characters remaning. 
    //so those characters should be * only. if it's not..then return true.
        
        while(j>=0){ //loop till 0. and check.
            if(pat[j--] != '*') return false;
        }
        
        return true;
    }
    
    //check if characters are matching.
    if(i>=0 && j>=0 && txt[i] == pat[j] || pat[j] == '?'){
        
        return solve(i-1, j-1, txt, pat);
    }
    else{
        
        if(pat[j] == '*'){
            
            //for first function call, consider as * means nothing..and move on to check remaining elements..so decrement index j but not i.
            return solve(i, j-1, txt, pat, dp) || solve(i-1, j, txt, pat, dp);
            //for second functin call, consider as current character matches with * so decrement i but not j.
        }
    }
    
    return false;
}

bool wildCard(string &txt, string &pat) {
    
    int n=txt.length(), m=pat.length();
    return solve(n-1, m-1, txt, pat); 
}


//Appraoch 2: using memorization. just addition of dp.
 int solve(int i, int j, string &txt, string &pat, vector<vector<int>>&dp){
        
    if(i < 0  && j < 0) return 1;
    
    if(j < 0 && i>=0) return 0;
    
    if(i<0 && j>=0){ 
        for(int temp=1; temp<=j; temp++){
            
            if(pat[temp-1] != '*'){
                return 0;
            }
        }
        
        return 1;
    }
    
    if(dp[i][j] != -1) return dp[i][j];
    
    //check if characters are matching.
    if(txt[i] == pat[j] || pat[j] == '?'){
        
        return dp[i][j] = solve(i-1, j-1, txt, pat, dp);
    }
    else{
        
        if(pat[j] == '*'){
            
            //for first function call, consider as * means nothing..and move on to check remaining elements..so decrement index j but not i.
            return dp[i][j] = solve(i, j-1, txt, pat, dp) || solve(i-1, j, txt, pat, dp);
            //for second functin call, consider as current character matches with * so decrement i but not j.
        }
    }
    
    return dp[i][j] = 0;
}

bool wildCard(string &txt, string &pat) {
    
    int n=txt.length(), m=pat.length();
    vector<vector<int>>dp(n, vector<int>(m,-1));
    
    return (solve(n-1, m-1, txt, pat, dp) == 1);
} 



//Approach 3: Using tabulation.
  bool wildCard(string &txt, string &pat) {
        
    int n=txt.length(), m=pat.length();
    vector<vector<bool>>dp(n+1, vector<bool>(m+1, false));
    
    
    dp[0][0] = true; //first base case. i.e for  if(i < 0  && j < 0) return 1;
    
    for(int i=1; i<=n; i++) //second base case i.e for if(j < 0 && i>=0) return 0;
        dp[i][0]= false;
        
    
    for(int j=1; j<=m; j++){ //third base case. for refor above memorization.
        
        bool flag = true;
        
        for(int temp=1; temp<=j; temp++){
            
            if(pat[temp-1] != '*'){
                flag = false;
                break;
            }
        }
        
        dp[0][j]=flag;
    }
    
    
    for(int i=1; i<=n; i++){ //one based indexing.
        for(int j=1; j<=m; j++){
    
            //check if characters are matching.
            if(txt[i-1] == pat[j-1] || pat[j-1] == '?'){
                
                dp[i][j] = dp[i-1][j-1];
            }
            else if(pat[j-1] == '*'){
                //for first function call, consider as * means nothing..and move on to check remaining elements..so decrement index j but not i.
                dp[i][j] = dp[i][j-1] || dp[i-1][j];
                //for second functin call, consider as current character matches with * so decrement i but not j.
            }
            else
                dp[i][j] = false;
            
        }
    }
    
    return dp[n][m];
} 