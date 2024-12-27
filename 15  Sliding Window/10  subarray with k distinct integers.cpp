//GFG.

//TC - Optimised Approach. TC-O(N) SC-O(K)
//Approach is similar like previous one. just addition of map here. we're using map here to get number of distinct integers
//in current subarray.

int getSubArrayCnt(vector<int>&arr, int k){
    
    if(k < 0) return 0; //optional case
    
    int n=arr.size(), left=0, right=0, cnt=0;
    unordered_map<int,int>intFreq;
    
    while(right < n){
        
        intFreq[arr[right]]++;
        
        int size = intFreq.size();
        
        while(size > k){
            
            intFreq[arr[left]]--;
            
            if(intFreq[arr[left]] == 0){
                size--;
                intFreq.erase(arr[left]);
            }
            
            left++;
        }
        
        if(size <= k)
            cnt += right - left + 1;
        
        right++;
    }
    
    return cnt;
}

int subarrayCount(vector<int> &arr, int k) {
    
    
    return getSubArrayCnt(arr, k) - getSubArrayCnt(arr, k-1);
}


//Approach 2: Brute force solution TC-O(N2) SC-O(1)
int subarrayCount(vector<int> &arr, int k) {
    
    int n=arr.size(), cnt=0;
    for(int i=0; i<n; i++){
        
        unordered_map<int,int>intFreq;
        
        for(int j=i; j<n; j++){
            
            intFreq[arr[j]]++;
            
            int size = intFreq.size();
        
            if(size > k){
                break;
            }
            
            if(size == k) cnt++;
        }
    }
    
    return cnt;
}