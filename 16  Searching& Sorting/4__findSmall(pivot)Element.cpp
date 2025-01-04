//Example for find the smallest element(pivot) in an  rotated sorted array.
//On Leetcode and gfg


#include<bits/stdc++.h>
using namespace std;

//More optimised approach. 
int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        int ans = INT_MAX;
        
        while(low <= high) {
            int mid = (low + high) / 2;
            //checking for left half. if current mid is greater than nums[low] then low is possible answer
            //and as current left part is sorted thtat's why mid is greater than low. so store asnwer of low.
            //and check in right part.
            if(nums[low] <= nums[mid]){
                ans = min(ans, nums[low]);
                low = mid + 1;
            } else {
                ans = min(ans, nums[mid]); //if mid is not greater than low. that means. mid is in right part. so right part
                //is sorted and minimum possible value will be mid itself. so store it. and move to left part.
                high = mid - 1;
            }

        }
        return ans;
    }

//Approach 1 :- using binary search algorithm(optimized algo.) : TC- O(logN) SC-O(1)
int findpivot(vector<int>& arr)
{
  //write your code here
  int low=0;
  int high = arr.size()-1;
  while(low < high){ //looping till low < high
      int mid = low + (high - low)/2;
      if(arr[mid] > arr[high]) low = mid+1; //if mid element is grater than high element that means we have to search in right part for smaller element. 
      else high = mid; //else update high to mid and search in left part.
  }
  return arr[high]; //both low and high pointing to the same element.
}


//Approach 2: Linear Approach TC-O(N) SC-(1).
int findpivot(vector<int>& arr) 
{
    if(arr.size()==1) return arr[0];
    
 for(int i=0; i<arr.size(); i++){
    if(arr[i]>arr[i+1]) return arr[i+1]; //if at any time arr[i] > arr[i+1] means i+1 is the smallest element cause arrays is rotated.      
    // i.e 9, 14, 16, 1, 2, 3 so, here element 1 is a pivot and smallest element.
 }
}