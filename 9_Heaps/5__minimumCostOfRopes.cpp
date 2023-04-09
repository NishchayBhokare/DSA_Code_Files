//Minimum Cost of ropes
//GFG

#include<bits/stdc++.h>
using namespace std;

//TC-O(Nlogn) SC-O(N).
//Analogy: First we will add all elements in min heap
//then popping two elements from heap and then adding sum of those elements in priority queue.
//and we're looping till size of heap greater than 1 because if size is 1 then we cannot connect the roop.
long long minCost(long long arr[], long long n) {
    // Your code here
    long long cost=0; 
    priority_queue <long long, vector<long long>, greater<long long> > pq; //creating min heap
    for(int i=0; i<n; i++){
        pq.push(arr[i]); //pushing all the elements
    }
    
    while(pq.size()>1){ //looping till size is 1.
        long long a=pq.top(); //getting first minimum elements
        pq.pop();
        
        long long b=pq.top(); //getting second 
        pq.pop();
        
        long long sum=a+b; //adding their sum
        cost+=sum; //adding sum in cost i.e final answer.
        pq.push(sum); //and also in priority queue.
    }
    
    return cost; //returning answer.
}