//GFG Geek's Tranining.
//there is ninja's training question is there in code studio.

//Approach 1: using recursion. Gives u TLE.
int solve(vector<vector<int>>&arr, int n, int lastTask){
    if(n == 0){  //this is base case..for base case..check..take maximum from all elements except index lastTask.
        int maxi = INT_MIN;
        for(int i = 0; i<3; i++){
            if(i != lastTask){
                maxi = max(maxi, arr[n][i]);
            }
        }
        return maxi; //and return it.
    }
    
    
    //now similar like base case..check for current row elements.
    int maxi = INT_MIN;
    for(int i = 0; i<3; i++){ //check for current n row. 
            if(i != lastTask){
                
                int curr = arr[n][i] + solve(arr,n-1,i); //take current node value..and call for next row..i.e n-1 with lastTask is i.
                maxi = max(maxi,curr);//store max in maxi.
            }
        }
        
    return maxi; //return answer.
}
    
int maximumPoints(vector<vector<int>>& arr, int n) {
    
    return solve(arr,n-1,3); //3 shows...we're starting so choose any of the task.
}


//Approach 2: Using Memorization. TC-O(N*4*3). SC-O(N)
int solve(vector<vector<int>>&arr, vector<vector<int>>&dp, int n, int lastTask){
    
    //checking whether previously we're calculated or not. for this f(n,lastTask).   
    if(dp[n][lastTask] != -1)
        return dp[n][lastTask];
    
    if(n == 0){   
        int maxi = INT_MIN;
        for(int task = 0; task<3; task++){
            if(task != lastTask){
                maxi = max(maxi,arr[n][task]);
            }
        }
        
        return dp[0][lastTask] = maxi; //store this maximum value in dp array.
    }
    
    
    //now similar like base case..check for current row elements.
    int maxi = INT_MIN;
    for(int task = 0; task<3; task++){
            if(task != lastTask){
                
                int curr= arr[n][task] + solve(arr,dp,n-1,task);
                maxi = max(maxi,curr);
            }
        }
        
    return dp[n][lastTask] = maxi;//store maxi and return that dp value.
}
    
int maximumPoints(vector<vector<int>>& arr, int n) {
    
    vector<vector<int>>dp(n,vector<int>(4,-1));
    
    return solve(arr,dp,n-1,3); //3 shows...we're starting so choose any of the task.
}



//Approach 3: Using Tabulation.
int maximumPoints(vector<vector<int>>& arr, int n) {
    
    vector<vector<int>>dp(n,vector<int>(4,-1)); //creation of dp array.
    
    //preperation of base case.
    for(int lastTask = 0; lastTask<=3; lastTask++){ //for base case..adding all possible values on all three indexes.
    int maxi = INT_MIN;
        
        for(int task = 0; task<3; task++){
            if(task != lastTask)
                maxi = max(maxi,arr[0][task]);
        }
        
        dp[0][lastTask] = maxi;
    }
    
    
    for(int i = 1; i<n; i++){
            
        for(int lastTask = 0; lastTask<=3; lastTask++){ //last task is working till equals to 3 because..we want maximum answer on every row..so 
        //that answer is calculated by lastTask which equals to 3.
            int maxi = INT_MIN;
            
            for(int task = 0; task<3; task++){
                if(task != lastTask){
                    
                    int curr = arr[i][task] + dp[i-1][task];
                    maxi = max(maxi,curr);
                }
            }
            
            dp[i][lastTask] = maxi;
        }
    }
    

 return dp[n-1][3];
}


//Approach 4: Using Space Optimization.
//TC-O(N*4*3) SC-O(4+4)
 int maximumPoints(vector<vector<int>>& arr, int n) {
        
        vector<int>prevVec(4,-1);
        //we're using only 4 size array.
        
        //preperation of base case.
        for(int lastTask = 0; lastTask<=3; lastTask++){
            int maxi = INT_MIN;
            
            for(int task = 0; task<3; task++){
                if(task != lastTask)
                    maxi = max(maxi,arr[0][task]);
            }
            
            prevVec[lastTask] = maxi; //base case will act as previos vector.
        }
        
       
        vector<int>currVec(4,-1); //current vector will point's to current row values.
        for(int i = 1; i<n; i++){

            for(int lastTask = 0; lastTask<=3; lastTask++){
                int maxi = INT_MIN;
                
                for(int task = 0; task<3; task++){
                    if(task != lastTask){
                        
                        int curr = arr[i][task] + prevVec[task]; //chec previous task value from prev array. and store current addition in curr.
                        maxi = max(maxi,curr); //store maximum value in maxi.
                    }
                }
                
                currVec[lastTask] = maxi; //at the end update currVec with maxi.
            }
            prevVec = currVec; //now prevvec points to current vector.
        }
       
       
    
     return prevVec[3]; //return prevVec of last index.
    }