// Rotate array to right by k.
// Leetcode, GFG.
#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;

//Approach 1- Optimize approach (by creating reverse function) TC-O(n) Sc- O(1). 
    void Reverse(vector<int>& nums, int start, int n){ //funciton to reverse an array.
       int i=start, j=(n-1);
        while(i < j){
            swap(nums[i],nums[j]);
            i++; j--;
        }
    }

      void rotate(vector<int>& nums, int k) {
       int n = nums.size();
       k = (k % n); //handling case when k becomes greater than n.
       Reverse(nums,0,(n-k)); //reversing 0 to n-k-1 th part.
       Reverse(nums,(n-k),n); //reversing n-k to n-1 th part.
       Reverse(nums,0,n); //finally reversing whole array. 
    }

//Approach 2- Optimize approach(by using inbuilt reverse function) TC-O(n) Sc- O(1).
     void rotate(vector<int>& nums, int k) {
       int n = nums.size();
       k = (k % n); //handling case when k becomes greater than n. 
          reverse(nums.begin(),(nums.end()-k)); //similarly like 0 to n-k. cause nums.end() stand on n where n is size of array so no need to do -1. 
          reverse((nums.end()-k),nums.end()); //reversing n-k to end.
          reverse(nums.begin(),nums.end()); //finally reversing total array.     
    }


//Approach 3 - Using temporary vector. TC- O(n) SC-O(n).
 void rotate(vector<int>& nums, int k) {
       vector<int> ans; //creating vector for temporary purpose.
       int n = nums.size();
       k = (k % n); //handling case when k becomes greater than n.
       int i = (n - k);
        for(i; i<n; i++) ans.push_back(nums[i]); //pushing all elements from n-k to n in ans vector.
        i = 0;
        for(i; i<(n-k); i++) ans.push_back(nums[i]); //finally pushing elements from 0th to n-k-1 in ans vector.
        nums = ans; //assigning ans to nums vector.
    }


//gfg version, in gfg example we have to shift to the right instead shifting towards left as in above example
 void rotateArr(int arr[], int d, int n){
        d= d%n; //andling case when d becomes greater than n.
        reverse(arr,arr+d); //reverse first d elements 
        reverse(arr+d,arr+n); // reverse remaining elements i.e d to n-1.
        reverse(arr,arr+n); // lastly reverse whole array.
    }
    
    