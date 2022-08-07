#include<iostream>
#include<map>
using namespace std;

int main(){
    map<int,string>m;
    
    m[1]="Nishchay";
    m[4]="Pradip";
    m[2]="Bhokare";
    // m.clear();
    // cout<<m.count(28)<<endl;
    // m.insert({3,"Rohan"});
    // m.erase(2); //we can erase in this way.
    // m.empty()
    // cout<<m.size()<<endl;
    // cout<<m.max_size()<<endl;

    auto it=m.find(2);
    for(auto itr=it;itr!=m.end();itr++){
        // cout<<(*itr).first<<" ";
        // cout<<itr->first<<" "; //we can access in this way also
    }cout<<endl;


// Traversing over the map
    for(auto i:m){
        cout<<"The key is -> "<<i.first<<" & The value is -> "<<i.second<<endl;
    }

}