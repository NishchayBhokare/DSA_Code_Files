#include<iostream>
using namespace std;

int binSearch(int arr[],int low, int high, int key){
int mid = (low + high)/2;

//base case
if(low > high) return -1; //When element is not found
if(arr[mid] == key) return mid; //When element is found

//Recursion function
if(key > arr[mid])  return binSearch(arr,mid+1,high,key);
else return binSearch(arr,low,mid-1,key);

}

int main(){
    int arr[] = {1,3,5,7,9,11,13};
    int key = 13;
    int n= sizeof(arr)/sizeof(arr[0]);
    int index = binSearch(arr,0,n-1,key);
    if(index > -1) cout<<"Index of given key is "<< index<<endl;
    else cout<<"Given key is not found"<<endl;
    return 0;
}