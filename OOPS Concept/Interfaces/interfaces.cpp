#include<iostream>
using namespace std;
 
 //imp:
//  Interfaces are nothing but a way to describe the behavior of a class without committing to the implementation of the class. In C++ programming there is no built-in concept of interfaces. 

// In order to create an interface, we need to create an abstract class which is having only pure virtual methods. In C++, Interfaces are also called pure abstract classes.

// The C++ interfaces are implemented using abstract classes and these abstract classes should not be confused with data abstraction which is a concept of keeping implementation details separate from associated data.

// A class is made abstract by declaring at least one of its functions as pure virtual function. A pure virtual function is specified by placing "= 0"

//Purpose:- Purpose is to define some common behaviour that can be inherited by multiple sub classes, without implement the entire class. Abstract classes cannot be used to instantiate objects and serves only as an interface. Attempting to instantiate an object of an abstract class causes a compilation error.





class Human{ //this class is know as abstract class. because it contains at least one pure virtual function.
    public:
    virtual void sayMaleOrFemal() = 0; //pure virtual function.
};

class Male:public Human{
    public:
    void sayMaleOrFemal(){
        cout<<"I am Male "<<endl;
    }
};

class Female:public Human{
    public:
    void sayMaleOrFemal(){
        cout<<"I am Female "<<endl;
    }
};

int main(){
    Male obj1;
    Female obj2;
    obj1.sayMaleOrFemal();
    obj2.sayMaleOrFemal();
    return 0;
}