//Stack Implementation Using Linked List.

#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next=NULL;
    
    Node(int data){
        this->data=data;
    }
};

Node *top=NULL; //creating top pointer of Node class which will point to the top most element of stack.

int isFull(){
    Node *n=new Node(0); 
    if(n == NULL) return 1; //if created node gets as NULL then memeory is full in stack using linked list.
    return 0; 
}

int isEmpty(){
    if(top == NULL) return 1; //if top pointing to null, then stack is empty
    return 0;
}

void push(int data){
    if(isFull()){
        cout<<"Stack is full "<<endl;
    }
    else {
        Node *n=new Node(data); //creating node.
        n->next=top; //pointing that node to top.
        top=n; //and shifting top to n.
    }
}

void pop(){
    if(isEmpty()){
        cout<<"Stack is underFlow! "<<endl;
    }
    else{
        Node *n=top; //creating one pointer which points to top.
        top=top->next; //shifting top to next of top.
        delete n; //and deleting that n node.
    }
}

void StackTop(){
    cout<<"Top of stack is "<<top->data<<endl; //returning top most element of stack.
}

void print(){ //printing stack.
    Node *ptr=top;
    while(ptr != NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    } cout<<endl;
}
int main(){
    push(3);
    push(5);
    push(7);

    // pop();
    // pop();
    // pop();
    // pop();
    // StackTop();
    print();
    
    return 0;
}