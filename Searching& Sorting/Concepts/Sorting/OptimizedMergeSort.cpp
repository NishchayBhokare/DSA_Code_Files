#include<iostream>
using namespace std;

void mergeBothArrays(int *arr2,int start, int end){

    int mid = start + (end - start)/2;
    // int len1 = (mid-start+1); //calculating length of first array
    // int len2 = (end-mid); //calculating length of second array

    // int *firstArr = new int[len1];  //creating array for first sub array
    // int *secondArr = new int[len2]; //for second sub array

  //  int mainArrIndex = start; //Index of for given array is pointing to start.
    // for(int i=0; i<len1; i++){ 
    //     firstArr[i] = arr2[mainArrIndex++]; //adding elements in first subarray
    // }
    
    // mainArrIndex = mid+1;
    // for(int i=0; i<len2; i++){
    //     secondArr[i] = arr2[mainArrIndex++]; // adding elements in second subarray
    // }

    //Now Merging two sorted array i.e firstArr and secondArr
    int index1=mid, index2=end;
    // mainArrIndex=start;
    while(index1 >= start && index2 > mid){ //looping till both indexes are less than its array length
        
        if(arr2[index1] > arr2[index2]) swap(arr2[index1],arr2[index2--]);
        else index2--;

    }

}

void mergeSort(int *arr,int start, int end){
    //Base case
    if(start >= end) return;

    int mid = start + (end - start)/2;
    
    //Go to the left part for sorting
    mergeSort(arr,start,mid);

    //Got to the right part for sorting
    mergeSort(arr,mid+1,end);

    //Now,merge both partitioned array 
    mergeBothArrays(arr,start,end);
}

int main(){
    int arr[]={3,7,2,5,12,15,13,14};
    int size = sizeof(arr)/sizeof(int);

    mergeSort(arr,0,size-1);

    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
}