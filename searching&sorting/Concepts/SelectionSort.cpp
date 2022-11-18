#include<iostream>
using namespace std;

//After every pass we will get (i+1)th smallest element.
//Best TC- O(n2), Worst Tc- O(n2)
//Not stable, Not Adaptive, Not recursive
//Use Case- Useful When list is small,as the TC is O(n2) which makes it inefficient for a large list.
//When memeory space is limited because it makes the minimum number of swaps during sorting.
 void selectionSort(int arr[],int n){
    
    for(int i=0; i<n-1; i++){ //looping from 0 to n-1 cause last element will automatically sorted.
        int minIndex = i; //assuming first ith index is minIndex.
        for(int j = i+1; j<n; j++){ //looping from i+1 to less than n, to search for minimum element than minIndex element.
            if(arr[j] < arr[minIndex]) minIndex = j; //if we found element less than minIndex then just change minIndex to j.
        }
        swap(arr[minIndex],arr[i]); //and after looping out from inner for loop, just swap arr[minIndex] with arr[i]. before incrementing i.
    }
 }


 void print(int arr[],int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
 }

int main(){
    int arr[] = {5,4,2,8,3};
    int size = sizeof(arr)/sizeof(int);
    selectionSort(arr,size); //calling selection sort.
    print(arr,size); //printing array.
}