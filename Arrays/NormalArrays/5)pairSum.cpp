//Example for returning list of pairs whose sum equals to s.
//on coding ninjas

#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;

//Using two pointer Approach. TC- O(n2) and SC is constant.
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