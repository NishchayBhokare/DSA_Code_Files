//Maximum of all subarrays of size k
//gfg

#include<bits/stdc++.h>
using namespace std;
 
 //Approach1: using Deque Tc-O(N) SC-O(K)
 vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        vector<int> ans;
        deque <int> maxi; //creating one deque which will contain maximum element in decreasing order
        
        for(int i=0; i<k; i++){ //processing first k elements.
            while(!maxi.empty() and arr[maxi.back()] <= arr[i]){ //if deques max's back less than current element then simply pop back
                maxi.pop_back();
            }
            
            maxi.push_back(i); //pushing maximum element index.
        }
        
        ans.push_back(arr[maxi.front()]); //finally push answer for first k element, answer will front index's element in arr.
        
        for(int i=k; i<n; i++){ //processing for remaining element
            if(i - maxi.front() >= k){ //checking if front index element is greater than k, that means it is out of range of k size window
                maxi.pop_front(); //pop out that out of range element
            }
            
            //Addtition logic, now again if back elment is less than current element then pop out those small element from deque
             while(!maxi.empty() and arr[maxi.back()] <= arr[i]){
                maxi.pop_back();
            }
            maxi.push_back(i); //and push this current element in deque
            
            ans.push_back(arr[maxi.front()]); //then push back maximum element in ans vector.
        }
        
        return ans; //finally return ans
    }
 
 
 //Approach 2: TC-O(N*k) SC-O(1)
 vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        vector<int> ans;
        for(int i=0; i<= (n-k); i++){ //looping for every index
            int maxi=INT_MIN; //initialise max to int min.
            for(int j=i; j<(i+k); j++){ //processing k elements from index j.
                maxi = max(maxi,arr[j]);
            }
            ans.push_back(maxi); //once k elements processed push that maximum element in ans vector.
        }
        
        return ans;
    }