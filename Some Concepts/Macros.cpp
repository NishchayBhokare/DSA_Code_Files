#include<iostream>
#include<vector>
using namespace std;

#define Num 5   //Object-like Macros.

#define Instagram Followers
#define Followers 130   // Chain Macros.

#define Elements 1,\
                 2,\
                 3  // Multi-line Macros.

#define max(a,b) (((a) > (b))? (a): (b)) //Function-like Macros.

int main(){
    cout<<Num<<endl;

    cout<<"I have "<<Instagram<<" k Followers on Instagram"<<endl;

    vector<int> arr = {Elements};
    for(auto i: arr) cout<<i<<" ";
    cout<<endl;

    int a=3, b=5;
    cout<<"Max value is "<<max(a,b);

}