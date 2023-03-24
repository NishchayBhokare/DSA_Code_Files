#include<iostream>
using namespace std;

class circularQueue{
    public:
    int *arr;
    int f,r;
    int size;

    circularQueue(int size){
        this->size=size;
        arr=new int[size];
        f=-1;
        r=-1;
    }

    bool isFull(){
        if((r+1)%size == f) return true;
        return false;
    }

    bool isEmpty(){
        if(f==-1) return true;
        return false;
    }

    void enqueue(int data){
        if(isFull()){
            cout<<"Circular Queue is overFlow "<<endl;
        }
        else{
            if(f == -1){ //when queue is empty 
                f=r=0;
            }
            else{
            r=(r+1)%size; 
            }
            arr[r]=data;
        }
    }

    void dequeue(){
        if(isEmpty()){
             cout<<"Circular Queue is underFlow "<<endl;
        }
        else{
            int val;
            val=arr[f];
            if(f == r){ //when queue have only single element 
                f=r=-1;
            }
            else{
                f = (f + 1) % size;
            }
            // cout<<"Dequeue "<<val;
        }
    }

      void print(){
        int start=f;

        while(start<r){
            cout<<arr[start]<<" ";
            start=(start+1)%size;
        } cout<<endl;
    }
};


int main(){
    circularQueue q1(5);

    q1.enqueue(3);
    q1.enqueue(1);
    q1.enqueue(8);
    // q1.print();
    q1.dequeue();

    q1.enqueue(6);
    q1.enqueue(6);
    //  q1.enqueue(6);

    
    
    // q1.print();

}