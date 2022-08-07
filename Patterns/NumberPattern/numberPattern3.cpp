#include<iostream>
using namespace std;
// 4 
// 3 3
// 2 2 2
// 1 1 1 1

int main(){
    cout<<"Enter a number "<<endl;
    int n;
    cin>>n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cout<<n - i + 1<<" ";
        }
        cout<<endl;
    }
}