#include<iostream>
using namespace std;

class heap{
    public:
    int *arr;
    int size;

    heap(){
        arr = new int[100];
        size = 0;
    }

    void insertNode(int data){
        size++;
        int index = size;
        arr[index] = data;

        while(index > 1){
            int parent = index/2;
            if(arr[parent] < arr[index]){
                swap(arr[parent],arr[index]);
                index = parent;
            }
            else return;
        }
    }

    void print(){
        for(int i=1;  i<=size; i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
    }

    void deleteFromHeap(){

        //step 1: replace with last element
        arr[1] = arr[size];

        //step 2: 
        size--;

        //step 3;
        int index = 1;
        while(index < size){
            int leftChild = index*2;
            int rightChild = index*2+1;

            int largest;
            if(leftChild <= size and arr[leftChild] > arr[rightChild])
                largest = leftChild;

            else largest = rightChild;
            
            if(arr[index] < arr[largest]){
                swap(arr[index],arr[largest]);
                index = largest;
            }
            else 
                return;
        }
    }
};


void heapify(int arr[],int index, int size){
    int largest = index;
    int leftchild = index*2;
    int rightchild = index*2 + 1;

    if(leftchild <= size and arr[largest] < arr[leftchild]){
        largest = leftchild;
    }

    if(rightchild <= size and arr[largest] < arr[rightchild]){
        largest = rightchild;
    }

    if(largest != index){
        swap(arr[largest],arr[index]);
        heapify(arr,largest,size);
    }
}


void heapSort(int arr[], int n){
    int size = n;
    while(size > 1){
        swap(arr[1],arr[size]);
        size--;
        heapify(arr,1, size);
    }
}

int main(){

    heap h;
    // h.insertNode(50);
    // h.insertNode(55);
    // h.insertNode(53);
    // h.insertNode(52);
    // h.insertNode(54);

    // h.print();

    // h.deleteFromHeap();

    // h.print();

    int arr[6] = {-1, 50, 53, 55, 52, 56};
    int n=5;
    for(int i=n/2; i>=1; i--){
        heapify(arr,i,n);
    }

    for(int i=1; i<=n; i++) cout<<arr[i]<<" ";

    heapSort(arr,n);

    cout<<"After sorting function. "<<endl;
    for(int i=1; i<=n; i++) cout<<arr[i]<<" ";
    return 0;
}