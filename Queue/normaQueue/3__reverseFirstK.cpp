
//Reverse First K elements of Queue
//gfg

#include<bits/stdc++.h>
using namespace std;

//Tc-O(N) SC-O(K)
queue<int> modifyQueue(queue<int> q, int k) {
    
    stack<int> st;
    
    //step 1: pop first k elements and store it into the stack
    for(int i=0; i<k; i++){
        st.push(q.front());
        q.pop();
    }
    
    //step2: Fetch those elements from stack and push back in queue
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }
    
    //step3: pop out first n-k elemnets from queue and push back in itself.
    for(int i=0; i<(q.size()-k); i++){
        int val = q.front();
        q.pop();
        q.push(val);
    }
    
    return q;
}