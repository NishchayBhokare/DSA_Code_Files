//Example of binary search. i.e array is totally sorted. 
#include<iostream>
using namespace std;

void binarySearch(int arr[],int size,int e,int low,int high){
    int count=0;
    int mid;
    while (low<=high)
    {   
        count++;
         mid=(low+high)/2; //  we can write in this way also, mid=low+(high-low)/2;

        if(arr[mid]==e){
            cout<<"Element "<<e<<" is prsent at index "<<mid<<" and count is "<<count;
            return;
        }
        else if(e > arr[mid]){ //if element is greater than arr[mid] then definitely it will present in right of the mid.
            low=mid+1; //pointing low to mid+1 position to search in right side of the array
        }
        else{ //if element is less than arr[mid] then definitely it will present in left of the mid.
            high=mid-1; //pointing high to mid-1 position to search in left side of the array
        }
    }
    cout<<"Element is not present and count is "<<count<<endl;  
}

int main(){
 int arr[]={1,4,6,12,19,20,45,500};
 int size=sizeof(arr)/sizeof(arr[0]);
 int e=500,low=0,high=size-1;
 binarySearch(arr,size,e,low,high);
 return 0;
}