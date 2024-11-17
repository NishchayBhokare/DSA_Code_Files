#include<bits/stdc++.h>
using namespace std;

class heap{
    public:
    int arr[100];
    int size = 0;

    void insert(int val){
        int index = ++size;

        arr[index] = val;

        while(index > 1){
            int parentInd = index/2;
            if(arr[parentInd] < arr[index]){
                swap(arr[parentInd], arr[index]);
                index = parentInd;
            }
            else break;   
        }
    }

    void print(int *arr, int size){
        for(int i = 1; i<=size; i++){
            cout<<arr[i]<<" ";
        }
    }

    void deletionInHeap(){
        arr[1] = arr[size]; //putting.
        size--;

        int index = 1;
        while(index < size){
            int leftchild = index * 2;
            int rightchild = index * 2 + 1;

            if((leftchild <= size) and (arr[index] < arr[leftchild])){
                swap(arr[index], arr[leftchild]);
                index = leftchild;
            }
             
            else if((rightchild <= size) and (arr[index] < arr[rightchild]) ){
                swap(arr[index], arr[rightchild]);
                index = rightchild;
            }
                 
            else
                return;
        }
    }

    void heapify(int *arr, int index, int size){
        if(index > size/2) return;

        int leftchild = 2 * index;
        int rightchild = 2 * index + 1;

        int element = arr[index];
        int largest = leftchild;

        if(rightchild <= size &&  arr[rightchild] > arr[largest])
            largest = rightchild;
   
        if(arr[index] < arr[largest])
        { 
            swap(arr[index], arr[largest]);
            heapify(arr, largest, size);
        }
    }

    void heapSort(int *arr, int size){

        while(size > 1){
            //swap first element with last.
            swap(arr[1],arr[size]);

            //decrement size
            size--;

            //call heapify to make first element on it's right position.
            heapify(arr,1,size);
        }
    }
};


int main(){
    heap h;
    // h.insert(50);
    // h.insert(55);
    // h.insert(53);
    // h.insert(52);
    // h.insert(54);

    // h.deletionInHeap();
    int arr[]={-1, 55,50,53};
    int size = 3;


    for(int i = size/2; i>0; i--){
        h.heapify(arr,i, size);
    }

    h.print(arr,size);

    h.heapSort(arr,size);

    // cout<<"after sorting"<<endl;
    // h.print(arr,size);


    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(3);
    pq.push(4);
    pq.push(14);
    pq.push(67);
    pq.push(1);

    cout<<endl;
    cout<<pq.top();
}