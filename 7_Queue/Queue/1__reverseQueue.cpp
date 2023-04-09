//Reverse Queue
//gfg

#include<bits/stdc++.h>
using namespace std;
//Approach 1: using stack TC-O(N) SC-O(N)
queue<int> rev(queue<int> q)
{
    stack<int>st; //create stack insert all elemetns into the stack, and one by one insert back element into the queue
    while(!q.empty()){
        st.push(q.front());
        q.pop();
    }
    
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }
    
    return q;
}



//Approach 2: using Recursion TC-O(N) SC-O(N)
void solve(queue<int>&q){
    if(q.size() == 0) return;
    
    int val=q.front(); //take out element
    q.pop(); //pop element from queue
    
    solve(q); //call
     
    q.push(val); //at the end insert that take out element in the queue.
}

queue<int> rev(queue<int> q)
{
    solve(q);
    return q;
}