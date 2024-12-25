//GFG.

//Approach 1: most optimised approach TC-O(N) SC-O(1).
int minCandy(vector<int> &ratings) {
    int n=ratings.size();
    
    int sum = 1;
    
    int i=1;
    while(i<n){
        
        if(ratings[i] == ratings[i-1]){
            sum+=1;
            i++;
            continue;
        }

        int peak=1; //peak started from 1. because..when new incresing slop started. then we will get initial value is
        // 1 so that..before adding into the sum..it will be peak++. so peak will be 2.
        while(i<n && ratings[i] > ratings[i-1]){ //increasing slope.
            peak++;
            sum += peak;
            i++;
        }
        
        int down = 0; //starting from down zero. because if you observe..when new downfall started we can assign them as down started from 0.
        //so before adding for first element of downfall. down will be 0+1. and then added to sum.
        while(i<n && ratings[i] < ratings[i-1]){ //decreasing slope
            down++;
            sum+=down;
            i++;    
        }
        
        down++; //we need to increemnt down count. observe value for peak element. we need to increment down for peak eleent.
        if(down > peak){ //now check down greater than peadk or not. if yes then add different in sum. because we already added peak.
            sum+= down-peak;
        }
    }
    
    return sum;
}



//Approach 2: using one extra array. TC-O(N) SC-O(N).
    int minCandy(vector<int> &ratings) {
    int n=ratings.size();

    vector<int>left(n,1);
    
    for(int i=1; i<n; i++){
        
        if(ratings[i] > ratings[i-1]){
            left[i] = 1 + left[i-1];
        }
    }
    
    //considerting right elements.
    for(int i=n-2; i>=0; i--){
        
        if(ratings[i] > ratings[i+1]){
            int candies = 1 + left[i+1]; //one the way calculating value from right.
            left[i] = max(candies,left[i]);
        }
    }
    
    or we can do like this also.
    // int right=1,curr=1;
    // for(int i=n-2; i>=0; i--){
        
    //     if(ratings[i] > ratings[i+1]){
    //         curr = 1 + right;
    //         left[i] = max(left[i], curr);
    //         right = curr;
    //     }
    //     else{
    //         curr = 1;
    //         right = 1;
    //     }
    // }
    
    
    int sum = 0;
    
    for(int i=0; i<n; i++) 
        sum += left[i];
    
    return sum;
}



//Approahc 3: using two extra array left and right. TC-O(N) SC-O(2N)    //TC-O(N) SC-O(2N)
int minCandy(vector<int> &ratings) {
    
  int n=ratings.size();
    
  //considering left elements.
  vector<int>left(n,1);
    
  for(int i=1; i<n; i++){
        
      if(ratings[i] > ratings[i-1]){
          left[i] = 1 + left[i-1];
      }
    }
    
    //considerting right elements.
    vector<int>right(n,1);
    for(int i=n-2; i>=0; i--){
        
        if(ratings[i] > ratings[i+1]){
            right[i] = 1 + right[i+1];
        }
    }
    
    
    int sum = 0;
    
    for(int i=0; i<n; i++)  //take maximum of it.
        sum += max(left[i], right[i]);
    
    return sum;
}