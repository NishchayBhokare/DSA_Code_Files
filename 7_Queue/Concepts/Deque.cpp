#include<iostream>
using namespace std;

class Deque
{
public:
  int *arr;
    int f,r;
    int size;
    // Initialize your data structure.
    Deque(int size)
    {
        // Write your code here.
        this->size=size;
        arr=new int[size];
        f=-1;
        r=-1;
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int data)
    {
        if(isFull()){
           return false;
        }
        else{
            if(f == -1){ //when queue is empty 
                f=r=0;
            }
            else if(f==0 and r!=size-1){ //This is extra condition to maintain cyclic nature
                f=size-1;
            }
            else{
                f--; 
            }
            arr[f]=data;
            return true;
        }
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int data)
    {
         if(isFull()){
            return false;
        }
        else{
            if(f == -1){ //when queue is empty 
                f=r=0;
            }
            else{
                r=(r+1)%size; 
            }
            arr[r]=data;
            return true;
        }
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
        if(isEmpty()){
             return -1;
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
            return val;
        }
    }

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
        if(isEmpty()){
             return -1;
        }
        else{
            int val;
            val=arr[r];
            if(f == r){ //when queue have only single element 
                f=r=-1;
            }
            else if(r == 0){ //This is extra condition to maintain cyclic nature.
                r=size-1;
            }
            else{
                r--;
            }
            return val;
        }
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
       if(isEmpty()) return -1;
       return arr[f];
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
        if(isEmpty()) return -1;
       return arr[r];
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
         if(f==-1) return true;
        return false;
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
        if((r+1)%size == f) return true;
        return false;
    }
};


int main()
{
    Deque dq1(5);
    dq1.pushFront(4);
    dq1.pushRear(2);
    cout<<dq1.getFront()<<endl;
    cout<<dq1.getRear()<<endl;
}