#include<iostream>
#include<deque>
using namespace std;

int main(){
    // deque<string> dq={"riyaz","Yusuf"};  /*we can initialize in this way also*/
    deque<string> d2={"ok","no","yes"};
    deque<string> dq;
    // dq.push_front("viraj");
    dq.push_back("viraj");
    dq.push_back("rohan");
    dq.push_back("kiran");
    dq.push_back("shantanu");

    // cout<<dq[0]<<endl;
    // cout<<dq.at(0)<<endl;
    // cout<<dq.front()<<endl;
    // cout<<dq.back()<<endl;
    // cout<<dq.size()<<endl;
    // cout<<dq.empty()<<endl;
    // dq.erase(dq.begin(),dq.begin()+1);
    // dq.assign(3,"hello"); //three times we are adding hello in the dequqe by replacing all the elements.
    // dq.clear();
    // dq.at(2)="bhai";
    // dq.swap(d2);
    // dq.insert(dq.begin()+2,"start");

// Traversing over the deQueue
    // for(auto i:dq){
    //     cout<<i<<endl;
    // }
    

    for(auto it=dq.begin();it!=dq.end();it++){
        cout<<*it<<endl;
    }
}
