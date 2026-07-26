#include<bits/stdc++.h>
using namespace std;


//Approach 1: Optimised approach. TC-O(N) SC-O(1)
 void pushZerosToEnd(vector<int> arr, int n) {
    int p=0,q=0;
    while(q<n){
        if(arr[q]!=0){
            swap(arr[p],arr[q]);
            q++;p++;
        }
        else{
            q++;
        }
    }



    //Second way only with one loop.
	//    for(q=0;q<n;q++){
	//         if(arr[q]!=0){
	//            swap(arr[p],arr[q]);
	//            p++;
	//        }
	//    }
}



//Approach 2: not much optimised. TC-O(N) SC-O(1)
class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
       int n=arr.size(), i=0, j=0;
       
       while(j<n){
           
           while(arr[j] == 0 && j<n){
               j++;
           }
           
           if(j<n){   
               arr[i++] = arr[j++];
           }
       }    
       while(i<n){
           arr[i++]=0;
       }
    }
};


//Approach 3: Brute force approach. TC-O(N) SC-O(N)
class Solution {
public:
    void pushZerosToEnd(vector<int>& arr) {
        // code here
        vector<int>ans(arr.size(),0);
        
        for(int i=0; i<arr.size(); i++){
            
            if(arr[i] != 0){
                ans.push_back(arr[i]);
            }
        }
        
        arr = ans;
    }
};