#include<iostream>
using namespace std;
//Best,worst,average TC - O(n logn)
//Stable, Adaptive(after optimization), it is recursive algo.
//It is not in place algo.

// Time Complexity: O(N*logN), merging two arrays take linear time and array is recursively divided into halves (logN times).
// Space Complexity: O(N), we use a temporary array to store elements in sorted order.
void mergeBothArrays(int *arr2,int start,int mid, int end){

    
    int len1 = (mid-start+1); //calculating length of first array
    int len2 = (end-mid); //calculating length of second array

    int *firstArr = new int[len1];  //creating array for first sub array
    int *secondArr = new int[len2]; //for second sub array

    int mainArrIndex = start; //Index of for given array is pointing to start.
    for(int i=0; i<len1; i++){ 
        firstArr[i] = arr2[mainArrIndex++]; //adding elements in first subarray
    }
    
    mainArrIndex = mid+1; //Optional because already mainIndex points to mid+1th element after first loop.
    
    for(int i=0; i<len2; i++){
        secondArr[i] = arr2[mainArrIndex++]; // adding elements in second subarray
    }

    //Now Merging two sorted array i.e firstArr and secondArr
    int i=0, j=0;
    mainArrIndex=start;
    while(i < len1 && j < len2){ //looping till both indexes are less than its array length
        
        if(firstArr[i] <= secondArr[j]) arr2[mainArrIndex++] = firstArr[i++];
        else arr2[mainArrIndex++] = secondArr[j++];

    }

    //If any of the sub array contains elements then add those elements to main array
    while(i < len1) arr2[mainArrIndex++] = firstArr[i++];

    while(j < len2) arr2[mainArrIndex++] = secondArr[j++];

    delete []firstArr; //at the end delete those temporaray first and second subarray.
    delete []secondArr;
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
    mergeBothArrays(arr,start,mid,end);
}

int main(){
    int arr[]={3,7,2,5,12,15,13,14};
    int size = sizeof(arr)/sizeof(int);

    mergeSort(arr,0,size-1);

    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
}



//Approach 2: Another approach striver.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to merge two halves of the array
    void merge(vector<int>& arr, int low, int mid, int high) {
        // Create temp arrays
        vector<int> temp;
        int left = low, right = mid + 1;

        // Merge two sorted halves
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right])
                temp.push_back(arr[left++]);
            else
                temp.push_back(arr[right++]);
        }

        // Copy remaining elements from left half
        while (left <= mid)
            temp.push_back(arr[left++]);

        // Copy remaining elements from right half
        while (right <= high)
            temp.push_back(arr[right++]);

        // Copy sorted elements back to original array
        for (int i = low; i <= high; i++)
            arr[i] = temp[i - low];
    }

    // Recursive merge sort function
    void mergeSort(vector<int>& arr, int low, int high) {
        if (low >= high)
            return;

        // Find the middle index
        int mid = (low + high) / 2;

        // Recursively sort left half
        mergeSort(arr, low, mid);

        // Recursively sort right half
        mergeSort(arr, mid + 1, high);

        // Merge the two sorted halves
        merge(arr, low, mid, high);
    }
};

int main() {
    vector<int> arr = {5, 2, 8, 4, 1};
    Solution sol;
    sol.mergeSort(arr, 0, arr.size() - 1);
    for (int x : arr)
        cout << x << " ";
    cout << endl;
    return 0;
}
