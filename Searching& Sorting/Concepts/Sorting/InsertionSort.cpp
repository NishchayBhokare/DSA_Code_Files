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


 void print(int arr[],int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
 }

 void insertionSortUsingRecursion(int arr[], int size, int i){
    if(i == size) return;
    
    int j = i-1; //ek case solve karlo..baki recursion apne aap sambhal lega.
    int key = arr[i];
    while(j>=0 && arr[j] > key){
        arr[j+1]=arr[j];
        j--;
    }
    arr[j+1] = key;
    
    return insertionSortUsingRecursion(arr,size,i+1);
}


int main(){
    int arr[] = {2,7,4,1};
    int size = sizeof(arr)/sizeof(int);
    insertionSort(arr,size); //calling selection sort.
        insertionSortUsingRecursion(arr,size,1);
    print(arr,size); //printing array.
}