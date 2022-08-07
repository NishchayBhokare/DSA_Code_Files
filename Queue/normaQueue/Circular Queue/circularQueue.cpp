#include<iostream>
using namespace std;

class circularQueue{
  public:
  int *arr;
  int f,r;
  int size;  
};

int isFull(circularQueue *q){
 if(((q->r+1) % q->size) == q->f ){ //eg. size is 8 and r+1=7+1=8 % 8= 0 and if f==0 then queue is full.
   return 1;
 }
 return 0;
}

int isEmpty(circularQueue *q){
 if(q->r ==q->f){
   return 1;
 }
 return 0;
}

void enqueue(circularQueue *q,int data){
    if(isFull(q)){
        cout<<"Queue is full"<<endl;
    }
    else{
        q->r=(q->r+1 % q->size);
        q->arr[q->r]=data;
        cout<<"Enqueued element is "<<data<<endl;
    }
}

void dequeue(circularQueue *q){
    int val;
    if(isEmpty(q)){
        cout<<"Queue is Empty"<<endl;
    }
    else{
        q->f=(q->f+1 % q->size);
        val=q->arr[q->f];
        cout<<"Qequeued element is "<<val<<endl;
    }
}

int main(){

    circularQueue *q=new circularQueue;
    q->size=5; //even size is 5 but we can add only 4 elements cause front is stand where no element can added.
    q->f=q->r=0;

    enqueue(q,3);
    enqueue(q,8);
    enqueue(q,1);
    // enqueue(q,9);
    // enqueue(q,9);
    // enqueue(q,9);
    // enqueue(q,9);



    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);
    dequeue(q);


}