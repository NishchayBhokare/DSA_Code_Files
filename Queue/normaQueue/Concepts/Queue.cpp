#include<iostream>
using namespace std;

class queue{
    public:
    int *arr;
    int size;
    int f;
    int r;

    queue(int size){
        this->size=size;
        arr=new int[size];
        f = 0;
        r = 0;
    }

    bool isFull(){
        if(r == size) return true;
        return false;
    }

    bool isEmpty(){
        if(f == r) return true;
        return false;
    }

    void enqueue(int data){
        if(isFull()){
            cout<<"Queue is overflow!"<<endl;
            return;
        }
        else{
            arr[r] = data;
            r++;
        }
    }

    void dequeue(){
        if(isEmpty()){
            cout<<"Queue is underFlow!"<<endl;
        }
        else{
            arr[f]=-1;
            f++;
            if(f == r){ //when we reach the condition where both f and r same then point both to beginning and add remaining elements if there.
                f=0;
                r=0;
            }
        }
    }

    void print(){
        int start=f;
        while(start<r){
            cout<<arr[start++]<<" ";
        } cout<<endl;
    }
};

int main(){
    queue q1(5);

    // q1.enqueue(3);
    // q1.enqueue(1);
    // q1.enqueue(0);
    // q1.enqueue(8);
    q1.dequeue();
    // q1.print();

    // q1.enqueue(6);
    // q1.enqueue(6);
    
    q1.print();

}































