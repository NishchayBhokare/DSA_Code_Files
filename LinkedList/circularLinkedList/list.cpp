#include<iostream>
#include<list>
using namespace std;

int main(){
    list<int>l1={2,6,5,9}; //It is doubly linked list.
    list<int>l2={0,4};
    // l1.push_back(3);
    // l1.push_front(8);
    // l1.pop_back();       
    // l1.pop_front();       
    // l1.sort();
    // l1.reverse();
    // l1.remove(5); //which value we want to remove.
    // l1.clear();
    // l1.merge(l2); // we are merging two sorted lists into one lists.
    // l1.assign(5,2);  //it assigns new value by replacing old ones. simply it will add 2 for 5 times in vector.
    // cout<<l1.size()<<endl;
    // cout<<l1.empty()<<endl;
    // l1.resize(2);
    // cout<<l1.max_size()<<endl;
    // list <int> :: iterator it=l1.begin();

    // l1.erase(it);  //giving iterator to erase which pointing to particular element.

    // while (*it!=6)
    // {
    //     it++;
    //     /* code */
    // }
    // l1.insert(it,3); //inserting before element 6.
    
    




//Traversing over the list.
    // list<int> :: iterator it=l1.begin();
    // while (it!=l1.end())
    // {
    //     cout<<*it<<" ";
    //     it++;
    // }cout<<endl;
    

    // for(auto i=l1.begin();i!=l1.end();i++){ //Here " i " is one kind of iterator. 
    //     cout<<*i<<" ";
    // }cout<<endl;

    for(auto i:l1){
        cout<<i<<" ";
    }
}