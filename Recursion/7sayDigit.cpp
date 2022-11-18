//in function number will given we have to print that number in words i.e for 3 output will be three.

#include<iostream>
using namespace std;

void sayDigit(int n,string arr[]){
    //Base case
    if(n==0) return;

    //Processing
    int digit = n % 10; //getting last digit from n number
    n = n / 10; //reducing n.

    //Recursion function.
    sayDigit(n,arr);

    cout<<arr[digit]<<" "; //we are printing when base case hit and it will return. 
}

int main(){
int n=682;
string arr[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
sayDigit(n,arr);
return 0;
}