//Get minimum element from stack in big oh of 1 TC and SC.
//GFG

//Analogy:
//push - > while pushing at first just simply push element and marked minielement as first elemet.
 //for remaining elements, if given element is less than minElement, then pushed element in stack like 2*x - minElement. and update minelement to x.

 //pop - > while popping, if top element is less than minElement, then use 2*minElement - topelement. to get previous small element and return minElement i.e nothing but top element.

 //for get min simply return minelem.

class Solution{
    int minElem;
    stack<int> st; //creating stack
    public:
    
       /*returns min element from stack*/
       int getMin(){
            if(st.empty()) return -1;
            return minElem;
       }
       
       /*returns poped element from stack*/
       int pop(){
           if(st.empty()) return -1;
           
           int curr = st.top();
           if(curr < minElem){
               int popped = minElem;
               minElem = 2*minElem - curr;
               st.pop();
               return popped;
           }
           else{
               st.pop();
               return curr;
           }
       }
       
       /*push element x into the stack*/
       void push(int x){
          if(st.empty()){
              minElem = x;
              st.push(x);
          }
          else{
              if(x < minElem){
                  int updatedX = 2 * x - minElem;
                  st.push(updatedX);
                  minElem = x;
              }
              else{
                 st.push(x);
              }
          }
       }
};

//similar to above only but straightforward..looks simple.
class SpecialStack {
    public:
    stack<int> st;
    int minElement; 
    void push(int data) {
        if(st.empty()){
            st.push(data);
            minElement = data;
        }
        else{
            if(data < minElement){
                int val = 2*data - minElement;
                st.push(val);
                minElement = data;
            }
            else st.push(data);
        }
        
    }

    void pop() {
        if(!st.empty()){
            if(st.top() >= minElement) st.pop();
            else{
                minElement = 2*minElement - st.top();
                st.pop();
            }
        }
    }

    int top() {
        if(!st.empty()){
            if(st.top() > minElement) return st.top();
            else{
                return minElement;
            }
        }
    }

    int getMin() {
       return minElement;
    }  
};




//Approach 2: using space. TC-O(1) SC-O(N);class SpecialStack {
class SpecialStack {
    public:
        stack<int>st;
        stack<int>mini; //using mini stack..to track minimum element.
        int minElement = INT_MAX;
    void push(int data) {
        // Implement the push() function.
        st.push(data);
        minElement = min(data,minElement);
        mini.push(minElement);
    }

    void pop() {
        // Implement the pop() function.
        if(st.size() >0){
            st.pop();
            int val = mini.top();
            mini.pop();
            
            if(minElement == val){
                if(mini.empty()) minElement = INT_MAX;
                else minElement = mini.top();
            }
        }
        
    }

    int top() {
        // Implement the top() function.
        if(st.size() > 0) return st.top();
        return -1;
    }

    int getMin() {
        // Implement the getMin() function.
       if(mini.size()>0) return mini.top();
       return -1;
    }  
};