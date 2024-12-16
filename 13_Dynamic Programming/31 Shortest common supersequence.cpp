//code studio.

//basically quetion ask to merge s1 and s2 in way that..number of characters in string should be lesser.
//in short..use duplicate elements to reduce length of merged strings.

//Approach 1: using Memorizaiton + tabulation 
//first do lcs. and prepeare grid/dp.
//do memorization with 1 based indexing so that we can use that dp for 
//further getting shortest common supersequence.

int solve(int i, int j, string&str1, string&str2, vector<vector<int>>&dp){

    if(i<0 || j<0) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    //same character condition.
    if(str1[i-1] == str2[j-1]){
      return dp[i][j] = 1+solve(i-1, j-1, str1, str2, dp);
    }

    int first = solve(i-1,j,str1,str2,dp);
    int second = solve(i,j-1,str1,str2,dp);

    return dp[i][j] = max(first, second); //return max from first and second.
}

string shortestSupersequence(string s1, string s2)
{

    int n=s1.length(), m=s2.length();
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    solve(s1.size(), s2.size(), s1,s2,dp);   //prepeare dp using lcs.
     
    string ans="";
    
    int i=n, j=m;
    
    while(i>0 && j>0){ ///i have explained all about this in below, tabulation approach.
        
        if(s1[i-1] == s2[j-1]){
                ans+=s1[i-1];
                i--; j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]){
            ans+=s1[i-1];
            i--;
        }
        else{
            ans+=s2[j-1];
            j--;
        }
    }
    
    while(i>0) {
        ans+=s1[i-1];
        i--;
    }
    
    while(j>0) {
        ans+=s2[j-1];
        j--;
    }
    
    reverse(ans.begin(), ans.end());
    
    return ans;
}



//Approach2: Using tablulation.  
string shortestSupersequence(string s1, string s2)
{

    int n=s1.length(), m=s2.length();
    vector<vector<int>>dp(n+1, vector<int>(m+1,0));
    
    for(int i=1; i<=n; i++){ 
        for(int j=1; j<=m; j++){
            
            if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    
    //once dp prepeared. loop till i > 0 and j>0
    //basically logic is..when we're moving or left. then there will be the situation..where we're eleminating
    //one character when we're moving left or right. so just push that character.
    //simply..if we move up. i.e i-1. then take character i-1 character from first stirng.. 
    //if we're moving left. i.e j-1 then take j-1 character from second string. this -1 because 1 based indexing.
    
    //then when loop get's over...either i will gerater than 0 or j will greter than 0.
    //so whoever is remaing just take there charactesr in answer.
    //and this will be the shortest common supersequence. of string s and t.
    string ans="";
    
    int i=n, j=m;
    
    while(i>0 && j>0){
        
        if(s1[i-1] == s2[j-1]){
                ans+=s1[i-1]; //if character are same...then move diagonal up. and take character from s1[i-1] or s2[j-1]
                i--; j--; //decreemnt both
        }
        else if(dp[i-1][j] > dp[i][j-1]){ //if upper box is greater than left box. then go to upper box.
            ans+=s1[i-1]; //before going up. just add current i to ans by taking string from s1.
            i--;
        }
        else{
            ans+=s2[j-1]; //similarly, if left box is greater than upper box. then move to left. before moving
            //push character of j-1th index in s2 and add in ans.
            j--; //decrement j.
        }
    }
    
    //loop till i and j greater than 0. and add remaning characters in answer.
    while(i>0) {
        ans+=s1[i-1];
        i--;
    }
    
    while(j>0) { 
        ans+=s2[j-1];
        j--;
    }
    
    reverse(ans.begin(), ans.end()); //finally reverse the string..as we are iterating from n,m to 0. so that's why
    //our stirng will be the revesed of required answer.
    
    return ans; ///return answer.
}