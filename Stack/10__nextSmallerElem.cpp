//Find next smaller element on coding ninja or Help classmate on gfg
//https://practice.geeksforgeeks.org/problems/fab3dbbdce746976ba35c7b9b24afde40eae5a04/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

//Approach 1: More optimised using stack. TC-O(N) SC-O(N)
vector<int> help_classmate(vector<int> arr, int n) 
{ 
    vector<int>ans(n); //creating ans vector of size n
    stack<int>st; //creating stack
    st.push(-1); //push -1 first in stack
    for(int i=n-1; i>=0; i--){
        while(st.top() >= arr[i]){ //loop till top element greater than or equal to ith element in array.
            st.pop(); //and pop out that greater element from stack
        }
        ans[i] = st.top(); //after loop out, we will get smaller element top of stack, so store that element in ans vector
        st.push(arr[i]);  //and push that ith new element in stack
    }
    return ans;    //return ans vector
} 

//Understandable approach
 vector<int> help_classmate(vector<int> arr, int n) 
    { 
        // Your code goes here
         vector<int>ans;
    stack<int>st;
    st.push(-1);
    for(int i=n-1; i>=0; i--){
        if(arr[i] > st.top()){ //if ith element grater than top, then simply push top element in ans and ith element in stack
            ans.push_back(st.top());
            st.push(arr[i]);
        }
        else{
            while(st.top() >= arr[i]){ //else loop and find out smaller element
                st.pop();
            }
            ans.push_back(st.top()); //once find push in ans vector
            st.push(arr[i]); //and push that ith element in stack
        }
    }

    reverse(ans.begin(),ans.end()); //reverse ans vcetor
    return ans;
    } 
