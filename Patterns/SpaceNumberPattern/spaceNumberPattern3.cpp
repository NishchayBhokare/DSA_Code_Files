#include<iostream>
using namespace std;

// 1234
//  234
//   34
//    4

int main(){
      cout<<"Enter a number\n";
    int n;
    cin>>n;
    for(int i=1; i<=n; i++){
         int space=i-1;
        while (space)
        {
            cout<<" "; 
            space--;
        }

        for(int j=1; j<=n-i+1; j++){
            cout<<i+j-1;
        }
        cout<<endl;
    }
}