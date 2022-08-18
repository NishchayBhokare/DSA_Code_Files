 // Example for finding duplicate elements and return it.
// link-
    // https://practice.geeksforgeeks.org/problems/rotate-array-by-n-elements-1587115621/1#
 
#include<bits/stdc++.h>
using namespace std;

  // Approach 1: Most efficient approach TC : O(n) SC is constant(in place manipulation).
    void rotateArr(int arr[], int d, int n){
         if(n==0) return ;
         if(d > n) d=d % n; //handling case when d > n;
         int i=0 , j=n-1;
         while(i<j){ //first swapping all elements of array so that it will get reverse.
             swap(arr[i], arr[j]);
             i++; j--;
         }
         for(i=0, j=n-d-1; i<j; i++,j--){ //now reversing from 0 to n-d-1.
             swap(arr[i], arr[j]);
         }
         for(i=n-d, j=n-1; i<j; i++,j--){ //and finally reversing n-d to n-1 elements.
             swap(arr[i], arr[j]);
         }
     }
     
     
// Approach 2: Another approach using reverse function in O(1) space complexity.
// Time complexity is O(n) & space complexity is O(1);
//  void rotateArr(int a[], int d, int n){
//         d%=n;
//         //First reversing d elements from starting index up to the d-1 that is a+d.
//         reverse(a, a+d);
        
//         //Then reversing the last n-d elements.
//         reverse(a+d, a+n);
        
//         //Finally, reversing the whole array.
//         reverse(a, a+n);
//  }
     
    
// Approach 3: Time complexity is O(n) & space complexity is O(k)
//     void rotateArr(int arr[], int d, int n){
//     int temp[d];
//     d=d%n; // to handle d>n situation i.e if d=77 and n=44 then d%n=33. so we have to rotate array by 33.

//     int i=0; // i pointing to starting postion in arr array.
//     for( i;i<d;i++){
//         temp[i]=arr[i]; // storing elements which are before 'd' to new array.
//     }
//     int j=d; //j will point to the first element which are going to shfiting.
//     for(i=0;i<(n-d);i++){ //shifting remaining elements to starting of an array.(overwriting)
//         arr[i]=arr[j];
//         j++;
//     }
//      j=0; // here j is pointing to the starting position in temporary array.
//     for(i;i<n;i++){ //Adding stored element to the main array at the end.
//     // here i value is (n-d).
//         arr[i]=temp[j];
//         j++;
//     }
// }