#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//Method overriding is possible through inheritance only.

class c{
    public:
    // c(){
    //     cout<<"I am constructor of class c"<<endl;
    // }
    // ~c(){
    //     cout<<"I am destructor of class c"<<endl;
    // }
};
class A{
    public:
    // A(){
    //     cout<<"I am constructor of class A"<<endl;
    // }
    // ~A(){
    //     cout<<"I am destructor of class A"<<endl;
    // }
    
    virtual void sayHello(){
        cout<<"Hey Nishchay!"<<endl;
    }
};

class B: public A{
    public:
    // B(){
    //     cout<<"I am constructor of class B"<<endl;
    // }
    // ~B(){
    //     cout<<"I am destructor of class B"<<endl;
    // }

    //  void sayHello(){ //Method overriding -> here we are override method present in base class with new implementation.
    //     cout<<"Hey Nishu!"<<endl;
    // }
};

int main(){
    // A obj1;
    A *ptr;
    B obj2;
    ptr=&obj2;
    obj2.sayHello();
    ptr->sayHello();
    return 0;
}