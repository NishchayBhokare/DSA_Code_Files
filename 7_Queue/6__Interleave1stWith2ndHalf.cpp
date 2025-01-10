//Interleave The First Half Of The Queue With The Second Half
//Coding ninja

#include<bits/stdc++.h>
using namespace std;


//Approach 1: Using Queue TC-O(N) SC-O(N)
void interLeaveQueue(queue < int > & q) {
    queue<int>temp1;
    int n=q.size()/2;
    
    //step1: push half elements of queue into the stack
    //q ->    16 17 18 19 20
    //temp -> 11 12 13 14 15
    for(int i=0; i<n; i++){ 
        temp1.push(q.front());
        q.pop();
    }

    //step2: one by one push elements back to the queue.
    while(!temp1.empty()){
        q.push(temp1.front());
        temp1.pop();

        q.push(q.front());
        q.pop();
    }
}

//Approach 2: efficient approach using stack. Tc-O(N) SC-O(N)
//using only two loops.
//first push half elements in stack.
//now, if you observe carefully...current queue front element has right position is 1 and for next further
//q elements position will be...qind + 2.
//similarly for stack..current position is...size-2. and for next stack top element..position will be
//stInd - 2.
vector<int> rearrangeQueue(queue<int> &q){
    stack<int>st;
    vector<int> ans(q.size(),0); //creating array of q size..so that we can access it with index.
    
    int qInd = 1, stInd = q.size()-2, mid = q.size()/2; //initialising qind and stind.
    while(mid--){
        st.push(q.front()); //pushing mid elements into the stack.
        q.pop();
    }
    
    while(!st.empty()){ //while stack not empty.
        ans[qInd] = q.front(); //add front q element into the answer vector.
        ans[stInd] = st.top(); //then stack element.
        qInd += 2; //now increment qind by 2 to store next qfront elemnt
        stInd -= 2; //similarly for stInd...decrement st by 2.
        q.pop(); 
        st.pop(); //pop elements from both q and st.
    }
    return ans; //now return final answer.
}

//Approach 3: Using stack Tc-O(N) SC-O(N)
void interLeaveQueue(queue < int > & q) {
    int n=q.size()/2;
    stack<int>st;

    //step1: pushing first half of queue in stack
    // queue:16 17 18 19 20, stack: 15(T) 14 13 12 11
    for(int i=0; i<n; i++){
        st.push(q.front());
        q.pop();
    }

    //step2: pushing stack elements back to stack
    // queue: 16 17 18 19 20 15 14 13 12 11
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }

    //step3: dequeue the first half elements of queue
    // and enqueue them back
    // queue: 15 14 13 12 11 16 17 18 19 20
    for(int i=0; i<n; i++){
        q.push(q.front());
        q.pop();
    }

    //step 4: Again push the first half elements into the stack
    // queue: 16 17 18 19 20, 
    //stack:  11(Top) 12 13 14 15
    for(int i=0; i<n; i++){
        st.push(q.front());
        q.pop();
    }

    //step 5: finally push, one by one elements to the queue.
    while(!st.empty()){
        q.push(st.top());
        st.pop();

        q.push(q.front());
        q.pop();
    }

}