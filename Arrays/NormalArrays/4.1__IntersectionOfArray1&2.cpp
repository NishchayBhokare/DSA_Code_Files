//Example for finding Intersection(common elements) Of Two Sorted Arrays.
//on coding ninjas

#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;

//Approach 1:- Most Efficient approach(two pointer). TC- O(max(n,m)) and SC is constant.
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
    //given array is sorted.
  int i=0,j=0;
  vector<int> ans={};
  while(i<n && j<m){
      if(arr1[i] < arr2[j]) i++; //first condition when ith element is less than jth element, then no need to check further in jth array cause array is in incresing order, so increment i.
      else if(arr1[i] > arr2[j]) j++; //third condition when ith element is greater than jth element, then increment j, to check for further element.
      else{
		ans.push_back(arr1[i]); //if element is same then push in ans.and increment in i and j.
		i++; j++;
	  }
  }
   return ans;
}


//Approach 2:- Using extra space and counting strategies. TC- O(max(n,m))  SC-(n).
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
    int maxi = 0;
    for(int i=0; i<n;i++) maxi = max(arr1[i],maxi); //first get max element of array arr1.

    vector<int> temp(maxi+1,0); //creating temp vector for storing count of repeated elements. and size is maxi+1, cause maxi is element and size should be maxi+1. (indexing from 0 to maxi)

    vector<int> ans={}; //ans vector, which is initially is empty. 

    for(int i=0; i<n; i++) temp[arr1[i]]++; //incrementing count of repeating element in temp vector.(looping over arr1 array.) 

    for(int j=0; j<m; j++){ //looping over arr2 vector

        if((arr2[j]<=maxi) && (temp[arr2[j]] > 0)){ //first checking arr2[j]th element is small or equal to maxi or not, cause count array has max element is maxi, so if arr2[j] greater than maxi then no need to enter in if block. //second condition is, element at count array should greater than 0.
            ans.push_back(arr2[j]);
            temp[arr2[j]]--; //decrementing count so that it will not get map, for further elements.
        }

    }
    return ans;
}



//Approach 3:- By comparing with every elements TC is O(n2) SC is constant.
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
	// Write your code here.
    vector<int> ans={};
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr1[i] == arr2[j]) { //if element is same then push in ans vector. 
                ans.push_back(arr1[i]);
                arr2[j]=-1; //Assign arr2[j] to -1 so that no other element gets mapped with it on next iteration.
                break; //do break for moving to next iteration.
            }
        }
    }
    return ans;
}