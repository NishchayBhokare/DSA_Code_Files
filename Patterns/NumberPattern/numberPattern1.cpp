#include<iostream>
using namespace std;

// 1
// 23
// 345
// 4567

int main(){
      cout<<"Enter a number\n";
    int n;
    cin>>n;
    for(int i=1; i<=n; i++){

        for(int j=1; j<=i; j++){
            cout<<i+j-1;
        }
        cout<<endl;
    }
}