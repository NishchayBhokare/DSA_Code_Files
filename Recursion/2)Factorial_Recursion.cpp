#include<iostream>
using namespace std;

int factorial(int n){
//Base case
if(n==0){
    return 1; //because factorial of zero is 1.
}

    int ans =  n * factorial(n-1);
    return ans;
    //OR return n * solve(n-1).
}


int main(){
    int n=4;
    cout<<" "<<factorial(n);
}