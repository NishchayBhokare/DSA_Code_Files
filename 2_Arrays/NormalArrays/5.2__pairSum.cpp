//Example for returning list of pairs whose sum equals to s.
//on coding ninjas

#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;

//Approach 1: Most optimised approach. TC-O(Nlogn) SC-O(N)
vector<vector<int>> pairSum(vector<int> &arr, int k){
   vector<vector<int> > ans;

   unordered_map<int,int> m;

   for(int i=0;i<arr.size();i++){

      int pairs=m[k-arr[i]]; //calculating number of pairs which can make with current element
      while(pairs--){ //looping till pair not gets 0.
         vector<int> temp; //creating temporary vect
         temp.push_back(arr[i]); //pushing current element
         temp.push_back(k-arr[i]); //pushing element which make sum with ith element which will nothing but sum - current element.
         sort(temp.begin(),temp.end()); //sort this temp vector.
         ans.push_back(temp); //push temp vector in ans.
      }
      
      m[arr[i]]++; //incrementing frequency of current element.
   }

   sort(ans.begin(),ans.end()); //finally sort answer and return.
   return ans;
}


//Approach 2: Using two pointer Approach. TC- O(n2) and SC is constant.
vector<vector<int>> pairSum(vector<int> &arr, int s){
    vector<vector<int>> ans; //creating vector of vector ans.

    for(int i=0; i<(arr.size()-1); i++){ //looping from 0 to less than n-1. cause not need to check for last element.

        for(int j=i+1; j<arr.size(); j++){ //looping from i+1 to less than n.

            if(s == (arr[i]+arr[j])){ //if sum of ith and jth element equal to s, then enter in if block.
                vector<int> temp; //creating temporary vector.
                temp.push_back(arr[i]); //pushing ith and jth element in temp vector.
                temp.push_back(arr[j]);
                sort(temp.begin(),temp.end()); //sorting temp vector.
                 ans.push_back(temp); //pushing temp vector in ans vector.
            }

        }
        
    }
    sort(ans.begin(),ans.end()); //sorting ans vector, to get ans in increasing order.
    return ans;
}