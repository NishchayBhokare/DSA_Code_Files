#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector <int> v={1,3,5,6,9};
    vector <int> v2={4,1,7,3,0};
    // sort(v2.begin(),v2.end());

    //algo for binary search
    // cout<<binary_search(v.begin(),v.end(),5)<<endl;
    // cout<<"Lower Bound "<<lower_bound(v.begin(),v.end(),5) - v.begin()<<endl;
    // cout<<"Upper Bound "<<upper_bound(v.begin(),v.end(),5) - v.begin()<<endl;
    // rotate(v.begin(),v.begin()+2,v.end());

    for(auto i:v2){
        cout<<" "<<i<<" ";
    }

    // int a=3,b=5;
    // swap(a,b);
    // cout<<a<<b;
    // cout<<max(a,b)<<endl;
    // cout<<min(a,b)<<endl;


    // string str="abcd";
    // reverse(str.begin(),str.end());
    // cout<<str;    
}