//Implement two stacks in an array
//Coding ninja & GFG.
class TwoStack {
    vector<int>arr;
    int size;
    int top1, top2;

public:
    // Initialize TwoStack.
    TwoStack(int s) {
        size = s;
        arr.resize(size);
        top1=-1;
        top2=size;
    }


//Approach to solve problem, TC-O(1) SC-O(size for array)
//Analogy create top1 and top2, insert element for top1 from left to right and for top2 from right to left.
void  push1(int x)
{   
    // if(top1+1 == top2) return; //or we can write this also..to avoid overlflow condition.

    if(top2 - top1 > 1){ //if top2-top1 is greater than one then only insert. 
        top1++;
        arr[top1]=x;
    }
}
   
//Function to push an integer into the stack2.
void push2(int x)
{
    if(top2 - top1 > 1){
        top2--;
        arr[top2]=x;
    }
}
   
//Function to remove an element from top of the stack1.
int pop1()
{
    if(top1==-1) return -1; // stack is empty
    else{
        int val=arr[top1];
        top1--;
        return val;
    }
}

//Function to remove an element from top of the stack2.
int pop2()
{
    if(top2==size) return -1; //similarly if top2 equals to size then stack is empty for top2.
    else{
        int val=arr[top2];
        top2++;
        return val;
    }
}

};