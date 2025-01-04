//Leetcode problem.

//Approach 1: Optimised Approach TC-O(N) SC-O(N)
//return total pair of two sum. Using storing prefix sum. or values.
vector<int> twoSum(vector<int>& nums, int target) {
    
    int n=nums.size();
    unordered_map<int,int>ump;
    vector<int>ans;
    for(int i=0; i<n; i++){

        int moreNeeded = target - nums[i]; //get moreNeeded to be check in map. if present then pair is there else not.

        if(ump.find(moreNeeded) != ump.end()){

            int first = ump[moreNeeded];
            int second = i;

            ans.push_back(first);
            ans.push_back(second);

            break;
        }
        
        ump[nums[i]] = i; //also update current map with it's index.
    }

    return ans;
}



//Approach 2: Brute force Approach TC-O(N2) SC-O(1)
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> ans;
    int n=nums.size();
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(nums[i] + nums[j] == target){
                ans.push_back(i);
                ans.push_back(j);
                
                return ans;
            }
        }
    }

}

