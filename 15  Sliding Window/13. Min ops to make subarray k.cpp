//3505. Minimum Operations to Make Elements Within K Subarrays Equal Leetcode

//Approach 1: optimised approach.
// TC-O(N*logx(iteration) +   nK(dp));
// SC-O(nk).
class Solution {
public:
    //after finding opsCost for every ith started subarray.
    //calculate the mininimum operations among all operations opsCost stored in opsCost array.
    long long solve(int count, int i, vector<int>&nums, int &x, int &k, 
    vector<long long>&opsCost, vector<vector<long long>>&dp){

        if(count==k) return 0;
    
        long long totalReqSubArrLen = (k-count)*x;
        if(i+totalReqSubArrLen > nums.size()) return LLONG_MAX /4;
        //if required length is 

        if(dp[count][i] != -1) return dp[count][i];

        //take case, when we're considering window.
        long long take = opsCost[i] + solve(count+1, i+x, nums, x, k, opsCost,dp);

        long long notTake = solve(count,i+1,nums,x,k, opsCost,dp);

        return dp[count][i] = min(take, notTake);
    }

    

    long long minOperations(vector<int>& nums, int x, int k) {

        long long leftSum = 0, rightSum=0;
        int count=0;
        int n = nums.size();
        vector<long long>opsCost(n-x+1);

        multiset<int>leftMaxArr;
        multiset<int>rightMinArr;

        //looping over nums array.
        for(int i=0; i<nums.size(); i++){

            if(leftMaxArr.size() <= rightMinArr.size()) {
                leftMaxArr.insert(nums[i]);
                leftSum+=nums[i];
            }
            else {
                rightMinArr.insert(nums[i]);
                rightSum+=nums[i];
            }

            if(!leftMaxArr.empty() and !rightMinArr.empty()){
                
                int leftMax = *leftMaxArr.rbegin();
                int rightMin = *rightMinArr.begin();
                if(leftMax > rightMin){
                    rightMinArr.insert(leftMax);
                    leftMaxArr.insert(rightMin);

                    leftSum=leftSum+rightMin-leftMax;
                    rightSum=rightSum+leftMax-rightMin;

                    leftMaxArr.erase(leftMaxArr.find(leftMax));
                    rightMinArr.erase(rightMinArr.find(rightMin));
                }
               
            }

            if(i<x-1) continue; //if window is not created yet. then first create window so move on.

            long long median= *leftMaxArr.rbegin();

            //get ops required to make array elements equal to median.
            long long leftOps= (median*leftMaxArr.size()) - leftSum;
            long long rightOps = rightSum - (median*rightMinArr.size());
            

            opsCost[i-x+1] = leftOps + rightOps;

            //before moving to next window we have to clear past data.
            if(leftMaxArr.find(nums[i-x+1]) != leftMaxArr.end()){
                leftSum -= nums[i-x+1];
                leftMaxArr.erase(leftMaxArr.find(nums[i-x+1]));
            }
            else {
                rightSum -= nums[i-x+1];
                rightMinArr.erase(rightMinArr.find(nums[i-x+1]));
            }
        }

        //once we get operation cost for every window, then find out minimum ways to get k subarray with minimum operation cost. so for this we will dynamic programming.
        vector<vector<long long>>dp(k+1,vector<long long>(n+1, -1));
        return solve(count,0,nums,x,k,opsCost,dp);
    }
};



















