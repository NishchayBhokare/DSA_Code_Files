#include<iostream>
using namespace std;

void fibonacii(int n){
    int a=0;
    int b=1;
    if(n >= 1) cout<<a<<" ";
    if(n >=2) cout<<b<<" ";
    for(int i=3; i<=n; i++){
        int c = a+b;
        cout<<c<<" ";
        a=b;
        b=c;
    }
}

int fibonaciiRecur(int n){
    //base case
    if(n==1) return 0;
    if(n==2) return 1;

    int third = fibonaciiRecur(n-1) + fibonaciiRecur(n-2);
    return third;
}

int main(){
    int n;
    cout<<"Enter a number to print first n fibonacci series "<<endl;
    cin>>n;
    //fibonacii(n); // Using while loop.

    cout<<fibonaciiRecur(n);
    return 0;
}