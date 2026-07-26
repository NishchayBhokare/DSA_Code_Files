// - Remove Duplicates Sorted Array. GFG
#include<bits/stdc++.h>
using namespace std;


//Approach 1: Better and simplified. TC-O(N) SC-O(N)
class Solution {
  public:
    vector<int> removeDuplicates(vector<int> &arr) {

        vector<int> ans;
        
        ans.push_back(arr[0]);
        
        for(int i=1; i<arr.size(); i++){
            
            if(arr[i]!=arr[i-1])
                ans.push_back(arr[i]);
        }
        
        return ans;
    }
};


//Approach 2: My understandable approach.
class Solution {
  public:
    vector<int> removeDuplicates(vector<int> &arr) {

        vector<int> ans;
        
        int i=0, size = arr.size();
        while(i < size){
            
            while(i < size-1 && arr[i]==arr[i+1])
                i++;
                
            
            ans.push_back(arr[i]);
            i++;
        }
        
        return ans;
    }
};