#include<iostream>
using namespace std;

//    1
//   22
//  333
// 4444

int main(){
      cout<<"Enter a number\n";
    int n;
    cin>>n;
    for(int i=1; i<=n; i++){
         int space=n-i;
        while (space)
        {
            cout<<" "; 
            space--;
        }

        for(int j=1; j<=i; j++){
            cout<<i;
        }
        cout<<endl;
    }
}