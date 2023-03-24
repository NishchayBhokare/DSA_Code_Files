//Example for reversing integer and find absolute difference betn reverse integer and given integer.
#include<iostream>
using namespace std;

int main(){
    int a= 345; 
    int b=a;
    int revA=0;
    while(a!=0){ //looping till given integer not become 0.
        int digit = a%10; //taking moduls to get one by one digit.
        revA=(revA * 10) + digit; //storing digit in revA.
        a/=10; //reducing a.
    }
    cout<<abs(b - revA)<<endl; //taking absoulte diffence between b and revA.
}