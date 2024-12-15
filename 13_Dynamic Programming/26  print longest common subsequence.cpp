//Code studio 

//Approach 1: using tabulation..using grid.
string findLCS(int n, int m,string &s1, string &s2){

	vector<vector<int>>dp(n+1, vector<int>(m+1,0)); //create dp array with n+1 and m+1 size..
    //because we're shifting elements. so that..i-1 or j-1 will not give any issues.

	for(int i=1; i<=n; i++){ //first prepare dp array.
		for(int j=1; j<=m; j++){

			if(s1[i-1] == s2[j-1]){
				dp[i][j] = 1 + dp[i-1][j-1]; //all these conditions are similar like..we count the length
                //of longest subsequence.
			}
			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}	


    //Here is tha catach..we know..our answer will be at location n, m in grid.
    //so pointing i and j to those index.
    //now backtrack from that index in such way that..we will get longest common
    //subsequence string.
	int i=n, j=m; 
	string ans = "";
	while(i>0 && j>0){

		if(s1[i-1] == s2[j-1]){ //if both chracters are same.
			ans+=s1[i-1]; //then take one instance of it.
			i--; j--; //and decrement both.
		}
		else if(dp[i-1][j] > dp[i][j-1]){ //if upper row box is greater than left row box.
			i--; //then go to up...so decrement i.
		}
		else j--; //similarly, go left..so decrement j.
	}

	reverse(ans.begin(), ans.end()); //reverse final answer..as we are backtracking so need to revers answer.
	
	return ans;
}

//Approach 2: brute force approach is as follows.
//logic is push all subsequences in vector.
void solve(int i, int j, string &first, string &second, string temp, vector<string>&vec){
	if(i==first.size() || j==second.size()){ 
		vec.push_back(temp);
		return;
	}
	
	//check character is same or not.
	if(first[i] == second[j]){
		return solve(i+1, j+1, first, second, temp+first[i], vec); //add current character in string
	}
		
	//if character is not same then call two functions.
	solve(i+1,j,first,second,temp,vec);
	solve(i,j+1,first,second,temp,vec);
}

string findLCS(int n, int m,string &first, string &second){
	vector<string>vec;
	
	string temp="";
	solve(0,0,first,second,temp,vec);
	
	string ans="";
	int len=0;
	for(auto i:vec){
		int currLen=i.length();
		if(len < currLen){  //current string length is greater then add this string as ans.
			len = currLen;
			ans = i;
		}
	}
	
	return ans;	
}


//Approach 2: using tabulation in progress.
// will work on this in future




//GFG print all longest common substrings.
void solve(int i, int j, string &first, string &second, string temp, set<string>&st){
        if(i==first.size() || j==second.size()){
            // cout<<temp<<endl;
            st.insert(temp);
            return;
        }
        
        //check character is same or not.
        if(first[i] == second[j]){
            return solve(i+1, j+1, first, second, temp+first[i], st);
        }
            
        
        //if character is not same then call two functions.
        solve(i+1,j,first,second,temp,st);
        solve(i,j+1,first,second,temp,st);
    }
    
    vector<string> all_longest_common_subsequences(string first, string second) {
        set<string>st;
        string temp="";
        solve(0,0,first,second,temp,st);
        
        int len=0;
        for(auto i:st){
            int currLen=i.length();
            len = max(len, currLen);
        }
        
        vector<string>ans;
        for(auto i:st){
            if(i.length() == len){
                ans.push_back(i);
            }
        }
        
        sort(ans.begin(),ans.end());
        
        return ans;
    }