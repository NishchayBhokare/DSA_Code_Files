#include<iostream>
using namespace std;

// 1234554321
// 1234**4321
// 123****321
// 12******21
// 1********1

int main(){
    int n;
    cout<<"Enter a number for Dabang Pattern"<<endl;
    cin>>n;

    for (int i = 1; i <=n; i++)
    {
        //First traingle of numbers.
        for (int j = 1; j<= (n-i+1); j++)
        {
            cout<<j;
        }

        //for middle star pattern
        for(int star=i-1; star>0; star--){
            cout<<"**";
        }

        //second traingle of numbers.
         for(int j=(n-i+1); j>=1; j--){
        cout<<j;
       }
        //or
        // for (int j = 1; j<= (n-i+1); j++)
        // {
        //     cout<<(n-i-j+2);
        // }

        cout<<endl;
    }
}