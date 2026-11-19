//Leetcode.
class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());

        int ans = INT_MAX, n=nums.size();
        
        //3 ways to get Min score
    
        //1. Consider changing first and second position element.
        ans = min(ans, nums[n-1] - nums[2]);

        //2. Consider changing last and second last.
        ans = min(ans, nums[n-3] - nums[0]);

        //3. Consider changing first and last.
        ans = min(ans, nums[n-2] - nums[1]);
        
        return ans;
    }
};