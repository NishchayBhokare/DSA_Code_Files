//Leetcode.
// Approach 1: Most optimised approach TC-O(N)

// Every element has only two possible final values: num or num + 1.
// Instead of trying every possible starting value and tracking lastVal, we can directly track 
// the best sequence ending at each value.
class Solution {
public:

    int maxSelectedElements(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<int>dp(nums.back()+2,0);
        int ans = 0;
        for(auto num:nums){

            // Choice 1: Increment current element by 1.
            dp[num+1] = 1 + dp[num];

            // Choice 2: Keep current element unchanged.
            dp[num] = 1 + dp[num-1];

            ans = max({ans, dp[num], dp[num+1]});
        }

        return ans;
    }
};


//Approach 2: Memroization recursive approach. TC-O(N*MaxVal) SC-O(N*MaxVal).
class Solution {
public:
    int solve(int ind, int lastVal, vector<int>& nums,
              vector<vector<int>>& dp) {

        if(ind == nums.size()) return 0;

        if(dp[ind][lastVal] != -1)
            return dp[ind][lastVal];

        // Choice 1: Skip the current element.
        int ans = solve(ind + 1, lastVal, nums, dp);

        // Choice 2: Select without incrementing.
        if(nums[ind] == lastVal) {
            ans = max(ans, 1 + solve(ind + 1, lastVal + 1, nums, dp));
        }

        // Choice 3: Select after incrementing by 1.
        if(nums[ind] + 1 == lastVal) {
            ans = max(ans, 1 + solve(ind + 1, lastVal + 1, nums, dp));
        }

        return dp[ind][lastVal] = ans;
    }

    int maxSelectedElements(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        // The required value can range from 1 to max(nums) + 2.
        int maxVal = nums.back() + 1;

        vector<vector<int>> dp(nums.size(), vector<int>(maxVal + 2, -1));

        int ans = 0;

        // Try every possible starting value.
        for(int start = nums.front(); start <= maxVal; start++) {
            ans = max(ans, solve(0, start, nums, dp));
        }

        return ans;
    }
};



//Approach 3: Tabulation. TC-O(N*maxVal) SC-O(N*maxVal);
// Tabulation approach, but will MLE (Memeory limit excedded).
class Solution {
public:

    int maxSelectedElements(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        // The required value can range from 1 to max(nums) + 2.
        int maxVal = nums.back() + 1;

        vector<vector<int>> dp(nums.size()+1, vector<int>(maxVal + 2, 0));

        // Try every possible starting value.
        for(int lastVal = maxVal; lastVal >= nums.front(); lastVal--) {
   
            for(int ind=nums.size()-1; ind>=0; ind--){

                // Choice 1: Skip the current element.
                int ans = dp[ind + 1][lastVal];

                // Choice 2: Select without incrementing.
                if(nums[ind] == lastVal) {
                    ans = max(ans, 1 + dp[ind + 1][lastVal+1]);
                }

                // Choice 3: Select after incrementing by 1.
                if(nums[ind] + 1 == lastVal) {
                    ans = max(ans, 1 + dp[ind + 1][lastVal+1]);
                }

                dp[ind][lastVal] = ans;
            }
        }

        int ans = 0;
        for(int start = nums.front(); start<=maxVal; start++){
            ans = max(ans, dp[0][start]);
        }

        return ans;
    }
};
