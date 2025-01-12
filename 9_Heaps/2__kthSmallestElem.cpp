//Example for kth smallest element in array using heap and also other algo.
// link- 
    // https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1

#include <bits/stdc++.h>
using namespace std;



//Approach 1- most efficient approach using max heap. TC- O(NlogK) SC- O(k);
//behind below algo. analogy is we are creating heap of k elements so for eg. if k=4 then we will create heap of 4 elements. so within that 4 element top most element refers to 1st largest and 4 th smallest element. but we have some other elements in array so we compare remaining  elements of array with top element from heap. so if element is less than top() we will delete top and push array element so that after comparing with all elements finally we will get 4 elements in heap and topMost elemnet will be 4th smallest and 1 st largest element among remaining 3 elements;

int kthSmallest(int arr[], int l, int r, int k) {
    priority_queue<int> pq;
    for(int i=0; i<k;i++){ //creating heap of only k elements.
        pq.push(arr[i]); //pushing into heap.
    }

    for(int j=k;j<=r;j++){  //now comparing heap's top with remaining elements i.e k to r elements.
        if(arr[j] < pq.top()){ //if element is smaller than pq's top then we will enter in if loop.
            pq.pop(); //poppin out top element from heap.
            pq.push(arr[j]); //and finally pushing that smaller element in heap.
        }
    }
    return pq.top(); //returning top most element from heap.
}



//Approach 2- using minheap TC-O(nlogn) SC- O(n);
int kthSmallest(int arr[], int l, int r, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i=0; i<=r;i++){
        pq.push(arr[i]);
    }
    k--; //cause 0 base indexing we decrement k-- i.e kth element is k-1th element in araay.
    while(k--){ //till k!=0
        pq.pop(); //poping out so that next smallest element will be in top of heap.
    } //basically we are poping till k-1 th times so if k=4 then 3 times we will pop so that we can get 4th smallest element at the top of heap.
    return pq.top();
}


//Approach 3- using sorting and while loop TC- O(nlogn) , SC-O(1)
int kthSmallest(int arr[], int l, int r, int k) {
    r++;
            // sort(arr, arr + r,greater<int>()); //for sort in decreasing order
    sort(arr, arr + r); //for sort in increasing order.
    int small=arr[k-1];  //k-1 cause zero base indexing.
    return small;
}