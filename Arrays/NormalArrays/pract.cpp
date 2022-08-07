#include <iostream>
using namespace std;
void fun(int *arr2){
    cout<<arr2[2];
}
int main(){
    int arr[]={2,3,4};
    fun(arr);
}