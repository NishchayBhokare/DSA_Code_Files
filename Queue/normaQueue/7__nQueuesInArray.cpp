//N Queues in an array 
//Coding ninja
class NQueue{
public:
    // Initialize your data structure.
    int *arr;
    int *next;
    int *front;
    int *rear;
    int freeSpot;
    NQueue(int n, int s){
        arr = new int[s];
        next = new int[s];
        for(int i=0; i<s; i++){
            next[i] = i+1;
        }
        next[s-1] = -1;
            
        front = new int[n];
        rear = new int [n];
        for(int i=0; i<n; i++){ //initialising front and rear's with -1.
            front[i]=-1;
            rear[i]=-1;
        }
        freeSpot = 0;
    }

    // Enqueues 'X' into the Mth queue. Returns true if it gets pushed into the queue, and false otherwise.
    bool enqueue(int x, int m){

        if(freeSpot == -1) return false; //Overflow condition

        //find first free index
        int index = freeSpot;
        
        //inserting element at that index in array
        arr[index] = x;

        //Update free spot that is point to next free spot.
        freeSpot = next[index];

        if(front[m-1] == -1){ //when we are inserting first element
            front[m-1] = index; //updating front to given index.
        }
        else{ //when there are more than one element then, 
            next[rear[m-1]] = index; //linking new element to prev element, when we insert new element next[rear[m-1]] will give us index on which rear will point when we update rear in next step.
        }

        next[index] = -1; //and pointing this latest inserted element index as -1 because this is last element wherer we insert element, and when we pop out element that time this will help.
        
        rear[m-1] = index;//updating rear to next index.
        return true;
    }


    // Dequeues top element from Mth queue. Returns -1 if the queue is empty, otherwise returns the popped element.
    int dequeue(int m){
        if(front[m-1] == -1)  return -1; //Underflow condition

        //first getting index to pop.(front will always points to index of first element)
        int index = front[m-1]; 
        //storing element of that index in arr
        int val = arr[index];

        //Updating front to next of index that pointing to next element
        front[m-1] = next[index];
        
        //then update index that points to free spot. so that we can track those free spot.
        next[index] = freeSpot;

        //pointing freespot to now index where we are currently pop out. 
        freeSpot = index;
        return val; //return val.
    }
};