//Create N stacks in single array
//Coding ninja

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

    //Updating next array i.e pointing top index
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
        top[m-1] = next[index];

        // Add the free slot to the free list.
        next[index] = freeSpot;
        freeSpot = index;

        int popped = arr[index];


        return popped;
    }
};