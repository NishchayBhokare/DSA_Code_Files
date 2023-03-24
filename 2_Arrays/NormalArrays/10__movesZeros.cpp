// Moves zeros to end.
//GFG
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


//Approach 3- Simple approach and better understanding TC-O(n) SC-O(1)
//Analogy is keeping i on zero element and j on non - zero element so that we can swap.
void pushZerosToEnd(int arr[], int n) {

    int i=0,j=0;
    while(j < n){ //looping till j < length of array
       if(arr[i] != 0)i++; //incrementing i when i stands on non-zero element
       
       else if(arr[i] == 0 && arr[j] != 0) swap(arr[i++],arr[j]); //when ith element is zero and jth element is non zero then swap it.
       
       j++; //and on every iteration increment j, this j will also increment when case like j standing on zero element and i is also standing on zero element.
      } 