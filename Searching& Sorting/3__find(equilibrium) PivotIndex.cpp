//Example for find the pivot index(leftSum & rightSum is equal) or equalibrium.
//here we have to find index of element in unsorted array whose left sum and right sum is equal.
//On Leetcode, GFG.


#include<bits/stdc++.h>
using namespace std;


//Approach 1: linear way O(n) SC(1).
int pivotIndex(vector<int>& nums) {
        
        int sum=0,leftSum=0;
        for(auto i:nums) sum+=i; //first calculating sum of all elements in given array.
        
        //As we know we have to find element whose leftsum == rightSum so instead of rightsum we can put (sum - leftsum - num[i]) which will equal to rightSum
        
        for(int i=0; i<nums.size(); i++){
            if(leftSum == sum - leftSum - nums[i]) return i; //if this condition gets equal that means current element is our pivot element.

            // or rightSum = rightSum - a[i]; 
            // if(leftSum == rightSum) return i;

            leftSum += nums[i]; //before moving to next iteration, adding current nums[i] to leftsum.
        }
        return -1; //if we reach till here that means we did'nt get pivot element so return -1.
    }

//Approach 2: Just little change
 int pivotIndex(vector<int>& nums) {
         int totalSum=0;
        for(int i=0; i<nums.size(); i++) totalSum+=nums[i];

        int leftSum=0, rightSum=totalSum;

        for(int i=0; i<nums.size(); i++){
            rightSum = rightSum - nums[i]; //first calculating rightSum and leftSum
            leftSum = totalSum - rightSum - nums[i];
            if(leftSum == rightSum) return i; //checking.
        }
        return -1;
    }


//GFG Example,  1 base indexing.
int equilibriumPoint(long long a[], int n) {
        long long totalSum=0;
        for(int i=0; i<n; i++) totalSum += a[i]; //calculating total sum
        
        int leftSum=0, rightSum=totalSum; //initialising rightsum with totalSum
        for(int i=0; i<n; i++){
            rightSum = rightSum - a[i]; //substracting current element from rightSum to get new rightSum.
            if(leftSum == rightSum) return (i+1); //if same then return i+1, cause of  1 base indexing.
            leftSum += a[i]; //before moving to next iteration, adding current a[i] to leftsum.
        } 
        return -1; //if not present any equilibrium point then return -1.
        
    }