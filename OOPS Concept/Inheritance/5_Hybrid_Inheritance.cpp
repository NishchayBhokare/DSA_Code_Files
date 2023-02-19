#include<iostream>
using namespace std;

class animal{
    private:
    string name="";
    public:
    int age;
    animal(){}
    animal(int age, string name){
        this->age=age;
        this->name=name;
    }

    void sayHelloAnimal(){
        cout<<"Hello i am animal"<<endl;
    }

    string getName(){
        return name;
    }
    int getAge(){
        return age;
    } 
};

class Dog: public animal{ //simple Inheritance
    private:
    int age1;
    public:
    Dog(){}
    void bark(){
        cout<<"Dog is barking"<<endl;
    }
};

class Lion{
    public:
    void bark(){
        cout<<"Lion is barking"<<endl;
    }
};

class Cat : public Dog, public Lion{ //Multiple inheritance.
    private:
    int age2;
    public:
    Cat(){ }
    void express(){
        cout<<endl<<"Cat is here "<<endl;
    }
};

int main(){
    animal obj1(30,"Animal");
   //cout<<obj1.getName()<<endl;

    Dog d1;
    d1.bark();
    d1.sayHelloAnimal();

    Cat c;
    c.express();
    c.sayHelloAnimal();
    c.Lion::bark(); //object.className :: functionName(); -> to remov ambiguity if same name of function of present in parent classes.
    return 0;
}