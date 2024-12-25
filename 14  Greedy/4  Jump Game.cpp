//GFG.

//Approach 1: very simple approach.
//very simple logic. store maximum jump we can do from ith index. so if we can do 3 jump from ith index.
//then obviously we can do 1,2 jump. so store that maxPossible jump index. and move to next index.
//if we're at the index where index is greater than maxIndex possible to reach then return false.
//because we can't reach to this index.

//One more observation..we have to think..how we can cross zero. if we able to cross zero then we're good to go.
//if array doesn't have any zero value..then we are able to reach to the destination.
bool canReach(vector<int> &arr) {
    
    int n=arr.size(), maxInd=0;
    for(int i=0; i<n; i++){
        
        if(i > maxInd) return false; //if i index is greater than maximum posssible index. then return false.
        
        maxInd = max(maxInd, arr[i]+i); //else take maxmium possible index to which we can reach and store it into the maxindex.
    }
    
    return true; //else return true if we reach till this index.
}



//Approach 2: Using Recursion. not optimised but still solve question.
bool solve(int i, vector<int> &arr, int &n){
    
  if(i >= n-1) return true;
    
  for(int j=arr[i]; j>= 1; j--){
        
      int jump = i+j;
        
      bool ans = solve(jump, arr, n);
      if(ans) return true;
  }
  return false;
}

bool canReach(vector<int> &arr) {
    
    int n=arr.size();
    return solve(0,arr,n);
}