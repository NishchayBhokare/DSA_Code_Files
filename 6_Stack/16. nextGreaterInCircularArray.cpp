//GFG. 
//Approach 1: Using single loop. and hypothitically considering we double 
    // given array..so that we can consider starting elements. As we have to find
    //next greater element. we will double up array and then will solve question.
    //for eg. 1 6 8 0 4 array..we're considering  1 6 8 0 4 1 6 8 0 4 array. twice array.

//TC-O(2N(for traversal)  + 2N(for removal)) SC-(2N(for pushing in stack) + N(for answer.))
vector<long long> nextLargerElement(vector<long long> &arr, int n){
    
    vector<long long>nextGreater(n,-1);
    
    stack<long long>st;
    st.push(arr[0]);
    
    for(int i=2*n-1; i>=0; i--){ //looping from end. 2*n-1. last index of doubly array.
        
        while(!st.empty() && st.top() <= arr[i%n]) //if current stack stop is lesser than current element
        //then pop stack. because we want greater element.
            st.pop();
        
        if(i<n){ //if array index is under range..then only we're doing this of creation answer.
            if(st.empty())
            nextGreater[i] = -1;
            
            else
                nextGreater[i] = st.top();
        }
        
        st.push(arr[i%n]); //push element in stack. before pushing get element in range of n.
    }
    
    
    return nextGreater;
}


//Approach 2: First push..starting greater element in stack. which forms increasing order.
//then do normal next greater element solution. 
//TC-O((N+N) + (N+N) == 4N) SC-O(N). Little optimisation in space.
vector<long long> nextLargerElement(vector<long long> &arr, int n){
    
    vector<long long>nextGreater(n,-1);
    
    stack<long long>st;
    st.push(arr[0]);
    
    //preparing stack for starting elements to deal with circular behaviour.
    for(int i=n-2; i>=0; i--){ //pushing all the elemnents in stack which are greater from 
    //front. for eg. 1 6 8 0 4 3 for this stack will be 1 6 8. 1 is on top. and 8 is in bottom.
        
        while(!st.empty() && st.top() <= arr[i])
            st.pop();
        
        st.push(arr[i]);
    }
        
    
    for(int i=n-1; i>=0; i--){ //now just do normal next greater element solution.
        
        while(!st.empty() && st.top() <= arr[i])
            st.pop();
        
        if(st.empty())
            nextGreater[i] = -1;
        
        else
            nextGreater[i] = st.top();
        
        st.push(arr[i]);
    }
    
    
    return nextGreater;
}


//Approach 3: Brute force approach. TC-O(N2) SC-O(N)
vector<long long> nextLargerElement(vector<long long> &arr, int n){
    vector<long long> ans(n,-1);
    
    for(int i=0; i<n; i++){
        
        for(int j=i+1; j<(i+n); j++){
            
            if(arr[i] < arr[j%n]){
                ans[i]=arr[j%n];
                break;
            }
        }
    }
    
    return ans;
}