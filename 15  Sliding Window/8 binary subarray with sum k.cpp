//GFG.

//Approach 1: Most Optimised Approach. TC-O(2*(N+N)) i.e overall O(N), SC-O(N).
//here we have changed the question. as we want to found subarray with sum equals to k.
//but when we try to do it. we will get stuck in situation where sum == k. and that time. what should we
//increment left or right. so because of this. we cannot solve this question by using regular approach.

//we need to think differently. 
//as we know we have to find subarray with exact k sum.
//we can dropdown this question to find subarray with sum less than or equal to k and
//find subarray with sum equals to k-1.
//i.e if you substract No. of subarray less than equals to k - No. of subarray less than equals to k-1.
//then we will get answer that will be number of subarray with sum equals to k.
int solve(vector<int>&arr, int target){
        
    if(target < 0) return 0;
    
    int n=arr.size(), cnt = 0, sum=0, left=0, right=0;
    
    while(right < n){
        
        sum += arr[right];
        
        while(sum > target){
            
            sum -= arr[left];
            left++;
        }
        
        if(sum <= target) cnt+= right-left+1; //this is also one more condition we need to understand.
        //if you observe carefully on every right index whose sum is less than or equal to target.
        //then increment count with length of current substring.
        //why it's like this. if you observe. we are storing all possible substrings which can be formed with 
        //current right index. which are nothing but length. as we are moving left++ so because of this..
        //we have to do above condition. otherwise we will miss some valid sub arrays.
        
        right++;
    }
    
    return cnt;
}

int numberOfSubarrays(vector<int>& arr, int target) {
    
    return solve(arr, target) - solve(arr, target-1); //substract from count of subarray with target - (target-1).
}


//Appraoch 2: TC-O(N2) SC-O(1)
 int numberOfSubarrays(vector<int>& arr, int target) {
    
    int n=arr.size(), cnt = 0;
    
    for(int i=0; i<n; i++){
        
        int sum = 0;
        
        for(int j=i; j<n; j++){
            
            sum += arr[j];
            
            if(sum > target) break;
            
            if(sum == target) cnt++;
        }
    }
    
    return cnt;
}