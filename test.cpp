int solve(int i, string &s, string &t, int &n, string &temp){

    if(i==n){
        if(temp == t) return 1;
        return 0;
    }


    //not take.
    int notTake = solve(i+1, s, t, n, temp);

    //take
    temp.push_back(s[i]);
    int take = solve(i+1, s, t, n, temp);
    temp.pop_back();

    return (take+notTake);
}

int numDistinct(string s, string t) {
    
    int n=s.length();
    string temp = "";
    return solve(0,s,t,n,temp);
}



// int solve(int i, string &s, string &t, int &n, string &temp, map<pair<int,string>,int>&dp){

//     if(i==n){
//         if(temp == t) return 1;
//         return 0;
//     }

//     // if(i==0){

        // if(temp == t) return 1;
        // if(temp+s[i] == t)return 1;
    // }

//     if(dp.find({i,temp}) != dp.end()) return dp[{i,temp}];

//     //not take.
//     int notTake = solve(i+1, s, t, n, temp, dp);

//     //take
//     temp.push_back(s[i]);
//     int take = solve(i+1, s, t, n, temp, dp);
//     temp.pop_back();

//     return dp[{i,temp}] = (take+notTake);
// }

// int numDistinct(string s, string t) {
    
//     int n=s.length();
//     map<pair<int,string>,int>dp;
//     // vector<vector<string>>dp(n,vector<string>(n,"-1"));
//     string temp = "";
//     return solve(0,s,t,n,temp,dp);
// }



// int numDistinct(string s, string t) {
    
//     int n=s.length();
//     vector<vector<int>>dp(n,vector<int>(n,-1));
//     string temp = "";


//     return solve(0,s,t,n,temp,dp);
// }