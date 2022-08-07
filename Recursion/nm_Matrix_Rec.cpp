#include<iostream>
using namespace std;

int matrix(int n,int m)
{
 if(n==1||m==1){
     return 1;
 }
 else{
     return (matrix(n-1,m) + matrix(n,m-1));
 }
}
int main(){
    cout<<matrix(2,2);
}