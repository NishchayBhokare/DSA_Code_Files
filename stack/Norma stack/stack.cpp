#include<iostream>
using namespace std;

class stack{
    public:
  int *arr;
  int size;
  int top;
};

int main(){
    stack *sp=new stack;
    sp->size=3;
    sp->arr=new int[sp->size];

    sp->top=0;
}