#include<iostream>
using namespace std;

// int main(){
    // char ch='A';
//     cout<<"Enter a number\n";
//     int n;
//     cin>>n;
//     for(int i=1; i<=n; i++){
//         for(int j=1; j<=n; j++){
//             cout<<ch<<" ";
//         }
//         ch++;
//         cout<<endl;
//     }
// }

// or

int main(){
    cout<<"Enter a number\n";
    int n;
    cin>>n;
    for(int i=1; i<=n; i++){
    char ch='A' + i - 1;
        for(int j=1; j<=n; j++){
            cout<<ch<<" ";
        }
        cout<<endl;
    }
}