//Code studio.

//here we have to get maximum cost obtained by cutting rods into the pieces.
//so similar like previous problem.

// Approach 1: using Recursion.
//we will go to all possible paths..and we can select one pieces multiple times..so we will do that
//in take condition.
//here index plus 1 is nothing but..piece weight. and for that price..we have price value in array for that peice index.


int solve(int ind, vector<int> &price, int n){


	if(ind == 0){
		return (n * price[0]); //at the end return ...n*price[0]. suppose n is 3 then..at price[0] is nothing but..we can 
        //we can divide 3 by peice value 1 which is nothing but 3 only..so just multiply three with cost of it.

        // i.e return ((n/ind+1) * price[index]);
	}


	//not take case
	int notTake = 0 + solve(ind-1, price, n);

	//take case
	int rodLen = ind+1;
	int take=0;
	if((rodLen)<=n) //if rodlen is lesser than n then only we can take it.
		take = price[ind] + solve(ind, price, n-rodLen);
	
	return max(notTake,take);
}

int cutRod(vector<int> &price, int n)
{	
	int ind = n;
	return solve(ind-1, price, n);
}



//Approach 2: using memorization. 
int solve(int ind, vector<int> &price, int n, vector<vector<int>>&dp){

	if(ind == 0){
		return (n * price[0]);
	}

	if(dp[ind][n] != -1) return dp[ind][n]; //just addition of dp.

	//not take case
	int notTake = 0 + solve(ind-1, price, n, dp);

	//take case
	int take=0;
	if((ind+1)<=n)
		take = price[ind] + solve(ind, price, n-(ind+1), dp);
	
	return dp[ind][n] = max(notTake,take);
}

int cutRod(vector<int> &price, int n)
{	
	int ind = n;
	vector<vector<int>>dp(ind+1,vector<int>(n+1,-1)); 
	return solve(ind-1, price, n, dp);
}




