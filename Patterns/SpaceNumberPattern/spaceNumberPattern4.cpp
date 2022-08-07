#include<iostream>
using namespace std;

//    0
//   12
//  345
// 6789

int main(){
      cout<<"Enter a number\n";
    int n;
    int count=0;
    cin>>n;
    for(int i=1; i<=n; i++){
         int space=n-i;
        while (space)
        {
            cout<<" "; 
            space--;
        }

        for(int j=1; j<=i; j++){
            cout<<count++;
        }
        cout<<endl;
    }
}