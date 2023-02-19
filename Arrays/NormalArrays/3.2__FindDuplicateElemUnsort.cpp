// Example for finding duplicate elements. More than one duplicate distinct element is present. (GFG)
// link-
    // https://practice.geeksforgeeks.org/problems/remove-duplicates-from-unsorted-array4141/1#

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


//Approach 1: TC -O(n), SC-O(1) No extra space other than ans vector.
//Making given array as count array because array have elements from 0 to n-1.
 vector<int> duplicates(int arr[], int n) {
        vector<int>ans;
        for(int i=0; i<n; i++){ //looping 
            int index=arr[i]%n; //extracting index for that ith element, taking modulus of n because, to get orginal value present at that ith index in original given array.
            arr[index]+=n; //after extracting index, at that index adding n i.e length of given array.
        }
        for(int i=0; i<n; i++){
            if( (arr[i]/n) >= 2) ans.push_back(i); //if we divide that ith element by n, and value gets equla to 2 or greater than it, that means we added n value more than one times on that index, so that index is nothing but duplicate element, so push that index in ans vector.
        }
        
        if(ans.size()==0) return {-1}; //if there is no duplicate element is present, then by creating just vector return -1.
        
        return ans; //else, return ans with duplicate element.
    }

//Approach 2: Using set and vector. TC-O(n) SC -O(No. of duplicate element)
 vector<int> removeDuplicate(int A[], int N) {
       unordered_set<int> s; //we are using hashing here.
       vector<int> v;
       for(int i=0;i<N;i++){ //Iterating over the array.
          if(s.find(A[i])==s.end()){ 
        // checking whether current element is already present in hash table or not. if not then put it in
        // hashtable and also in vector.
              s.insert(A[i]);
              v.push_back(A[i]);
          }
       }
       return v;
   }


//Approach3: Using extra vector. TC-O(n) SC -O(n) <--Extra space for temporary vector.
  vector<int> duplicates(int arr[], int n) {
        // code here
        vector<int>temp(n,0); //creating temporary vector.
        vector<int>ans; //answer vector to return answer.
        for(int i=0; i<n; i++) temp[arr[i]]++; //looping and incrementing value in temporary vector for that particular duplicate element.
        for(int i=0; i<temp.size(); i++) if(temp[i] > 1) ans.push_back(i); //if value at ith is greater than 1 that means that ith index is duplicate element in given array so push it into ans vector.
        if(ans.size() > 0 ) return ans; //if duplicate element is present then return ans vector with duplicate elements.
        else return {-1}; //If not present return vector with -1.
    }


