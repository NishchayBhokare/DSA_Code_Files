#include<iostream>
using namespace std;

// D
// CD
// BCD
// ABCD

int main(){
     cout<<"Enter a number\n";
    int n;
    cin>>n;

    for(int i=1;i<=n;i++){
        for(int j=1; j<=i; j++){
            char ch=n - i + j - 1 + 'A';
            cout<<ch;
        }
        cout<<endl;
    }
}