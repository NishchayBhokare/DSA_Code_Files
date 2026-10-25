//GFG.
//Approach 1: TC-O(N) SC-O(1)
//Convert the counting of odd number subarray problem into previous problem, where sum == k.
//so suppose, you have given array is 3 5 6 1 2 and k=3. we will convert this array into below,
// 1 1 0 1 0 - on for every even we will replace with 0, and for odd will replace with 1.
//so now check that, in given array [1 1 0 1 0] sum == k. i.e sum == 3.
class Solution {
  public:
    int solve(vector<int>&arr, int target){

          int l=0,r=0,cnt=0, n=arr.size(), sum=0;

          while(r<n){

              sum+=(arr[r]%2);

              while(sum>target){
                  sum-=(arr[l++]%2); //if take mod of 2 then even number will be converted into 0 and odd in 1.
              }

              if(sum<=target){
                  cnt += r-l+1;
              }

              r++;

          }

          return cnt;
      }
  
    int countSubarrays(vector<int>& arr, int k) {
        // code here
        return solve(arr,k) - solve(arr,k-1);
    }
};
 
//Approach 2: TC-O(N) SC-O(1).
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