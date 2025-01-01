//GFG.

//Approach 1: Using implementation. TC-O(N) SC-O(1)
void nextPermutation(vector<int>& arr) {
         
        //First Step 1: Find breakpoint.
        int n=arr.size(),ind=-1;
        for(int i=n-2; i>=0; i--){
            
            if(arr[i] < arr[i+1]){
                ind=i;
                break;
            }
        }
        
        //edge case.
        if(ind==-1){
            reverse(arr.begin(), arr.end());
            return;
        }
        
        //Step 2: swap this breakpoint with next smaller element.
        //as we know..to get immediate smallest element we need to traverse from right. i.e from end.
    for(int i=n-1; i>ind; i--){
        if(arr[i] > arr[ind]){
            swap(arr[i],arr[ind]);
            break;
        }
    }
    
    //Step 3: Just reverse right part from break point. as we swap. so element of right part
    //are decreasing order. so we want. as minimum as possible to have right part. so reverse it. and it will
    //convert into ascending order.
    reverse(arr.begin()+ind+1,arr.end());
}

//Approach 2: Using STL. TC-O(N) SC-O(1)
void nextPermutation(vector<int>& arr) {
    next_permutation(arr.begin(), arr.end());
}


//Approach 3: Brute Force Approach TC-O(N! * N).
void solve(int ind, int &n, vector<int>&nums, vector<vector<int>>&ans){

    if(ind == n){
        ans.push_back(nums);
        return;
    }

    for(int i=ind; i<n; i++){
        swap(nums[i], nums[ind]);

        solve(ind+1, n, nums, ans);

        swap(nums[i], nums[ind]);
    }
}

void nextPermutation(vector<int>& nums) {
    vector<int>temp = nums;
    vector<vector<int>>ans;

    int n=nums.size(),ind=0;
    solve(ind,n,nums,ans); //finding all permutations.

    sort(ans.begin(),ans.end());
    int i=0;
    while(i<ans.size()-1){
        if(ans[i] == ans[i+1]){
            ans.erase(ans.begin()+i); //to erasing duplicates.
        }
        else i++;
    }

    int x=ans.size(), y=ans[0].size();
    for(int i=0; i<x; i++){ //now checking current nums matches subarray index.
        bool flag = true;
        for(int j=0; j<y; j++){

            if(ans[i][j] != temp[j]){
                flag = false;
                break;
            }
            
        }

        if(flag){ //if it matched. then next index will be ind+1.
            int ind = i+1;
            if(ind==x) ind=0; //but here is catch. if i+1 goes out of range then make it to 0.
            nums = ans[ind]; // store next posssible permutation and break.
            break;
        }
            
    }

}

