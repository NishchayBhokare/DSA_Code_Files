//Find permutations of string.
//GFG
    // Input: ABC
    // Output:
    // ABC ACB BAC BCA CAB CBA
    // Explanation:
    // Given string ABC has permutations in 6 
    // forms as ABC, ACB, BAC, BCA, CAB and CBA 

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//TC - O(4^n * N),  SC-  O(N).
void solve(string str, vector<string> &ans, int index)
{
    if (index == str.length())
    {
    //for(int i=0; i<ans.size(); i++) if(str == ans[i]) return; //before pushing into ans vector, we can check whether current string is present in ans vector or not. so that duplicate strings will not present in ans vector. (To remove duplicate str)

        ans.push_back(str); //pushing current string into ans vector, when index reaches to the length of current str
        return;//returning.
    }

    for (int i = index; i < str.length(); i++) //looping from i equals to index value to the i less than string str length, to iterate over given string.
    {
        swap(str[i], str[index]); //First swap ith with index.
        solve(str, ans, index + 1); //call solve function for next index value

        // Backtrack position.
        swap(str[i], str[index]); //to restore previous position of current string, we need to backtrack, so this is situation of backtrack, where we are swapping ith value with index value to restore previous position.
    }
}

vector<string> find_permutation(string str)
{
    vector<string> ans;
    int index = 0;
    solve(str, ans, index);
    sort(ans.begin(), ans.end()); //sorting ans to get answer in lexiograhical order
    ans.erase(unique(ans.begin(), ans.end()), ans.end()); //to remove duplicate strings from string vector.
    // // or for(int i=0; i<ans.size()-1; i++){
	// 	        if(ans[i] == ans[i+1]){
	// 	            ans.erase(ans.begin()+i); //to erase.
	// 	        }
	// 	    }
    return ans;
}


//Apporach 2: TC-O(!N*N) SC-O(N)
//We are using data stucutre to check current element is already taken or not.
//and pushing that element in ds data structure.
//on every recursive call..checking from 0th index to last index...can we add current
//element or not. if we can add..then add that element and marked it as true.
//and call recursive function..so that..and while coming back from function..
//just retrive the original position by doing back track.
///we are mapping index with mapping data structure instead of their values..
//because values are unique.
//and storing values in ds data structure.
 void findPermutation(vector<int>& nums, vector<vector<int>>&ans, vector<bool>mapping, vector<int>ds){
        if(ds.size() == nums.size()){
            ans.push_back(ds);
            return;
        }

        for(int i = 0; i<nums.size(); i++){
            if(!mapping[i]){
                mapping[i] = true;
                ds.push_back(nums[i]);

                //recursive call
                findPermutation(nums,ans,mapping,ds);

                mapping[i] = false;
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<bool>mapping(nums.size(),false);
        vector<int>ds;

        findPermutation(nums,ans,mapping,ds);
        return ans;
    }