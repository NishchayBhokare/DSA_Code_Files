#include<iostream>
using namespace std;

//In bubbleSort on every pass, we are getting ith largest element from an array.
//so if array is already sorted, then there won't be any swapping so isSort will be 1 and we will loop out from bubble sort, that's why Best Time Complexity is O(n).
//Best TC - O(n), Worst Tc- O(n2)
//Stable, Adaptive(after optimization), Not recursive
//Use Case - On ith round, we placed ith largest element to its right position.
//Useful When list is small,as the TC is O(n2) which makes it inefficient for a large list.

 void bubbleSort(int arr[],int n){
    for(int i=0; i<(n-1); i++){ //for no. of passes.
    int isSort = 1; //We are assuming given array is sorted.
        for(int j=0; j<(n-1-i); j++){ //looping from 0 to n-1-i cause, on every pass j's range will be decrement, thats why n-1-i;
            if(arr[j]>arr[j+1]) { //if jth element is greater than j+1th element then swap.
            swap(arr[j],arr[j+1]);
            isSort = 0; //if we enter in if block that means given array is not sorted, so assign isSort to 0.
            }
        }
        if(isSort) return; //after one pass, if isSort is still 1, that means given array is already sorted.
    }
    
 }


 void print(int arr[],int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
 }

int main(){
    int arr[] = {1,3,4,5};
    int size = sizeof(arr)/sizeof(int);
    bubbleSort(arr,size); //calling selection sort.
    print(arr,size); //printing array.
}



//Recursive Bubble Sort.
void bubbleSort (int arr[], int size){
    if(size == 1 or size == 0) return;
    
    for(int i = 0; i<size-1; i++){ //solving first case only. 
        if(arr[i] > arr[i+1]) swap(arr[i],arr[i+1]);
    }
    
    bubbleSort(arr,size-1);
}
int main()
{
    int arr[] = {300,21,1,89,5};
    int size = 5;
    bubbleSort(arr,size);
   
   for(int i = 0; i<size; i++) cout<<arr[i]<<" ";
   
   return 0;
}



//Bubble sort using recurison:
#include <bits/stdc++.h>
using namespace std;

// Recursive Bubble Sort with early exit optimization
void bubble_sort(int arr[], int n) {
    // Base Case: if the size is 1, it's already sorted
    if (n == 1) return;

    int didSwap = 0; // Flag to check if any swap occurred in this pass

    // One pass: push the largest element to the end
    for (int j = 0; j <= n - 2; j++) {
        if (arr[j] > arr[j + 1]) {
            // Swap arr[j] and arr[j + 1]
            int temp = arr[j + 1];
            arr[j + 1] = arr[j];
            arr[j] = temp;
            didSwap = 1; // Mark that we did a swap
        }
    }

    // If no swap happened, array is already sorted
    if (didSwap == 0) return;

    // Recurse for the remaining unsorted portion
    bubble_sort(arr, n - 1);
}

int main() {
    int arr[] = {13, 46, 24, 52, 20, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before Using Bubble Sort: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    bubble_sort(arr, n);

    cout << "After Using Bubble Sort: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
