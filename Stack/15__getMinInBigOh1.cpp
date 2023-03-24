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
              st.push(x);s
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