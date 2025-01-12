// Example to check given array is sorted and rotated or not.
// Leetcode and GFG
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
        //why less than also..because array elements may have duplicates.
    }


//GFG Version - Check array is sorted or not.
//Approach 1 : Linear approach TC-O(n) SC-O(1)
  bool arraySortedOrNot(int arr[], int n) {
        // code here
        for(int i=1; i<n; i++){
          if(arr[i] < arr[i-1]) return false; //looping from first index and checking current element is less than previous or not, if yes then it is not in increasing order. so return false.
        }
        return true;
    }

//Approach 2: Recursive approach TC-O(n) SC-O(n).
     bool arraySortedOrNot(int arr[], int n) {
      if(n == 1) return true;
      
      if(arr[0] > arr[1]) return false;
      
      return arraySortedOrNot(arr+1,n-1);
    }