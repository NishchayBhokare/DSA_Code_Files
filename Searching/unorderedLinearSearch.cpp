//Example of unordered linear search i.e when array is not sorted. 
#include<iostream>
using namespace std;

void unorderedLinearSearch(int arr[],int size,int e){
    int count=0;
   for(int i=0;i<size;i++){
    count++;
    if(arr[i]==e){ //checking element is present or not.
        cout<<"Element "<<e<<" is prsent at index "<<i<<" and count is "<<count;
        return;
    }
   }
   cout<<"Element is not present and count is "<<count<<endl;
}

int main(){
 int arr[]={1,5,2,8,6,19,20};
 int size=sizeof(arr)/sizeof(arr[0]);
 int e=8;
 unorderedLinearSearch(arr,size,e);
 return 0;
}