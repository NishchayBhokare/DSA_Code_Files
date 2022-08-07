#include<iostream>
using namespace std;

// A
// BC
// DEF
// GHIJ

int main(){
     cout<<"Enter a number\n";
    int n;
    int count=1;
    cin>>n;

    for(int i=1;i<=n;i++){
        for(int j=1; j<=i; j++){
            char ch='A' + count - 1;
            cout<<ch;
            count++;
        }
        cout<<endl;
    }
}