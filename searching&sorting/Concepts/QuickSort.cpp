#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//Best TC - O(nlogg), Average Tc - O(nlogn) Worst Tc- O(n2)
//Worst case come when array is already sorted and best case come when pivot element stands at middle in the array.
//Not Stable, NOt Adaptive, Recursive
//It is in place algorithm i.e it does not take extra space to sort elements.


int partition(int arr[],int s,int e){ //In partitonIndex function we're doing two things first is, positioning pivot element i.e first element on its right position. and second is, positioning elements such that left part of pivot element should be less than or equal to pivot element and right part of sub array should be greater than pivot element.
    int count =0; 
    int pivot = arr[s];
    for(int i=s+1; i<=e; i++){ //Checking how many elemtns is lesser than pivot element so that we can move pivot element on its right position.
        if(arr[i] < pivot) count++; //increment count if element is less than pivot i.e start element.
    }

    int pivotIndex = s+count;
    swap(arr[s],arr[pivotIndex]); //moving pivot element on its right position. i.e s+count.

    int i=s,j=e; //Now positioning elements such that left part is smaller than pivot element and right part is larger than pivot element.
    while(i<pivotIndex && j>pivotIndex){ //looping till i is less than pivotIndex and j is greater than pivotIndex.

        while(arr[i] < arr[pivotIndex]) i++; //if ith element is less than pivot element then simply increment i, cause no need to swap, as we have left part is smaller.
        while(arr[j] >= arr[pivotIndex]) j--; //if jth element is greater than pivot element then simply decreemnt j.
        if(i<pivotIndex && j>pivotIndex) swap(arr[i++],arr[j--]); //if control reaches till here, that simply means, ith element is greater than pivot element and jth element is less than pivot element.
    }
    return pivotIndex;
}

void quickSort(int arr[],int s, int e){
    //Base case
    if(s >= e) return; //if condition when start becomes equals or greater than end then simply return.
    int partitionInd = partition(arr,s,e);
    quickSort(arr,s,partitionInd-1); //quick sort in left part of sub array.
    quickSort(arr,partitionInd+1,e); // quick sort in right part of sub array.
}

int main(){
    int arr[]={2,4,1,6,9,1};
    int size = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr,0,size-1);
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
}