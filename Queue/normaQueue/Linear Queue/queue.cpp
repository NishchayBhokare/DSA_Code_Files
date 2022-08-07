#include<iostream>
using namespace std;

class queue{
    public:
    int *arr;
    int size;
    int f;
    int r;
};

int isFull(queue *q){ 
 if(q->r==q->size-1){
    return 1;
 }
 return 0;
}

int isEmpty(queue *q){
 if(q->r==q->f){
    return 1;
 }
 return 0;
}

void Enqueue(queue *q,int data){
    if(isFull(q)){
     cout<<"Enqueue Operation is not possible"<<endl;
    }
    else{
       q->r++;
       q->arr[q->r]=data;
    }
}

int Dequeue(queue *q){
    if(isEmpty(q)){
     cout<<"Dequeue Operation is not possible"<<endl;
    }
    else{
       q->f++;
       return q->arr[q->f];
    }
}


int main(){
    queue *q=new queue;
    int size;
    q->size=4;
    q->f=q->r=-1;
    q->arr[q->size];

    Enqueue(q,3);
    Enqueue(q,7);
    Enqueue(q,9);
    Enqueue(q,2);

    cout<<"Removed element is "<<Dequeue(q);
    cout<<"Removed element is "<<Dequeue(q);
    cout<<"Removed element is "<<Dequeue(q);
    cout<<"Removed element is "<<Dequeue(q);
    cout<<"Removed element is "<<Dequeue(q);
    cout<<"Removed element is "<<Dequeue(q);

}
