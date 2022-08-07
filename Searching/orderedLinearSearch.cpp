//Example of ordered linear search i.e when array not sorted. 
#include<iostream>
using namespace std;

void unorderedLinearSearch(int arr[],int size,int e){
    int count=0;
   for(int i=0;i<size;i++){
    count++;
    if(arr[i]==e){
        cout<<"Element "<<e<<" is prsent at index "<<i<<" and count is "<<count;
        return;
    }
    else if(e<arr[i]){ //if condition when element 'e' is less than arr[i] that means element is not present in array
        cout<<"Element is not present and count is "<<count<<endl;
        return;
    }
   }
}

int main(){
 int arr[]={1,4,6,12,19,20,45};
 int size=sizeof(arr)/sizeof(arr[0]);
 int e=2;
 unorderedLinearSearch(arr,size,e);
 return 0;
}