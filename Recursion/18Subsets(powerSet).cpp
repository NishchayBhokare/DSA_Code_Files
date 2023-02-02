// find subsets of elements from given array 
// GFG.
#include<iostream>
#include<bits/stdc++.h>
using namespace std; 

 //TC - O(2^n) Sc- O(2^n) * O(length of each subset) = O(2^n*length of each subset).
 void solve(vector<int> & nums,vector<int> temp, vector<vector<int>> &ans, int i){ //observe carefully in parameters temporary vector is pass by value, not pass by reference cause we want temp vector of current iteration, not whole temp vector, as like we need whole ans vector so for that we are passing ans by reference, but this is not in case of temp vector so, passing it by value so that new copy will create.

        //Base case
        if(i == nums.size()){ //when i equals to size of nums then base case occurs, cause i gets out of bound.
            ans.push_back(temp); //when i reaches to size of nums, then push temp vector in ans vector.
            return; 
        }

        //Not taking element
        solve(nums,temp,ans,i+1); //not taking any element, just incrementing index i.
        
        //taking element.
        temp.push_back(nums[i]); //here we're taking element, so push nums[i] into the temp vector.
        solve(nums,temp,ans,i+1); //again  call solve function for next index.
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans; //creating ans two dimentational vector to store ans.
        vector<int> temp; // creating temporary vector to store current elements.
        int i=0;//index
        solve(nums,temp,ans,i); //calling solve function
        sort(ans.begin(),ans.end()); //sorting ans vector to get answer in lexicographical order.
        return ans;
    }