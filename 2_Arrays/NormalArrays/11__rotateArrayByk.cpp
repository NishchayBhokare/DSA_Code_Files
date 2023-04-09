// Rotate array to right by k.
// GFG.
#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;

//Approach 1- Optimize approach (by creating reverse function) TC-O(n) Sc- O(1). 
void Reverse(int arr[],int start,int end){
    while(start < end){
        swap(arr[start++],arr[end--]);
    }
}
void rotateArr(int arr[], int d, int n){
    d = d % n;
    Reverse(arr,0,d-1);
    Reverse(arr,d,n-1);
    Reverse(arr,0,n-1);
}


//Approach 2- Optimize approach(by using inbuilt reverse function) TC-O(n) Sc- O(1).
void rotateArr(int arr[], int d, int n){
    d= d%n; //andling case when d becomes greater than n.
    reverse(arr,arr+d); //reverse first d elements 
    reverse(arr+d,arr+n); // reverse remaining elements i.e d to n-1.
    reverse(arr,arr+n); // lastly reverse whole array.
}


//Approach 3 - Using temporary vector. TC- O(n) SC-O(n).
  void rotateArr(int arr[], int d, int n){
        int ans[n];
        d = d % n;
        int j=0;
        for(int i=d; i<n; i++) ans[j++]=arr[i];
        
        for(int i=0; i<d; i++) ans[j++]=arr[i];
        
        for(int i=0; i<n; i++) arr[i] = ans[i];
    }
 
    
    