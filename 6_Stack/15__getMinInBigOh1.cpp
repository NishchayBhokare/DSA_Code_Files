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
           if(curr < minElem){ //if current top is lesser than mini. that means. mini is original x value of this top(why? look in push operation. if current x is lesser than mini. then we're modifying x and updating mini as original x).
           //and as we're popping out this from stack. then we have to move back to previous stage of min element.
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
              if(x < minElem){ //if new elemnet is lesser than curren mini..then we need to push this 
              //new x element by updating it. why? because. if in future..we pop out this lesser element.
              //then we should able to move back to previous stage of mini element.
                  int updatedX = 2 * x - minElem; //why 2*x becuase if we do x-minelement. then it will goes into -ve. that's why 2*x.
                  st.push(updatedX);
                  minElem = x;
              }
              else{ //if new element is greater then..even after popping out this elemnet. there will be no impact on min element.
              //that's why we're storing it in normal way.
                 st.push(x);
              }
          }
       }
};

//Mathematical proof is.
 x - mini < 0;
 //if we add x to both sides.
 x + x - mini < x;  i.e 2x - mini < x; so 2x-mini is nothing but updated value.
 //so
 updatedValue < x. 
//  so updated value will always lesser than x. and original x will be mini in this cases.

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


//Approach 2: Using extra memory..create pair and store in stack. very simple.
class Solution{
    stack<pair<int,int>> st;
    public:
    
       /*returns min element from stack*/
       int getMin(){
           if(st.empty()) return -1;
           
           return st.top().second;
       }
       
       /*returns poped element from stack*/
       int pop(){  
           if(st.empty()) return -1;
           
           int val=st.top().first;
           st.pop();
           return val;
       }
       
       /*push element x into the stack*/
       void push(int x){
           if(st.empty())
                st.push({x,x});
           
           else st.push({x,min(x,st.top().second)});
       }
};



//Approach 3: using space. TC-O(1) SC-O(N);class SpecialStack {
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