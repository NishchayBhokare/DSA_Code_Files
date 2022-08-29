#include<iostream>
using namespace std;
int main(){

    //for adding space
    int n; 
    cin>>n;
// 4 
// 3 4
// 2 3 4
// 1 2 3 4
    for(int i=1; i<=n; i++){
       for(int j=(n-i+1); j>=1; j--){
        cout<<j;
       }
        cout<<endl;
    }

    return 0;
}