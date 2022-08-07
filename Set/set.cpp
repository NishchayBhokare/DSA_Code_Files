#include<iostream>
#include<set>
using namespace std;

int main(){
    set<int> s1={3,1};
    s1.insert(8);
    s1.insert(8);
    // s1.erase(s1.begin());
    // s1.erase(3); //we can add direct element in erase in set and map.
    // s1.clear();
    // cout<<"set is empty "<<s1.empty()<<endl;
    // cout<<"Element is present or not "<<s1.count(8)<<endl; //it return 1 if element is present otherwise return 0.
    // s1.emplace(82);
    // cout<<s1.size()<<endl;
    // set<int>::iterator it= s1.find(1); or auto it=s1.find(1); //it will return iterator which points to element present in find.else it will return iterator which points to end element.
    
    // cout<<*it<<endl;
    // for(auto itr=it;itr!=s1.end();itr++){
    //     cout<<*itr<<" ";
    // }cout<<endl;



// Traversing over the set
    for(auto i:s1){
        cout<<i<<" ";
    }
}