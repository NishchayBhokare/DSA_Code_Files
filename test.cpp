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

    void print(){
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

};


int main(){
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    h.deletionInHeap();

    h.print();
}