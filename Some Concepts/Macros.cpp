#include<iostream>
#include<vector>
using namespace std;
//Macro is piece of code..which get replace by value of macro.. before compile time. and it does not hold storage.
#define Num 5   //Object-like Macros. //

#define Instagram Followers
#define Followers 130   // Chain Macros.

#define Elements 1,\
                 2,\
                 3  // Multi-line Macros.

#define max(a,b) (((a) > (b))? (a): (b)) //Function-like Macros.

inline int getMax(int a, int b){
    return (a>b)? a : b;
}

int  c = 3; //globl variable
int main(){
    cout<<Num<<endl;

    cout<<"I have "<<Instagram<<" k Followers on Instagram"<<endl;

    vector<int> arr = {Elements};
    for(auto i: arr) cout<<i<<" ";
    cout<<endl;

    // int a=3, b=5;
    // cout<<"Max value is "<<max(a,b)<<endl;
    // cout<<c<<endl;

    int x = 4, y = 3;
    int maxValue = getMax(4,3);
    cout<<maxValue<<endl;
}