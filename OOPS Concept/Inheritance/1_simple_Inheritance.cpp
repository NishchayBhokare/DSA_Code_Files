#include<iostream>
using namespace std;

class animal{
    private:
    int age;
    string name="";
    public:
    animal(){cout<<"I am in parent class"<<endl;}
    animal(int age, string name){ //this is nothing but constructor overloading. overloading with number of parameters.
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

class Dog : public animal{ //Simple inheritance
    private:
    int age;
    public:
    Dog(){cout<<"I am in base class";}
    void bark(){
        cout<<"Dog is barking";
    }
};

int main(){
   // animal obj1(30,"Animal");
   // cout<<obj1.getName()<<endl;

    Dog d1;
    // d1.sayHelloAnimal();
    // d1.bark();
    return 0;
}