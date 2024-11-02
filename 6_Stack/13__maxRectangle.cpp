//Calculate max rectangle area
//GFG  

//Approach: Same approach as we did in finding largest histogram
// TC-O(n*m) SC-O(m)
 void nextSmallest(int arr[],int n, vector<int>&next){
        stack<int> st;
        st.push(-1);
        for(int i=n-1; i>=0; i--){
            while(st.top() != -1 and arr[st.top()] >= arr[i]){
                st.pop();
            }
            next[i]=st.top();
            st.push(i);    
        }
    }
    
void prevSmallest(int arr[],int n, vector<int>&prev ){
    stack <int>st;
    st.push(-1);
    for(int i=0; i<n; i++){
        while(st.top() != -1 and arr[st.top()] > arr[i]){
            st.pop();
        }
        prev[i] = st.top();
        st.push(i);
    }
}

    int calCulateArea(int arr[],int n){ //same as histogram problem 11.
        
        int maxArea=INT_MIN;
        vector<int> next(n);
        vector<int> prev(n);
        
        nextSmallest(arr,n,next);
        prevSmallest(arr,n,prev);
        
        for(int i=0; i<n; i++){
            int length=arr[i];
            
            if(next[i] == -1) next[i]=n;
            
            int breadth=next[i]-prev[i]-1;
            int area=length*breadth;
            maxArea=max(area,maxArea);
        }
        return maxArea;
    }
    
    int maxArea(int matrix[MAX][MAX], int n, int m) { //main function
        // Your code here
       int maxArea = calCulateArea(matrix[0],m); //first calculating max area of first array from given matrix
       
       for(int i=1; i<n; i++){ //then looping for remaining rows
           for(int j=0; j<m; j++){
               if(matrix[i][j] != 0){ //if current position element is not zero then only previous to it.
                   matrix[i][j] += matrix[i-1][j];
               }
           }
           
           int area = calCulateArea(matrix[i],m); //once inner for loop executed completelty, we are ready to call area function, for calculating area for ith array in matrix.
           maxArea=max(area,maxArea); //finally check whether current rows area greater or maxArea is greater.
       }
        
        return maxArea; //finally return maxArea.
    }




            //we can find area of largest rectangle..without putting -1 in stack initially.
      
      
      void previousSmallerElementIndex(int *arr,vector<int>&previous,int size){
        stack<int>st;
        for(int i = 0; i<size; i++){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            
            if(!st.empty()) previous[i] = st.top();
            st.push(i);
        }
    }
    
    void nextSmallerElementIndex(int *arr,vector<int>&next,int size){
        stack<int>st;
        for(int i = size-1; i>=0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            
            if(!st.empty()) next[i] = st.top();
            st.push(i);
        }
    }
    
    
    int findMaxAreadOfRectangle(int *arr,int size){
        int mArea = 0;
        vector<int>previous(size,-1);
        vector<int>next(size,size);
        
        previousSmallerElementIndex(arr,previous,size);
        nextSmallerElementIndex(arr,next,size);
        
        for(int i=0; i<size; i++){
            int length = arr[i];
            int breadth = next[i] - previous[i] - 1;
            int area = length*breadth;
            mArea = max(area,mArea);
        }
        
        return mArea;
    }