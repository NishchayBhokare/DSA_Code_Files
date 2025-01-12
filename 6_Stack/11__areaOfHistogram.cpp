    //Larget area of histogram
    //GFG
    

//Approach:Most optimised Approach TC-O(2N) SC-O(N).
//Logic is: here previous smaller element index we're calculating on the fly..on the go.
//and next smaller element we're finding..when..we're getting smaller eleemnt and popping out
//indexes from stack. that time...we're computing aread..for that popping out index.

//for that popping out index. area will be element of that index * next smaller element i.e ith element 
// minus previous smaller element that..next top element in stack. minus 1.
    int getMaxArea(vector<int> &arr) {
    
    int n=arr.size();
    
    stack<int>st;
    st.push(-1); //push -1. to get previous smaller as -1.
    

    int maxArea=0;
    
    for(int i=0; i<n; i++){
        
        while(st.top() != -1 && arr[i] < arr[st.top()]){ //check..if stack contains
        //greater than one element i.e not -1 then 
        //&& if we  encounter i as lesser element than stack top..then enter in this block.
        //to calculate area of top element index.
            
            int elem = arr[st.top()]; //now element will be element at index of stack top.
            st.pop(); //pop out element.
            
            int prevSmallInd = st.top(); //previous small will be next element present in stack.
            int nextSmallInd = i; //next small will be current element.
            
            int area = elem * (i - st.top() -1); //calculate area. Length * breadth.
            
            maxArea = max(maxArea, area);
        }
        
        st.push(i);
    }
    
    //here is another case..at the end..stack will conains elemnet which doesn't have smaller
    // eleements to right. so for this element..we have smaller element as n. last pos+1.
    while(st.top() != -1 &&  !st.empty()){
        
        int elem = arr[st.top()];
        st.pop();
        
        int prevSmallInd = st.top();
        int nextSmallInd = n;
        
        int area = elem * (n - st.top() -1);
        
        maxArea = max(maxArea, area);  
    }
    
    return maxArea;
}





//Approach 1: Optimised solution TC-O(2N + 2N + N i.e 5N) SC-O(2N + 2N i.e 4N)
    void nextSmaller(vector<long long>&next, long long arr[],int n){
    stack <long long> st;
    st.push(-1);

    for(int i=n-1; i>=0; i--){
        
        if(st.top()== -1 or arr[i] > arr[st.top()]){
            next[i] = st.top(); // which will be index;
            st.push(i);
        }
        else{
            while(st.top()!= -1 and arr[st.top()] >= arr[i]){
                st.pop();
            }
            next[i] = st.top();
            st.push(i);
        }
    }
}
    
//little optimised for prevSmaller
void prevSmaller(vector<long long>&prev, long long arr[],int n){
    stack <long long> st;
    st.push(-1);
    for(int i=0; i<n; i++){
        
        while(st.top()!=-1 and arr[st.top()] >= arr[i]){
            st.pop();
        }
        prev[i] = st.top();
        st.push(i);
    }
}

long long getMaxArea(long long arr[], int n)
{
    vector<long long > next(n);
    vector<long long > prev(n);
    
    nextSmaller(next,arr,n); //finding next smaller element for every element in arr and storing index of next smaller element in next vector.
    prevSmaller(prev,arr,n);  //similarly for previous vector.
    
    long long maxArea=INT_MIN; //pointing maxArea to Minimum value
    
    for(int i=0; i<n; i++){ //looping over given array
        long long length=arr[i]; //area can be calculated by length * breadth(width) so, length is nothing but value, so arr[i] equals to length.
        
        if(next[i] == -1) next[i] = n; //in case if next[i] equals to -1 that means there is no next smaller element for that element in arr.so, point that next of i to n, so that we can take whole range of array.

        long long breadth = next[i] - prev[i] - 1; //breadth for particular element can be calculate by nextsmaller index - previous smaller index - 1.
        long long area=length*breadth; //finally calculate length*breadth;
        maxArea=max(area,maxArea); //check which area is maximum and update according to that.
    }
    return maxArea; //finally after all iteration, return maximum area.
}



//Approach 2: without inserting -1 in stack..instead create previous and next array with 
// -1 and size of input array respectively
//without inserting -1 into the stack.
void previousSmallerElements(vector<int>&arr,vector<int>&previous, stack<int> st){
    //previous smallest element index.
    int n = arr.size();
    for(int i = 0; i<n; i++){
        while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();

        if(!st.empty()) previous[i] = st.top();
        st.push(i);
    }
}

    
void nextSmallerElements(vector<int>&arr, vector<int>&next, stack<int> st){
    //next smallest elementindex.
    int n = arr.size();
    for(int i = n-1; i>=0; i--){
        while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();

        if(!st.empty()) next[i] = st.top();
        
        st.push(i);
    }
}
    
int largestRectangleArea(vector<int>& arr) {
    int n = arr.size();
    vector<int>previous(n,-1); //initialising vector using -1.
    vector<int>next(n,n); //initialising vector with size of array.
    stack<int> st;

    previousSmallerElements(arr,previous,st);
    nextSmallerElements(arr,next,st);

    int maxArea = 0;
    for(int i = 0; i<n; i++){
        int length = arr[i];
        int breadth = next[i] - previous[i] - 1; //because of creating array with -1 and size of array..no need to add conditions here.
        int area = length * breadth;
        maxArea = max(maxArea,area);
    }

    return maxArea;
}



//Approach 3: brute force solution TC-O(N2) SC-O(1)
long long getMaxArea(long long arr[], int n)
{
    long long maxArea=0;
    for(int k=0; k<n; k++){
        long long area = arr[k];
        for(int i=k+1; i<n; i++){ //comparing next element with curr element if next element is greater than curr element then update area
            if(arr[i] >= arr[k]) area+=arr[k];
            else break;
        }
        
        for(int i=k-1; i>=0; i--){ //similarly checking with previous element.
            if(arr[i] >= arr[k]) area+=arr[k];
            else break;
        }
        
        maxArea=max(area,maxArea); //once one iteration is get over, taking max of both, that is either current area or maxArea.
    }
    
    return maxArea;
}



//Approach 4: get previous small and next element. TC-O(N2) SC-O(2N)
int getPrevSmallElemInd(int i, vector<int>&arr, int &n){
    
    int elem = arr[i];
    i--;
    while(i>=0){
        
        if(arr[i] < elem)
            return i;
        i--;
    }
    
    return -1;
}

int getNextSmallElemInd(int i, vector<int>&arr, int &n){
    
    int elem = arr[i];
    i++;
    while(i<n){
        
        if(arr[i] < elem)
            return i;
        i++;
    }
    
    return n;
}

int getMaxArea(vector<int> &arr) {

    int maxArea=0, n=arr.size();
    
    for(int i=0; i<n; i++){
        
        int prevSmallInd = getPrevSmallElemInd(i,arr,n);
        int nextSmallInd = getNextSmallElemInd(i,arr,n);
        
        int len = arr[i];
        int breadth = nextSmallInd - prevSmallInd - 1;
        
        int area = len * breadth;
        
        maxArea = max(area, maxArea);
    }
    
    return maxArea;
}