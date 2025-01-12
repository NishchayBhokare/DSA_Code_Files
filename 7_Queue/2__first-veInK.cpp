//First negative integer in every window of size k
//gfg

#include<bits/stdc++.h>
using namespace std;

//Approach: using Deque Tc-O(N) SC-O(K) 
vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int N, long long int K) {
    vector<long long> ans;
    queue<int> q;
    
    for(int i=0; i<K; i++){ //process first k elements, i.e if element is -ve then store it's index in deque
        if(arr[i] < 0 ) q.push(i);
    }
    
    if(q.empty()) ans.push_back(0); //if there is no negative number then push 0.
    else ans.push_back(arr[q.front()]); //else push element of that index number in arr
    
    for(int i=K; i<N; i++){ //loop from kth position to end of array
        if(arr[i] < 0) q.push(i); //if element is -ve then push that index in deque
        
        if(!q.empty() and (i - q.front()) >= K) { //because of this step we are storing index in dequeue, i.e to remove those elements which is not in range of k.
        //checking front element is out of range or not, if out of range then pop out front
        // or we can use this formula too. 
        // q.front() <= (i-k)
            q.pop();
        }
        
        
        if(q.empty()) ans.push_back(0); //if deque is empty then push 0.
        else ans.push_back(arr[q.front()]); //else push element of that index number in arr 
    }

    return ans;
 }

 //similar like above approach but in my way.
     vector<int> printFirstNegativeInteger(vector<int>& arr, int k) {
        // write code here
        vector<int>vec;
        deque<int>dq;
        
        for(int i = 0; i<k; i++){
             if(arr[i] < 0){
                dq.push_back(i);
            }
        }
           
        for(int i = 0; i<=arr.size()-k; i++){
            int j = i+k-1, index;
            
            //adding new element if -ve.
            if(i!= 0 && arr[j] < 0) dq.push_back(j);
            
            //processing .
            if(!dq.empty() && dq.front() >= i && dq.front() <= j)
            {
               index = dq.front();  
               if(index == i){
                dq.pop_front();
               }
               vec.push_back(arr[index]);
            }
            else
                vec.push_back(0);          
        }
        
        return vec;
    }



//Approach 2: But giving TLE TC-O(N*k) SC-O(1)
vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int N, long long int K) {
        vector<long long> ans;
        
        for(int i=0; i < (N-K+1); i++){
            int flag=0;
            for(int j=0; j<K; j++){
                if(arr[j] < 0) {
                    ans.push_back(arr[i+j]);
                    flag=1;
                    break;
                }
            } 
            if(flag == 0) {
                ans.push_back(0);
            }
        }
        
    return ans;
}