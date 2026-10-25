//Leetcode. 
// Max Consecutive Ones III



//Approach 1: Most optimised. using Tc-O(N) SC-O(1).
int longestOnes(vector<int>& nums, int k) {
    
    int left=0, right=0, zeros=0, maxLen = 0, n=nums.size();
    
    while(right<n){

        if(nums[right] == 0){
            zeros++;
        }

        if(zeros > k){ //instead of while we're using if. we're keeping same window. so that it will not get updated with more zeros.
        
            if(nums[left] == 0) zeros--;
            left++;
        }

        if(zeros <= k){
            maxLen = max(maxLen, right-left+1);
        }
        right++;
    }

    return maxLen;
}


//Appraoch 2: Using TC-O(2N) SC-O(1)
int longestOnes(vector<int>& nums, int k) {
    
    int left=0, right=0, zeros=0, maxLen = 0, n=nums.size();
    
    while(right<n){

        if(nums[right] == 0){
            zeros++;
        }

        while(zeros > k){
            if(nums[left] == 0) zeros--;
            left++;
        }

        if(zeros <= k){
            maxLen = max(maxLen, right-left+1);
        }
        right++;
    }

    return maxLen;
}


//TC-O(2N)
int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int l=0,r=0,maxLen=0;
        while(r<n){

            if(nums[r] == 1){
                maxLen = max(maxLen,r-l+1);
                r++;
            }
            else{

                if(k>0){
                    maxLen = max(maxLen,r-l+1);
                    k--;
                    r++;
                }
                else{

                    if(nums[l] == 0)
                        k++;
                    
                    l++;
                }
            }
        }

        return maxLen;
    }



//Approach 3: TC-O(N2) SC-O(1)
int longestOnes(vector<int>& nums, int k) {
    
    int maxLen = 0, n=nums.size();
    for(int i=0; i<n; i++){
        int zeros = 0;
        for(int j=i; j<n; j++){

            if(nums[j] == 0) zeros++;

            if(zeros <= k){
                maxLen = max(maxLen, j-i+1);
            }
            else break;
        }
    }

    return maxLen;
}


