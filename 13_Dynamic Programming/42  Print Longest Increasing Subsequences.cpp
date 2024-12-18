//GFG.

//Approach is similar like we have used to calculate maximum increasing subsequence.
//just addition of parent array to track previous elements..so that we can backtrack..to print
//elements.
vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
    vector<int>dp(n,1); //dp array basically says that..on ith index, what is the longest length of increasing subsequences.
    vector<int>parent(n,-1); //parent array is used to track parnet.
    
    int maxInd=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            
            if(arr[i] > arr[j]){
                
                int currLen = dp[j]+1; //plus 1 for current standing element.
                
                if(currLen > dp[i]){
                    dp[i]=currLen;
                    parent[i]=j; //updating parent.
                }
            }
        }
        
        
        if(dp[i] > dp[maxInd]){ //updating maxINd.
            maxInd = i;
        }
    }
    
    
    int index = maxInd;
    vector<int>ans;
    while(index != -1){ //loopin till index not becomes -1. print the answer.
        
        ans.push_back(arr[index]);
        index = parent[index];
    }
    
    reverse(ans.begin(), ans.end());
    return ans;
}