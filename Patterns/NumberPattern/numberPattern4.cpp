#include<iostream>
using namespace std;
// 4 
// 3 4
// 2 3 4
// 1 2 3 4

int main(){
    cout<<"Enter a number "<<endl;
    int n;
    cin>>n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cout<<n - i + j<<" ";
        }
        cout<<endl;
    }
}