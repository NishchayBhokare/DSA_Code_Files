#include<iostream>
using namespace std;

//In bubbleSort on every pass, we are getting ith largest element from an array.
//so if array is already sorted, then there won't be any swapping so, isSort will be 1 and we will loop out from bubble sort, that's why Best Time Complexity is O(n).
//Best TC - O(n), Worst Tc- O(n2)
//Stable, Adaptive(after optimization), Not recursive
//Use Case - On ith round, we placed ith largest element to its right position.
//Useful When list is small,as the TC is O(n2) which makes it inefficient for a large list.

//Approach 1: using loops.
 void bubbleSort(int arr[],int n){
    for(int i=1; i<n; i++){ //for no. of passes. total n - 1 cases maximum required to sovle. on every pass ith largest element will be added from last of array.
    int isSort = 1; //We are assuming given array is sorted.
        for(int j=0; j<(n-i); j++){ //looping from 0 to n-i cause, on every pass j's range will be decrement, thats why n-i;
            if(arr[j]>arr[j+1]) { //if jth element is greater than j+1th element then swap.
            swap(arr[j],arr[j+1]);
            isSort = 0; //if we enter in if block that means given array is not sorted, so assign isSort to 0.
            }
        }
        if(isSort) return; //after one pass, if isSort is still 1, that means given array is already sorted.
    }
    
 }


//Approach 2: using recurion.
void bubbleSortRecursion(int arr[],int n){
    //base case
    if(n==0 || n==1) return; //if size of array is eiter 0 or 1 then return simply.

    for(int i=0; i<(n-1); i++){ //solving only one case i.e moving largest number to end of an array.
        if(arr[i] > arr[i+1]) swap(arr[i],arr[i+1]);
    }

    return bubbleSortRecursion(arr,n-1); //for recrsive call simpley decremnt size by 1 cause we already sorted one element.
}


 void print(int arr[],int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
 }

int main(){
    int arr[] = {1,6,90,2,3,7,4,34,5};
    int size = sizeof(arr)/sizeof(int);
    //bubbleSort(arr,size); //calling bubble sort. (loops wala)
    bubbleSortRecursion(arr,size); //Calling recurion wala
    print(arr,size); //printing array.
}