// #include<iostream>
// using namespace std;
// int main(){
//      cout<<"Enter a number\n";
//     int n;
//     cin>>n;

//     for(int i=1;i<=n;i++){
//     char ch='A';
//         for(int j=1; j<=n; j++){
//             cout<<ch++;
//         }
//         ch++;
//         cout<<endl;
//     }
// }

// or

#include<iostream>
using namespace std;
int main(){
     cout<<"Enter a number\n";
    int n;
    cin>>n;

    for(int i=1;i<=n;i++){
        for(int j=1; j<=n; j++){
            char ch='A' + j - 1;
            cout<<ch;
        }
        cout<<endl;
    }
}
