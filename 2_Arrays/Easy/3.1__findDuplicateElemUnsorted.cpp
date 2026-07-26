//Example for finding duplicate element from an array. (Only one distinct duplicate element present)
//on coding ninjas

#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;



//Approach1:- Most efficient. TC- O(n) SC-O(1).
//Analogy- first calculate sum of given array, then calculate sum of natural number from 1 to n-1, cause if n=5, then we will calculate sum up to first 4 as, elements present in array is from 1 to 4 with additional duplicate elements so total 5 elements. that's why n-1.
//Finally deducting sum of given array minus sum of first n-1 natural number. sum of array contains additional sum of duplicate element so that will be the answer.
int findDuplicate(vector<int> &arr)
{
    int sum = 0;
    int size = arr.size();
    for(int i=0; i<size; i++) sum+=arr[i]; //sum of given array.
    int n=(size-1);  
    int ExactSum= (n*(n+1))/2; //calculating first n natural number.
    return (sum-ExactSum); //returning final sum by reducing it from natural number sum.
}

//Approach2:- efficient. TC- O(n) SC-O(1).
//array having elements from 1 to n-1.
//Take xor of all array elements with number 1 to n-1.
int findDuplicate(vector<int> &arr) 
{
   int ans=0; 
   for(int i=0; i<arr.size();i++){ //take xor of all array elements.
       ans = ans ^ arr[i];
   }

   for(int i=1; i<arr.size();i++){// take xor of ans with 1 to less than n-1 no. so that twice elements gets cancelled and thrice element i.e duplicate element will be our ans.
       ans = ans ^ i;
   }
   return ans;
}


//Approach 3: using extra space and counting strategies TC- O(n) SC-O(max(arr[i])).
int findDuplicate(vector<int> &arr) 
{
    int size=pow(10,5);
	vector<int>v(size);  
    for(auto i:arr){ 
        v[i]++;  //incrementing count of particular element in temporary vector v.
    }
    for(int i=0; i<v.size(); i++){
        if(v[i] > 1) return i; //checking if v[i] is greater than 1, that means ith index which refers to element in vector arr. is duplicate element. 
    }
}

//Using unordered map
int findDuplicate(vector<int> &arr) 
{
    unordered_map<int,int> mp;
    int ans=0;
    for(int i=0; i<arr.size(); i++){
        mp[arr[i]]++;
    }
    
    for(auto i:mp){
        if(i.second > 1) ans = i.first;
    }
    return ans;
}

//Approach 4:- Using sorting. TC- O(nlogn) SC-O(1). (TLE- Time Limit Exceeded)
int findDuplicate(vector<int> &arr) 
{
   sort(arr.begin(),arr.end()); //sorting array to get arrya in increasing order.
    for(int i=0; i<(arr.size()-1); i++){
        if(arr[i] == arr[i+1]) return arr[i]; //if current element is equal to next element that means element is duplicate so return ith element.
    }
}

