//Example for find the peak element from the bitonic array.
//peak element is a element whose left and right neighbour is smaller than it.
//On coding ninjas.


#include<bits/stdc++.h>
using namespace std;

//Given array is in bitonic sequence i.e eiter it will be strictly increasing or decreasing or mountain shape(first increase and then decrease)
//Approach 1 :- using binary search algorithm(optimized algo.) : TC- O(logN) SC-O(1)
//using more optimized binary search
int findPeak(vector<int> &arr) {
    int low =0; 
    int high = arr.size()-1;
    while(low < high){ //looping till low < high in this case, cause when low and high pointing to the same node, then that node will be our ans. so no need to enter in loop again cause we already stored our ans as, high = mid.
        int mid = low + (high - low)/2; //finding mid.
        if(arr[mid] < arr[mid + 1]) low = mid+1; //if mid element is smaller than mid+1 element, then our ans will definitely in left part of array so make low to mid+1.

        else high = mid; //if above condition is not true, then you will reach to condition that mid will be the peak element or mid element is less than < mid-1 element.
        //so that's why we update our high to mid and not to mid-1 cause current mid can be also peak element.
    }
    return arr[high];
}

// using Normal binary searach - Better understandable
int findPeak(vector<int> &arr) {
    int n = arr.size();

    // Single element
    if (n == 1) {
        return arr[0];
    }
    // Strictly descreasing
    if (arr[0] >= arr[1]) {
        return arr[0];
    }
    // Strictly increasing
    if (arr[n - 1] >= arr[n - 2]) {
        return arr[n - 1];
    }

    // Binary search
    int l = 1, r = n - 2;
    int ans = 1;
    while (l <= r) {
        int middle = (l + r) / 2;

       if (arr[middle] < arr[middle - 1]) {
            // Search the left half
            r = middle - 1;

        } else if (arr[middle] < arr[middle + 1]) {
            // Search the right half
            l = middle + 1;

        } else { // if(arr[middle] > arr[middle-1] and arr[middle] > arr[middle+1]).
            // Ans found
            return arr[middle];
        }
    }
}


//Approach 2: using linear way : TC- O(N) SC-O(1)
int findPeak(vector<int> &arr) {
    // Array size
    int n = arr.size();
    // If single element, that is the peak
    if (n == 1) return arr[0];

    // If strictly decreasing
    if (arr[0] >= arr[1]) return arr[0];

    // If strictly increasing
    if (arr[n - 1] >= arr[n - 2]) return arr[n - 1];

    for (int i = 1; i < n - 1; i++) { //looping from 1 to n-2 cause if you reach till here then first and last element is not your peak element.
        // Condition for peak
        if((arr[i] > arr[i-1]) && (arr[i] > arr[i+1])){
            return arr[i];
        }
    }
}


//Same example from GFG. (Instead returning peak element, we need to return index of that peak element.)
int peakElement(int arr[], int n)
    {
       // Your code here
       int low=0,high=n-1;
       while(low < high){
           int mid=(low+high)/2;
           if(arr[mid] < arr[mid+1]) low=mid+1;
           else high=mid;
       }
       return high; //returning index of peak element.
    }