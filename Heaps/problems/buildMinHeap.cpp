//Example for building min heap by heapify algorithm
// link- (coding ninja platform)
    // https://www.codingninjas.com/codestudio/problems/build-min-heap_1171167?leftPanelTab=0

#include <iostream>
#include<vector>
using namespace std;

void heapify(vector <int> &arr,int n,int i){
    int smallest=i;
    int left= 2 * i+1;
    int right=2 * i+2;
    
    if(left < n and arr[smallest] > arr[left]){ //only differences are left < n and we are checking whether parent is greater than child if yes, then change index of parent i.e smallest 
        smallest=left;
    }
    
    if(right < n and arr[smallest] > arr[right]){
        smallest=right;
    }
    
    if(smallest != i){
        swap(arr[smallest],arr[i]);
        heapify(arr,n,smallest);
    }
}

vector<int> buildMinHeap(vector<int> &arr)
{
    int n=arr.size(); //getting size of vector.
    for(int i=(n/2-1); i>=0; i--){//looping from n/2-1  to i>=0 (cause 0 based indexing) i.e from left to right.
        heapify(arr,n,i);
    }
        return arr;
    
}
