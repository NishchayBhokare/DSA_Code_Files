// Moves zeros to end.
#include <iostream>
#include <vector>
using namespace std;

//Approach 1- Optimize approach TC-O(n) Sc- O(1).
void pushZerosToEnd(int arr[], int n) {
//slight change is no need to right else part. because on else part we are just moving right, so if we use for loop then no need to right else part, cause on every iteration right will increment.
	    int left =0;
	    for(int right =0; right < n; right++){
	        if(arr[right] != 0) { 
	            swap(arr[left],arr[right]);
	            left++;
	        }
	    }
	}

    
//Approach 2-  TC-O(n) Sc- O(1).
void pushZerosToEnd(int arr[], int n) { // Time complexity is O(n)
	  int left=0,right=0;
	   while(right<n){
	      if(arr[right]!=0){ //if other than 0 then swap current element i.e (left) with non-zero element i.e (right)
 	          swap(arr[left],arr[right]);
	          right++;left++; //after swapping moves both left and right.
	      }
	      else{
	          right++; // if zero then move only right variable and keep left variable on zeroth element index so that further we can swap left with right.
	      }
	   }
	}