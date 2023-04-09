//Example for kth largest sum contigous Sub-array.
// link- 
    // https://practice.geeksforgeeks.org/problems/k-th-largest-sum-contiguous-subarray/1

#include <bits/stdc++.h>
using namespace std;

//Approach 1 - most efficient approach using min heap. TC- O(N2 * log K) SC- O(k);
int kthLargest(vector<int> &Arr,int N,int K){
    priority_queue<int,vector<int>,greater<int> > pq;

    for(int i=0; i<N; i++){ //using two loops.
        int sum=0; //when i index gets change value of sum will be 0 for new subarray.
        for(int j=i; j < N; j++){ //staring from i index up to the end.
            sum+=Arr[j]; //adding value in sum. i.e sum=sum+Arr[j];

            if(pq.size() != K){
                pq.push(sum);
            }
            else if(sum > pq.top()){
                pq.pop();
                pq.push(sum);
            }
        }
    }
    return pq.top();
}


//Approach 2- using maxheap TC-O(N2 * logn) SC- O(n2);
int kthLargest(vector<int> &Arr,int N,int K){
    priority_queue<int> pq;
    for(int i=0; i< N ;i++){
        int sum=0; 
        for(int j=i; j< N; j++){
            sum+=Arr[j];
            pq.push(sum);
        }
    }

    K--; //cause 0 base indexing we decrement k-- i.e kth element is k-1th element in araay.
    while(K--){ //till k!=0
        pq.pop(); //poping out so that next smallest element will be in top of heap.
    }
    
    //basically we are poping till k-1 th times so if k=4 then 3 times we will pop so that we can get 4th smallest element at the top of heap.
    return pq.top();
}


// Approach 3 - using sorting and while loop TC- O(n2logn) , SC-O(n2)
//in this example we are adding sum of subarray with two pointer and changing sum=0 when new subarray gets start.
    int kthLargest(vector<int> &Arr,int N,int K){
        vector <int> maxSum; 
        
        for(int i=0; i<N; i++){ //using two loops.
            int sum=0; //when i index gets change value of sum will be 0 for new subarray.
            for(int j=i; j < N; j++){ //staring from i index up to the end.
                sum+=Arr[j]; //adding value of every subarray in sum. i.e sum=sum+Arr[j];
                maxSum.push_back(sum);//pushing sum of every subarray in vector
            }
        }
        
        sort(maxSum.begin(),maxSum.end()); //sorting vector in ascending order so that we can get kth largest sum. TC for sorting n2logn
        int largest=maxSum[maxSum.size() - K]; //so kth largest will be size - k.
        return largest; //returning largest.
    }
    

    
    
    
    






    //
     int kthLargest(vector<int> &arr,int N,int K){
        priority_queue<int> pq;
        for(int i=0; i<N; i++) pq.push(arr[i]);
        
        for(int i=0; i<N-1; i++){
            int sum = arr[i];
            for(int j=i+1; j<N; j++){
                sum += arr[j];
                pq.push(sum);
            }
        }
        
        K--;
        while(K--) pq.pop();
        return pq.top();
    }