    //Larget area of histogram
    //GFG
    

    //Approach 1: Optimised solution TC-O(N) SC-O(N)
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