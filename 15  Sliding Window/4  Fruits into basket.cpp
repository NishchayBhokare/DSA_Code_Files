//GFG.
//Approach is similar like previous problem. but here we're using map to track frequency of any fruit.
//if map size exceeds the basket count 2. then we need to shrink left.
//and before shrinking make sure u decrement frequency of leftth fruit.
//after decrement, if frequency is zero then delete that fruit from map.
//and also move left to next.

//Appraoch 1: TC-O(N) SC-O(3)
int totalFruits(vector<int> &arr) {
    
    int maxLen = 0, left=0, right=0, n=arr.size();
    unordered_map<int,int>ump;
    
    while(right< n){
        
        ump[arr[right]]++;
        
        if(ump.size() > 2){ //for most optimization. we can just use if block instead of while. as we're not allow to update length. when it's invalid because we're shrinking left by 1.
        //so even if map contains more than 2 fruits. but still length will be same like previous lenght. it will not goes beyond it.
        //and once if fruit get's deleted then lenght will increase and we can update max length.
            ump[arr[left]]--;
            
            if(ump[arr[left]] == 0) ump.erase(arr[left]);
            
            left++;
        }
        
        if(ump.size() <= 2){
            maxLen = max(maxLen, right-left+1);
        }
        
        right++;
    }
    
    return maxLen;
}


    
//Approach 2: TC-O(2N) SC-O(3)
int totalFruits(vector<int> &arr) {
    
    int maxLen = 0, left=0, right=0, n=arr.size(), basket=0;
        unordered_map<int,int>ump;
    
    while(right< n){
        
        ump[arr[right]]++;
        
        while(ump.size() > 2){
            ump[arr[left]]--;
            
            if(ump[arr[left]] == 0) ump.erase(arr[left]);
            
            left++;
        }
        
        if(ump.size() <= 2){
            maxLen = max(maxLen, right-left+1);
        }
        
        right++;
    }
    
    return maxLen;
}


    //Approach 3: TC-O(N2) SC-O(3)
int totalFruits(vector<int> &arr) {
        
    int maxLen = 0, n=arr.size();
    
    for(int i=0; i<n; i++){
        
        unordered_map<int,int>ump;
        
        for(int j=i; j<n; j++){
            
            if(ump.find(arr[j]) == ump.end()){
                ump[arr[j]] = 1;
            }
            
            if(ump.size() > 2) break;
            
            maxLen = max(maxLen, j-i+1);
        }
    }
    
    return maxLen;
}