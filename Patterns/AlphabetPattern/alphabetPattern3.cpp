#include<iostream>
using namespace std;
// int main(){
//      cout<<"Enter a number\n";
//     int n;
//     cin>>n;
//     char ch='A';

//     for(int i=1;i<=n;i++){
//         for(int j=1; j<=n; j++){
//             cout<<ch++;
//         }
//         cout<<endl;
//     }
// }


// or

int main(){
     cout<<"Enter a number\n";
    int n;
    cin>>n;
    int count=0;
    for(int i=1;i<=n;i++){
        for(int j=1; j<=n; j++){
            char ch='A' + count;
            cout<<ch;
            count++;
        }
        cout<<endl;
    }
}