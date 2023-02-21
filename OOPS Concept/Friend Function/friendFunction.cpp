#include<iostream>
using namespace std;
 
 //imp:
 //It is not member function of class, we cannot called friend fuction using object, because it does not have any caller object.
 //friend function declared in class and defined in outside of the class.
 //A friend function cannot access the private and protected data members of the class directly. It needs to make use of a class object and then access the members using the dot operator.

class Human{
    private:
    string name="";
    public:
    Human(string name){
        this->name=name;
    }
    
    private:
    friend void sayHello(Human);
    //friend void sayOk(Human);
};

void sayHello(Human obj){
    cout<<"Hello "<<obj.name<<endl;
}

// void sayOk(Human obj){ //this function cannot access members of human object, because it is not friend function for Human class.
//     cout<<"Hello "<<obj.name<<endl;
// }


int main(){
   Human obj("Nishchay");
   sayHello(obj);
  // sayOk(obj);
    return 0;
}