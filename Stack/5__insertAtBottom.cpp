//Insert An Element At Its Bottom In A Given Stack
//Coding ninja

#include<stack>
using namespace std;
//Approach 1: optimised approach using recursion. TC-O(N) SC-O(N-recursive call stack)

//looping till last element, once reach to condition when stack gets empty, then insert that x element in stack and then through recursive back calls, insert remaining elements in stack.
void solve(stack<int>&st,int x){
    if(st.empty()){
        st.push(x); //once stack empty insert that x element in stack
        return;
    }

    int val=st.top(); //keep a side top value of stack.
    st.pop(); //and pop out stack.

    solve(st,x); //recursive call

    st.push(val); //after coming back from if block, insert remaining element one by one
}

stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    // Write your code here.
    solve(myStack,x);
    return myStack;
}


//Approach 2: Iterative approach. TC-O(N) SC-O(N-temporary stack)
stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    // Write your code here.
    // solve(myStack,x);
    stack<int>temp;
    while(!myStack.empty()){ //insert all elements in temporary stack.
        temp.push(myStack.top());
        myStack.pop();
    }

    myStack.push(x); //once given stack gets empty then insert that x element in the given stack

    while(!temp.empty()){ //and return back, insert all element from temp to stack.
        myStack.push(temp.top());
        temp.pop();
    }

    return myStack;
}