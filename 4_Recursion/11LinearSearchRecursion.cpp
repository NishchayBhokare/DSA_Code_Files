//Implementing Linear search using recursion.
#include<iostream>
using namespace std;


bool linearSearch(int *arr, int size, int key){
    //base case
    if( size == 0) return false;
    if(arr[0] == key) return true;

    //Recursive call
    return linearSearch(arr+1,size-1,key);
}

int main(){
int arr[] = {5,3,1,8,2};
int key = 2;
int size = sizeof(arr)/sizeof(int);
if(linearSearch(arr,size,key)) cout<<"Element is present "<<endl;
else cout<<"Element is not present "<<endl;

}