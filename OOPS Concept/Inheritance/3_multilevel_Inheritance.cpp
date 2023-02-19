#include<iostream>
using namespace std;

class animal{
    private:
    int age;
    string name="";
    public:
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
};

class Dog : public animal{ 
    private:
    int age;
    public:
    Dog(){}
    void bark(){
        cout<<"Dog is barking";
    }
};

class Cat : public Dog{ //Multilevel inheritance
    private:
    int age;
    public:
    Cat(){ }
    void express(){
        cout<<endl<<"Cat is here "<<endl;
    }
};

int main(){
    animal obj1(30,"Animal");
   // cout<<obj1.getName()<<endl;

    Dog d1;
    d1.sayHelloAnimal();
    d1.bark();

    Cat c;
    c.express();
    c.bark();
    c.getName();
    return 0;
}