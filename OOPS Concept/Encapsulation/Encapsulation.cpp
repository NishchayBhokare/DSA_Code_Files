//Encapsulation: Encapsulation is basically refers to wrapping/combining data and methods into a single unit or class and protecting it from outside intervention. eg. Bank Account class.
//Encapsulation is nothing but hiding background information.
//Advantages:
    // Encpasulation is a way to achieve data hiding because other classes will not be able to access the data through the private data memebers.
    //In encapsulation, we can hide the data's internal infromation, which is better for security concerns.
    //By encapsulation, we can make the class read-only. The code Reusability is also an Advantage of Encapsulation.
    //Encapsulated code is better for unit testing.

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class animal{
    private:
    string name="";
    int age;

    public:
    animal(string &str,int age){
        this->name=str;
        this->age=age;
    }
    string getName(){ 
        return this->name;
    }
};

int main(){
    string str="lion";
    animal a1(str,34);
    cout<<a1.getName();
    return 0;
}