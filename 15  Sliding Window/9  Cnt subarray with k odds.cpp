//GFG.

 
//Approach 1: TC-O(N) SC-O(1).
//Question is exactly similar like previous one. just here we have to cnt number of ods which equals to k.
int solve(int n, vector<int>& nums, int k){
    
    if(k<0) return 0;
    
    int left=0, right=0, maxSubStrLen=0, oddCnt=0;
    
    while(right < n){
        
        if((nums[right] % 2) != 0) oddCnt++;
        // oddCnt += nums[right]%2; //we can write like this also.
        
        while(oddCnt > k){
            
            if((nums[left] % 2) != 0) oddCnt--;
            
            left++;
        }
        
        maxSubStrLen += right-left+1;
        
        right++;
    }
    
    return maxSubStrLen;
}

int countSubarray(int n, vector<int>& nums, int k) {
    
    return solve(n, nums, k) - solve(n, nums, k-1); //first calculate answer for number of odds less than equals to k
    //and then calculate for k-1. and substract it from k answer.
} 