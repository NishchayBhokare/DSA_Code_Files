#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Complex{
    private:
    int a,b;
    public:
    Complex(){}
    Complex(int a,int b){
        this->a=a;
        this->b=b;
    }
    void operator++(){
        this->a++;
        this->b++;
    }
    
    void show_data(){
        cout<<"Value of a is "<<this->a<<" and value of b is "<<this->b<<endl;
    }

};

int main(){
    Complex obj1(3,5);
   ++obj1; 
   //obj1.operator++(); This statement performs same as above statement.

    obj1.show_data(); 
    return 0;
}