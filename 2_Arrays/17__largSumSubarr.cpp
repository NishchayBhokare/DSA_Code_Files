// Example for finding Largest Sum of Contiguous Subarray
// link-
    // https://leetcode.com/problems/maximum-subarray/submissions/

#include<bits/stdc++.h>
using namespace std;
//Approach 1 : use of kaden's algo. in different way.
int maxSubArray(vector<int>& nums) { //Time Complexity is O(n).
        int maxSum=nums[0]; //final sum which we are going to return.
        int currSum=nums[0]; //temporary current sum.
        for(int i=1;i<nums.size();i++){ //looping from 1 to n-1.
            currSum=max(nums[i], currSum+nums[i]); //checking and storing greater element betn current element i.e nums[i]  and the currSum + current element. It will help to handle with negative numbers. so that no need to write special condition of kaden's algo. i.e currSum < 0 or not.
            if(currSum > maxSum){ //now, checking currSum is greater or small than maxSum
                maxSum=currSum; //if greater then store it into maxSum. else move on.
            }  
            // maxSum=max(currSum, maxSum);
        }
        return maxSum;
    }


//use of kaden's algorithm.
     int maxSubArray(vector<int>& nums) {
     int currSum=0; int maxSum=INT_MIN; //creating currSum and maxSum variable.
        for(int i=0; i<nums.size();i++){ //looping till size-1.
            currSum+=nums[i]; //adding sum of element in currSum.
            maxSum=max(currSum,maxSum); //now, checking currSum is greater or small than maxSum, if greater then store it into maxSum oterwise move.
            if(currSum < 0) currSum=0; //This is special condition of kaden's algo. where we are handling with negative sum. i.e after adding elements in currSum and if currSum is less than 0 then no need to take that sum. cause that CurrSum is less than 0.
        }
        return maxSum;
     }


     //on gfg
     long long maxSubarraySum(int arr[], int n){
        
        // Your code here
        int i=0; long long currSum=0; long long maxSum=INT_MIN; //creating currSum and maxSum variable.
        while(i<n){ //looping till size-1.
            currSum+=arr[i]; //adding sum of element in currSum.
            maxSum=max(maxSum,currSum); //now, checking currSum is greater or small than maxSum, if greater then store it into maxSum oterwise move.
            if(currSum < 0) currSum=0; //This is special condition of kaden's algo. where we are handling with negative sum. i.e after adding elements in currSum and if currSum is less than 0 then no need to take that sum. cause that CurrSum is less than 0.
            i++;
        }
        return maxSum;
    }