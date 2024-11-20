#include<iostream>
using namespace std;

int sumOfN(int n){
 if(n==1){
     return 1;
 }
 else{
     return(sumOfN(n-1)+n);
 }

}

int main(){
 cout<<sumOfN(4);
}