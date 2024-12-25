//Leetcode.


//Approach 1: optimised approach. TC-O(N) SC-O(1).
//here logic is we will keep track of two varaibles. mini and maxi.
//it will normal when we encounter opening and closing braces.
//but if we encounter asterisk. then we will decrement mini and increment mini
//so that we can achieve maximum possible range. 

//i.e if we consider asterisk as ) bracket. 
// then it's will be -1 in previous value, if we consider empty char
//then it will be +0 and in case of opening bracket it will be +1. so range is from -1 to +1.
//so by considerting this range minimum possible value we will store it in mini and maximum will be in maxi.
bool checkValidString(string s) {
    
    int mini=0, maxi=0, n=s.length();

    for(int i=0; i<n; i++){

        if(s[i] == '('){
            mini++;
            maxi++;
        }
        else if(s[i] == ')'){
            mini--;
            maxi--;
        }
        else{

            //decrement mini
            mini--;

            //increment maxi.
            maxi++;
        }

        if(mini < 0) //if at any point mini get's less than zero then just reset it to 0.
            mini=0;
        
        if(maxi < 0) //but by chance maxi get's less than 0 that means. there is no range in positive side. because maxi itself is zero.
        //so string is not valid then return false.
            return false;
    }

    return mini==0; //at the end..if mini is zero. that means. string is valid. so return true.
}


//Approach 2: More intiuative TC-O(N) SC-O(2N).
bool checkValidString(string s) {
    stack<int>opening;
    stack<int>asterisk;
    int n=s.length();

    for(int i=0; i<n; i++){

        if(s[i] == '(')
            opening.push(i);
        
        else if(s[i] == '*')
            asterisk.push(i);
        
        else{
            //when we encounter closing bracket.

            if(!opening.empty()) //if opening bracket is present then pop out it.
                opening.pop();
            
            else if(!asterisk.empty()){ //else if asterisk is present then balance it, by considering asterisk is closing bracket.
                asterisk.pop();
            }
            else //but if no previous opening bracket or asterisk to balance then return false.
                return false;
        }
    }


    //now check at the end for stack of opening and asterisk.
    //make sure opening brackets should be stand before index of asterisk.

    if(opening.size() > asterisk.size()) return false; //if size of opening is greater than asterisk..then how we can balance it. no way to balance.
    
    while(!opening.empty() && !asterisk.empty()){

        int opInd = opening.top();
        int astInd = asterisk.top();

        opening.pop();
        asterisk.pop();

        if(opInd > astInd) return false; //if asterisk came before opening..then we cannot match.
    }

    return true;
}



//Approach 3: using recursion. trying all possible ways. TC-O(3^n) SC-O(N)
 bool solve(int i, int op, string &s, int n){
        if(op < 0) return false;

        if(i == n){
            if(op == 0) return true;
            return false;
        }
        
        if(s[i] == '('){
            bool ans = solve(i+1, op+1, s, n);
            if(ans) return true;
        }
        else if(s[i] == ')'){
            bool ans = solve(i+1, op-1, s, n);
            if(ans) return true;
        }
        else{

            //consider as a opening bracket '('
            bool first = solve(i+1, op+1, s, n);

            //consider as closing bracket ')'
            bool second = solve(i+1, op-1, s, n);

            //consider as empty string.
            bool third = solve(i+1, op, s, n);

            if(first || second || third) return true;
        }
       
        return false;
    }
    bool checkValidString(string s) {
        
        int op = 0, n=s.length();

        return solve(0, op, s, n);
    }


//Approach 4: using dp memorization. little optimisation. TC-O(N2). SC-O(N2)
    bool solve(int i, int op, string &s, int n, vector<vector<int>>&dp){
    if(op < 0) return false;

    if(i == n){
        if(op == 0) return true;
        return false;
    }

    if(dp[i][op] != -1){
        return  dp[i][op];
    }
    
    if(s[i] == '('){
        bool ans = solve(i+1, op+1, s, n, dp);
        if(ans) return dp[i][op] = true;
    }
    else if(s[i] == ')'){
        bool ans = solve(i+1, op-1, s, n, dp);
        if(ans) return dp[i][op] = true;
    }
    else{

        //consider as a opening bracket '('
        bool first = solve(i+1, op+1, s, n, dp);
        if(first) return dp[i][op]=true;

        //consider as closing bracket ')'
        bool second = solve(i+1, op-1, s, n, dp);
        if(second) return dp[i][op]=true;

        //consider as empty string.
        bool third = solve(i+1, op, s, n, dp);
        if(third) return dp[i][op] = true;
    }
    
    return dp[i][op] = false;
}
bool checkValidString(string s) {
    
    int op = 0, n=s.length();
    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    return solve(0, op, s, n, dp);
}

