#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int funct(int a, int b){
    int count = 0;
   //01010
   //10100
//    while(a or b){
//     int aBits=a%2;
//     int bBits=b%2;
//     if(aBits != bBits) count++;
//     a=a>>1;
//     b=b>>1;
//    } 

   int ans = a ^ b;
   while(ans){
        if(ans & 1) count++;
        ans=ans>>1;
    }
   return count;
}

int main(){
    int a=10,b=20;

    cout<<funct(a,b);
}