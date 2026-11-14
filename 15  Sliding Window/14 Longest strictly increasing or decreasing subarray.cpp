
//Leetcode problem.
//Approach 1: TC-O(N) SC-O(1)
//Just remove repetative work from brute case approach.
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        
        int maxLen = 0;

        //checking for strightly increasing.
        int n=nums.size(),l=0, r=0;
        while(r<n){
            
            if(l==r or nums[r] > nums[r-1]){
                maxLen = max(maxLen, r-l+1);
                r++;
            }
            else{
                l=r;
            }
        }


        l=0,r=0;
        while(r<n){
            if(l==r or nums[r] < nums[r-1]){
                maxLen = max(maxLen, r-l+1);
                r++;
            }
            else{
                l=r;
            }
        }

        return maxLen;
    }
};