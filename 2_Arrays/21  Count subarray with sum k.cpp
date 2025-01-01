//GFG. 

//Prefix sum approach.
int countSubarrays(vector<int> &arr, int k) {
    
    int n=arr.size(), cnt=0, preSum=0;
    unordered_map<int,int>mapping;
    
    mapping[0]=1; //initially map sum 0 to 1 freq. because if any element needs prefix sum as 0. then we will have this 1 freq. cnt.
    //suppose ith prefix is 3 and k is 3. then we need 3-3=0 as prefix sum.
    for(int i=0; i<n; i++){
        
        preSum += arr[i];
        
        int removal = preSum - k; //from this removal we will get how many removals are required to get
        //sum k. 
        
        cnt += mapping[removal]; //so those occurences will be nothing but subarray cnt.
        
        mapping[preSum]++; //increment frequency of prefix sum.
    }
    
    return cnt;
}


//Approach 2: Normal brute force approach. TC-O(N2) SC-O(1)
int countSubarrays(vector<int> &arr, int k) {
    
    int n=arr.size(),cnt=0;
    
    for(int i=0; i<n; i++){
        
        int sum=0;
        for(int j=i; j<n; j++){
            
            sum+=arr[j];
            
            if(sum == k)
                cnt++;
        }
    }
    
    return cnt;
}