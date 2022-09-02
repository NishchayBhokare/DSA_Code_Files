//Example for find the pivot index(leftSum & rightSum is equal) or equalibrium.
//here we have to find index of element in unsorted array whose left sum and right sum is equal.
//On Leetcode.


#include<bits/stdc++.h>
using namespace std;


//Approach 1: linear way O(n) SC(1).
int pivotIndex(vector<int>& nums) {
        
        int sum=0,leftSum=0;
        for(auto i:nums) sum+=i; //first calculating sum of all elements in given array.
        
        //As we know we have to find element whose leftsum == rightSum so instead of rightsum we can put (sum - leftsum - num[i]) which will equal to rightSum
        
        for(int i=0; i<nums.size(); i++){
            if(leftSum == sum - leftSum - nums[i]) return i; //if this condition gets equal that means current element is our pivot element.
            leftSum += nums[i]; //before moving to next iteration, adding current nums[i] to leftsum.
        }
        return -1; //if we reach till here that means we did'nt get pivot element so return -1.
    }