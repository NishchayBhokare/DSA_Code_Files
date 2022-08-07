#include<iostream>
#include<queue>
using namespace std;

int main(){
    queue <string> q1;
    queue <string> q2;
    // q2.push("kiran");
    q1.push("rohan");
    q1.push("viraj");
    // cout<<q1.size()<<endl;
    // q1.swap(q2);
    // cout<<q1.back()<<endl;
    // q1.emplace("yash");
    
    
//Traversing over the queue.
    while (!q1.empty())
    {
        cout<<q1.front()<<endl;
        q1.pop();
    }
    
}