//Example for finding duplicate element from an array.
//on coding ninjas

#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;



//Approach1:- most efficient. TC- O(n) SC-O(1).
//Take xor of all array elements with number 1 to n-1.
int findDuplicate(vector<int> &arr) 
{
   int ans=0; 
   for(int i=0; i<arr.size();i++){ //take xor of all array elements.
       ans = ans ^ arr[i];
   }

   for(int i=1; i<arr.size();i++){// take xor of ans with 1 to n-1 no. so that twice elements gets cancelled and thrice element i.e remaining will be our ans.
       ans = ans ^ i;
   }
   return ans;
}


//Approach 2: using extra space and counting strategies TC- O(n) SC-O(max(arr[i])).
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


//using sorting nlogn. (TLE- Time Limit Exceeded)
int findDuplicate(vector<int> &arr) 
{
   sort(arr.begin(),arr.end());
    for(int i=0; i<(arr.size()-1); i++){
        if(arr[i] == arr[i+1]) return arr[i];
    }
}
