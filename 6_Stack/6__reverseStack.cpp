 //Reverse a Stack using recursion.
 //GFG

 //Approach:Recursive approach. TC-O(N2) SC-O(N)
 //Analogy: first reach till last element in stack.
 //once gets return from if block, call for insert at bottom function for that val element.
 //This insertAtbottom function will insert that val at bottom of stack.
 //and one by one for all elments call this insertAtBottom function.

#include<stack>
using namespace std;

 void insertAtbottom(stack<int> & st,int x){
        if(st.empty()){
            st.push(x);
            return;
        }
        
        int val = st.top();
        st.pop();
        
        insertAtbottom(st,x);
        st.push(val);
    }
    
    void Reverse(stack<int> &st){
        if(st.empty()){ //looping till stack not get empty
            return;
        }
        
        int val=st.top(); //keeping value aside of top
        st.pop();
        
        Reverse(st); //recursive call
        insertAtbottom(st,val); //once stack get empty then for one by one val element call insert at bottom function
    }


//Approach 2: Slightly different approach TC-O(N2) SC-O(N)
 void insertAtBottom(stack<int>&st, int &x, int &i){
    if(st.size() == i){ //every time we added element bottom element. then i getting increased.
        st.push(x);
        return;
    }
    
    int val=st.top();
    st.pop();
    
    insertAtBottom(st,x,i);
    
    st.push(val);
}

void Reverse(stack<int> &st){
    
    int n=st.size();
    for(int i=0; i<n; i++){ //looping till size of array.
        
        int x=st.top();
        st.pop();
        
        insertAtBottom(st,x,i);
    }
}