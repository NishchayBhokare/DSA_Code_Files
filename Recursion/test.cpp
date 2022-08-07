#include<iostream>
using namespace std;
int fun(int a){
    return ++a;
}
int main(){
    int a=3;
    cout<<fun(a);
}