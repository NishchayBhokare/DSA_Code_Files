//Leetcode
//Only one valid solution is there for every test case.

#include<bits/stdc++.h>
using namespace std;

//Appraoch 1: TC-O(N) SC-O(N).
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int,int>ump;
        vector<int>ans;

        for(int i=0; i<nums.size(); i++){

            if(ump.find(target-nums[i]) != ump.end()){ //a+b=sum. i.e sum-a = b. so if b is there then add both a's index and b's index in ans.

                ans.push_back(ump[target-nums[i]]);
                ans.push_back(i);
            }


            ump.insert({nums[i], i}); //storing ith value and i index.
        }

        return ans;
    }
};


//Approach 2: Simple approach TC-O(N2) SC-O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int>ans;

        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){

                if(nums[i] + nums[j] == target){
                    ans.push_back(i);
                    ans.push_back(j);
                }
            }
        }

        return ans;
    }
};