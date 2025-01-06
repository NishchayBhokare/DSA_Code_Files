#include<iostream>
#include<vector>
using namespace std;

int main(){
   vector<int>v1={1,2,3,7,9};
    //    vector<int> v2(3,4); //it will initialize all elements as 4 in the vector.
    //    v1.push_back(5);
    //    v1.pop_back();
    // cout<<v1.at(1);
    //    cout<<v1.capacity();
    //    v1.shrink_to_fit();
    //    cout<<v1.capacity();

    //    cout<<v1.back();
// cout<<v1.size();
    // v1.resize(1);
// cout<<v1.size();
// int *pos=v1.data(); //it will return address of first element of a vector.
// cout<<*pos;
// cout<<sizeof(v1)<<endl;
// cout<<v1.empty();
// v1.assign(2,8);
// v1.clear();
// v1.insert(v1.begin(),9);
// vector<int> :: iterator it=v1.begin();
// while (*it!=7)
// {
//     it++;
// }
// v1.erase(it);
// v1.erase(v1.begin(),v1.begin()+2);
// v1.emplace(v1.begin(),9);

//    for(auto i:v1){
//     cout<<i;
//    }

    //   for(auto i=v1.begin();i!=v1.end();i++){
    //     cout<<*i;
    //   }
    // v1.at(2)=4;

    for(int i=0;i<v1.size();i++){
        cout<<v1[i]<<" ";
    }


Syntax of erase()
    iterator erase(iterator position);
    iterator erase(iterator first, iterator last);

    iterator position: The iterator points to the element to be erased.
    iterator first, iterator last: A range of elements to be erased. 
    The function removes elements from vectors in C++ starting from the first and ending at the last (exclusive).

Syntax of substrin.
string substr (size_t pos, size_t len) const;
Parameters:

pos: Index of the first character to be copied.
len: Length of the sub-string.
size_t: It is an unsigned integral type.
}