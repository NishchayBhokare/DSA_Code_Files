// Example to check given array is sorted and rotated or not.
// Leetcode.
#include <iostream>
#include <vector>
using namespace std;

//TC-O(n) SC-O(1).
//Analogy: If given array is sorted and rotated that means there will be only one or less than one pair is present for condition i > i+1.
//Zero pair will present when array will be like 1 1 1.
//if there are more than one pair is present that means, array is not sorted.    
    bool check(vector<int>& nums) {
        int count = 0; 
        int n = nums.size();
        for(int i=0; i<n; i++){ //looping from 0 to n.
            if( nums[i] > nums[( (i+1) % n )]) count++; 
            //checking condition for ith element greater than i+1 or not.
            //here we took modulus with n so that last element will compare with first element.
        }   
        return count<=1; //if count is less or equal to 1 then it will return 1, otherwise it will return 0.
    }