//Example to delete middle element of stack.
//gfg
#include<stack>
using namespace std;

//Approach 1:Optimised Recursive approach. TC-O(N) SC-O(N - for recursive call)
void solve(stack<int>&s, int count,int size){

        if(count==size/2){ //once we reach to middle element in stack. then pop that element and return.
            s.pop();
            return;
        }
        
        int val=s.top(); //store top element in val variable.
        s.pop(); //pop out that element.
        
        solve(s,count+1,size); //call function for next charcater.
        
        s.push(val); //once we delete middle element, then push remaining element into the stack, one by one through recursive call.
    }
    
void deleteMid(stack<int>&s, int n)
{
    int count=0;
    solve(s,count,n); //calling function.
}



//Approach 2: iterative approach Tc-O(N) SC-O(N - for stack)
void deleteMid(stack<int>&s, int n)
{
    stack<int>popped;
    int i=(n/2)+1;  //getting index of middle element.
    while(i--){ //popping out element till middle element.
        popped.push(s.top()); //and pushing those element in popped stack.
        s.pop();
    }
    
    popped.pop(); //the element we want to delete will be on top of popeed stack, so pop out that element.

    while(!popped.empty()){ //and insert all remaing element back to given stack.
        s.push(popped.top());
        popped.pop();
    }
}




