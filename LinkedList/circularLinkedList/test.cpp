#include<iostream>
using namespace std;
int main(){
    int arr[]={};
    arr[0]=3;
    arr[1]=5;
    cout<<arr[0];
    int size=sizeof(arr)/sizeof(arr[0]);
    cout<<"size of array is "<<size;
    return 0;
}