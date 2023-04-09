#include<iostream>
#include<stack>
using namespace std;

void print(stack <int> st){
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    } cout<<endl;
}

int main(){
    stack<int> st;
    stack<int>st2;
    
    st.push(4);
    st.push(1);
    st.push(2);

    // cout<<"Size of stack before pop "<<st.size()<<endl;
    // st.pop();
    print(st);
    // cout<<st.empty()<<endl;
    // cout<<"Size of stack after pop "<<st.size()<<endl;

    // cout<<st.top()<<endl;
return 0;
}