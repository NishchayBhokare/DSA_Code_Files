#include<iostream>
using namespace std;

// ABCD
// BCDE
// CDEF
// DEFG

int main(){
     cout<<"Enter a number\n";
    int n;
    cin>>n;

    for(int i=1;i<=n;i++){
        for(int j=1; j<=n; j++){
            char ch='A' + i + j - 2;
            cout<<ch;
        }
        cout<<endl;
    }
}