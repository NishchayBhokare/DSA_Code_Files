//Create N stacks in single array
//Coding ninja

//Approach 1:optimised approach.
Logic : 
top[] size = no. of stacks, and it contains  index of top element of respective stack. e.g top element of 2nd stack will be kept in [2-1]th stack.
// if ith stack is empty then top[i] = -1;
// we initialise top[] with -1 as all stacks are empty during initialisation.

freespot : denotes index of arr which is free, so we can push element there, and we need to update freespot to next available free spot!
// we initialise freespot to 0 and if we are pushing an element then we'll update freespot to next free spot and that'll be 1 that's why we initialise next[] with 1!  //next[0] = 1 

Next: stores next free spot, eg. for i = 0, next free spot is 1 , next[0] = 1;
// //it's primary goal is to update freespot variable with next free index, 
// after that we can store previous element in it why ? 
// coz when we pop then we will have to update top of stack with previous element, 
// and we can easily access it this way!.

next : 2 functions
// 1. it'll contain next free spot
// 2. after assigning freespot ,it contains prev element index (it is actually current top element , after we push 'x' it'll become prev!)

class NStack
{
public:

    int *arr;
    int *top;
    int *next;
    int freeSpot;
    // Initialize your data structure.
    NStack(int N, int S)
    {   //N -> size of stack.
        //S -> size of array
        arr=new int[S];
        top=new int[N]; //top array will point top most element of every stack
        next=new int[S]; //next will show, two things, either next free spot or previous element of stack top (in the case of pop it is useful thats why it is using).

        for(int i=0; i<N; i++){ //initialising all top to -1
            top[i]=-1;
        }

        for(int i=0; i<S; i++){ //initialising next current index to next free spot i.e next index
            next[i]=i+1;
        }
        next[S-1]=-1; //and at last index in next arr, point it to -1, because there is no further free spot available
        freeSpot=0; //this freeSpot variable is nothing but starting index of free list in next arr, and  will give us free space and update as per next arr.
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        if(freeSpot == -1) return false; //Array is full, so element can't pushed

        //getting index where we will store element in array
        int index = freeSpot;

        //storing element into the array at index position
        arr[index] = x;

        //Updating free spot i.e update the starting index of free list
        freeSpot=next[index];

        //Updating next array i.e pointing top index -> before updating top..add current element in next array.
        next[index] = top[m-1];

        //Update the top i.e point top to latest inserted element index.
        top[m-1] = index;  

        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        if(top[m-1] == -1) return -1; //if top is -1 then stack is empty
        //Exactly opposite of push

         // getting the index of the top element of the stack.
        int index=top[m-1];

         // Remove the element from the stack by updating the head/top of the stack list.
        top[m-1] = next[index]; //now next of index is ...previous element's index for top.

        // Add the free slot to the free list.
        next[index] = freeSpot; //now remove mapping of previous element's index and add freespot as current index.
        freeSpot = index; //now this current index will be free to insert.

        int popped = arr[index]; //return popped elemnet.


        return popped;
    }
};


//Approach 2: creating stacktracker to track all elements for every stack.
#include <bits/stdc++.h> 
class NStack
{
public:
//this is how stacktracker will look like. for below eg. before popping out.
// 3 6 5
// 1 10 1
// 1 20 1
// 1 30 2
// 2 1
// 2 2

 top[i]  stack[i]
    0 -> 0 1 (these are indexes.)
    1 -> 2
    2 ->
    // Initialize your data structure.
    int *arr;
    vector<stack<int>>stackTracker;
    int size;
    NStack(int N, int S)
    {   
        size = S;
        arr = new int[S];
        stackTracker.resize(N); //creating stacktracker of size N (number of stacks.)
        for(int i = 0; i<S; i++) arr[i] = -1;
    }

    int getAvailableIndex(int *arr, int size){
        int i = 0;
        while(i<size && arr[i] != -1) i++;
        if(i<size) return i;
        return -1;
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {   int stNo = m-1;
        int index = getAvailableIndex(arr,size);
        if(index != -1){
            arr[index] = x;
            stackTracker[stNo].push(index);
            return true;
        }
        else return false;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        int stNo = m-1;
        if(stackTracker[stNo].size() > 0){
            int index = stackTracker[stNo].top();
            stackTracker[stNo].pop();
            int val = arr[index];
            arr[index] = -1;
            return val;
        }
        else return -1;
    }
};