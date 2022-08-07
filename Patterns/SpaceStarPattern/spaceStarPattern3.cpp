#include<iostream>
using namespace std;

//     *
//    ***
//   *****
//  *******
// *********

int main(){
      cout<<"Enter a number\n";
    int n;
    cin>>n;
    for(int i=1; i<=n; i++){
         int space=n-i;
        //printing space. 
        while (space)
        {
            cout<<" "; 
            space--;
        }

        //printing first traingle of star.
        for(int j=1; j<=i; j++){
            cout<<"*";
        }
        // i.e
            // *
            // **
            // ***
            // ****
            // *****


        //printing second traingle of star.
        for(int k=i-1; k>0; k--){
            cout<<"*";
        }
        cout<<endl;
    }
}