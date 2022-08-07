//Example for find first and last occurnece of particular element in the array.
//link-
    // https://practice.geeksforgeeks.org/problems/first-and-last-occurrences-of-x2041/1


#include<bits/stdc++.h>
using namespace std;
//Approach 1 using manula binary search algorithm : TC- O(logN) SC-O(1)
  int binarySearch(vector<int> &arr,int n,int x,int low,int high,int tog){
  int ans=-1; //Initially ans equal to -1. so that if we don't get any element we will return -1.
  while( low <= high){ //looping till low is less than or equla to high.
      int mid=(low+high)/2; // mid equal to low + high / 2
      if(arr[mid]==x) { //if element got found then,
          ans = mid; //assinging mid to ans.
          if(tog==-1) high=mid-1; //if tog is -1, i.e we are looking for first occurence of that element so, we will search in first half i.e high=mid-1.
          else
          low=mid+1; //if tog is not -1, i.e we are looking for last occurence of that element so, we will search in second half i.e high=mid+1.
      }
      else if(arr[mid] < x) { //if element is greater than mid, look for element in second half
          low=mid+1;
      } 
      else  high=mid-1; //if element is smaller than mid, look for element in first half
  }
  return ans;
  }

    vector<int> firstAndLast(vector<int> &arr, int n, int x) {
        vector<int> v;
        int start=binarySearch(arr,n,x,0,n-1,-1); //calling binary search for getting first occurence of particular element.
        int end=binarySearch(arr,n,x,0,n-1,1); //calling binary search for getting second occurence of particular element.
        if(start== -1){ //if start is -1 i.e element is not found.
        v.push_back(-1); //then push -1.
        }
        else
        { //else push start and end occurence.
          v.push_back(start);
          v.push_back(end);
        }
        
     return v;// return vector. 
    }

//Approach 2 using lower bound & upper bound stl : TC- O(logN) SC-O(1)
// In this example we are using lower_bound and upper_bound which is used in case of search an element in logn. Internally it works as binary search.
//lower_bound will give iterator of first occurence of particular element and if element is not found then it will give iterator pointing to next element. 
//In bothe present and absent cases upper_bound will give iterator pointing to next element.\
//to get index of that element we need to minus arr.begin() i.e starting iterator so that we can get index.
//In the case of upper_bound we also need to do -1 so that we can index of that particular element. cause, it always gives index of next element so do -1 

        vector<int> firstAndLast(vector<int> &arr, int n, int x) {
            vector<int> v; //creating one vector to store answer
              auto start=lower_bound(arr.begin(),arr.end(),x) - arr.begin(); //calling lower_bound
             auto end=upper_bound(arr.begin(),arr.end(),x) - arr.begin() -1; //calling upper_bound
             if(start==n || arr[start]!=x) v.push_back(-1); // push -1 in vector, when element is not found then in some case it will reach to end + 1 pos. so we're checking start==size of vector or not and 2nd condition may occur is element is'nt found but start not reach to end + 1. cause, next elem. of that X is present.
             else { //otherwise we got index of element. so add it in vector and return it.
             v.push_back(start); 
             v.push_back(end);
             }
        return v;
        }