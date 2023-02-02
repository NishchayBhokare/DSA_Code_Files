#include<iostream>
using namespace std;

//Remember this algo. as cards. Insert new element from i-1 to 0th pos.
//Best TC - O(n), Worst Tc- O(n2)
//Stable, Adaptive, Not recursive
//Use Case - When array is nearly sorted, it will perform very well cause it is adaptive.
//Useful When list is small,as the TC is O(n2) which makes it inefficient for a large list.
//When array is totally sorted then it will only take O(n) passes.

 void insertionSort(int arr[],int n){

    for(int i=1; i<n; i++){ //for no. of passes, we are starting from 1 st index by assuming 0th element is sorted.
        int j = (i - 1); //j pointing to the previous element of i th pos.
        int key = arr[i]; // storing ith value in key,cause we may need to shift array elements.
        while(j >= 0 && arr[j] > key){ //looping till j>=0 and jth element should be greater than ith element i.e key.
            arr[j+1] = arr[j]; //if greater then shift jth element to j+1 pos. that is copy jth element to j+1th pos.
            j--; //decrement j, so that we can compare with remaining elements.
        }
        arr[j+1] = key; //because of we're doing j--, after while loop we always stand on previous pos. instead of pos. where we should stand to insert that key element, so that we will insert key at j+1 th index pos.
    }

 }

void insertionSortRecursion(int arr[],int n){

    if(n <= 1) return; //if size is equal to 1 or  less than 1 then return;

    insertionSortRecursion(arr,n-1); //solve first n-1 elements


    //after returning back, initially n will be 2.
    int i=n-1; //i will be the second element initially n-1 i.e 2-1 = 1
    int j=n-2; //j will be the first element initially n-2 i.e 2-2=0
    int key = arr[i];
    while( j>=0 && arr[j] > key) {
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = key;
}

 void print(int arr[],int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
 }

int main(){
    int arr[] = {2,7,8,4,1};
    int size = sizeof(arr)/sizeof(int);
   // insertionSort(arr,size); //calling selection sort.
    insertionSortRecursion(arr,size);
    print(arr,size); //printing array.
}