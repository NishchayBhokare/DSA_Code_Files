//Stack Implementation Using Array.

#include<iostream>
using namespace std;
class Stack{
  public:
  int *arr;
  int size;
  int top;

  Stack(int size){
    top=-1;
    this->size=size;
    arr=new int [this->size];
  }

  void peek(int i){
    int index=top-i+1; //formula to get mapping equation between array index and current number of element.
    if(index < 0){
      cout<<"Not a valid position in stack"<<endl; //if index is less than 0, then position is not valid.
    }
    else{
      cout<<arr[index]<<" "; //printing index;
    }
  }

  void print(){ 
    //printing stack by calling peek function. 
    // for(int i=1; i<=top+1; i++){
    //   peek(i);
    // }

    for(int i=0; i<=top; i++){
      cout<<arr[i]<<" ";
    }cout<<endl;
  }

  int stackTop(){ //function to return top most element of stack.
    return arr[top];
  }


  int isFull(){
    if(top == size-1) return 1; //condition for isFull, if top equals to less than size of array then simply return true;
    return 0; //else false;
  }

  int isEmpty(){
    if(top==-1) return 1; //for empty if, top equals to -1, then stack is empty.
    return 0; //else return 0 that is not empty.
  }

  void push(int val){
    if(isFull()){ //Checking whether already stack is full or not.
      cout<<"Stack is already full i.e overflow "<<endl; //if yes then simply print cout and return;
    }
    else{ //if not full then push element in stack.
      top++; //increment top
      arr[top]=val; //and enter value at tha top index in array.
    }
  }

  void pop(){ //popping out element from stack
    if(isEmpty()){ //Similarly check stack is alredy empty or not.
      cout<<"Stack is alredy empty "<<endl;
    }
    else{
      top--; //if not then just decrement top.
    }
  }

};
int main(){
  Stack *st=new Stack(5);
  st->push(3);
  st->push(5);
  st->push(1);
  st->push(2);
  st->push(8);

  st->print();
  cout<<"Top most element in stack is " <<st->stackTop()<<endl;

  cout<<"After popping out element stack is "<<endl;
  st->pop();

  st->print();
  return 0;
}