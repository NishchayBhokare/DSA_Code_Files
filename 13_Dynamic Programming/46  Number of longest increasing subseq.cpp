//GFG.

//Approach: there is shuttle change in longest increasing subsequecen problem.
//the change is..if ith element is greater than jth element and length of subsequence of j+1 equals to i
//that means...there are another way to reach ith element in j+1th steps. so increment count of number of subsequence
//of i by number of subsequnece of j.
int numberofLIS(vector<int>& arr) {
    int n=arr.size(), maxiLen=0;
    vector<int> lenArr(n,1);
    vector<int> noOfSub(n,1);
    
    for(int i=1; i<n; i++){
        
        for(int j=0; j<i; j++){
            
            if(arr[i] > arr[j]){
                
                if(lenArr[j]+1 > lenArr[i]){
                    
                    lenArr[i] = lenArr[j]+1;
                    noOfSub[i] = noOfSub[j]; //inehrit the number of subsequence of j.
                }
                
                else if(lenArr[j]+1 == lenArr[i]){ //new way to reach this ith element so add +j in this.
                    
                    noOfSub[i] += noOfSub[j]; //add value of number of subsequence till j.
                }
            }
        }
        
        maxiLen = max(maxiLen,lenArr[i]); //store maximum value of subsequecne length in maxilen.
    }
    
    //here we're caculating answer. our answer will be maximum length instances and sum of it's value from number of subsequences
    //in noOfSub array.
    int ans = 0;
    for(int i=0; i<n; i++){
        
        if(lenArr[i] == maxiLen){ //if lenght is equals to max length.
            ans += noOfSub[i]; //then add number of subsequence till ith eleemnt. 
        }
    }
    
    return ans; //return final answer.
}