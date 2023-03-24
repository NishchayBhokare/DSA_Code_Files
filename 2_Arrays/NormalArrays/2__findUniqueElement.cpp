//Example for finding unique element from an array.
//on coding ninjas
//second problem from GFG.
#include<iostream>
#include<math.h>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

//Approach 1: Coding ninja. Efficient approach, By taking xor of all elements. TC- O(n) SC-O(1).
//if we take xor of all elements then we will get the element which will be unique element. 
int findUnique(int *arr, int size)
{
  int ans = 0;
    for(int i=1; i<size; i++){
        ans = ans ^ arr[i]; //take xor and store it in ans.
    }
    return ans;
}



//Approach 2: using extra space and counting strategies TC- O(n) SC-O(max(arr[i])).
int findUnique(int *arr, int size)
{
    int maxi=INT_MIN; //initialzing maxi to intMin.
    for(int i=0; i<size; i++) if(arr[i] > maxi) maxi = arr[i];  //looping over array to get max element of given arrya.
    int v[maxi+1]={0}; //creating temporary array of size maxi+1, cause indexing starts from 0.
    for(int i=0; i<size; i++) v[arr[i]]++;  //incrementing count of particular element in temporary vector v.
    for(int i=0; i<=maxi; i++)  if(v[i]==1) return i;  //checking if v[i] is equal to 1, that means ith index which refers to element in array arr. is unique element. 
}



//Example from GFG- Given an array of size n which contains all elements occurring in multiples of K, except one element which doesn't occur in multiple of K. Find that unique element.

//Approach 1: Using map. TC-O(N) SC-O(N) 
int findUnique(int a[], int n, int k) {
      unordered_map<int,int> mp;
      for(int i=0; i<n; i++){ //iterating over array and incrementing count in map for that element
          mp[a[i]]++;
      }
      
      for(auto i:mp){ //looping over map, 
          if( (i.second % k) != 0) return i.first; //if i.second that is if frequency of element is in multiple of k that means element is present k times so if we take modulus with k then answer should be 0, if answer i.e remainder is not zero that means element is not present k times, so return element i.e i.first.
      }
  }

//Approach 2: Good Practice. TC- O(nlogn) SC-O(1).
   int findUnique(int a[], int n, int k) {
        sort(a,a+n); //first sort given array so that we can compare elements.
        for(int i=0; (i+k-1)<n; i=(i+k)){ //looping from i to 0, incrementing
            if( a[i] != a[i+k-1]) return a[i]; //checking ith element with with kth-1 element, if it is not equal then return ith element.
        }
      return a[n-1]; //because we're checking condition, i+k-1 should be less than n, so someties if that unique element is presnt at last of array, then we were not able to return it from for loop because of specified condition, so to return that element at last returning n-1th element.
    }

//Approach 2: Bad Practice but solved problem on gfg. TC- O(n) SC-O(1).
//Bad practice because, we not specified condition i.e i+k-1 < n; instead this we specify, i<n; because of this if ith element is last from array then, it will compare with garbage value becuase, i+k-1 i.e index will be out of bound from array index, so to avoid this specify condition like in approach 1.
    int findUnique(int a[], int n, int k) {
      sort(a,a+n);
      for(int i=0; i<n; i+=k){
          if(a[i] != a[i+k-1]) return a[i];
      }
    }