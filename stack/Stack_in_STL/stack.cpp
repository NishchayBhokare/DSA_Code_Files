#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack <string> s1;
    stack<string>s2;
    s2.push("hey s2");
    s1.push("kiran");
    s1.push("viraj");
    s1.push("yash");
    // s1.pop();
    // cout<<s1.size()<<endl;
    // cout<<s1.empty()<<endl;
    // s1.swap(s1);
    // cout<<s2.top();    //it will return top most element in the stack.
    // cout<<"size is "<<s1.size()<<endl;



// Traversing over the stack
    while (!s1.empty())
    {
        cout<<s1.top()<<" ";
        s1.pop();
    }cout<<endl;
}

