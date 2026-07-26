//leetcode.

//Approach 1. Optimised one. TC-O(N) SC-O(N).
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>ans(nums.size());

        int p=0, n=1;

        for(int i=0; i<nums.size(); i++){

            if(nums[i] >=0 ){
                ans[p] = nums[i];
                p+=2;
            }
            
            else{
                ans[n] = nums[i];
                n+=2;
            }
        }


        return ans;
    }
};


//Approach 2: TC-O(N) SC-O(N+N)
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
       vector<int>positive;
       vector<int>negative;

       for(auto i:nums){
        
        if(i >=0 )
            positive.push_back(i);
        
        else
            negative.push_back(i);
       }

        vector<int>ans;
        for(int i=0; i<positive.size(); i++){
            ans.push_back(positive[i]);
            ans.push_back(negative[i]);
        }    

        return ans;
    }
};