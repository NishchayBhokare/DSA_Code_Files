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
    Complex operator+(Complex obj){
        obj.a+=this->a;
        obj.b+=this->b;
        return obj;
    }
    
    void show_data(){
        cout<<"Value of a is "<<this->a<<" and value of b is "<<this->b<<endl;
    }

};

int main(){
    Complex obj1(3,5);
    Complex obj2(2,6);
    Complex obj3 = obj1.operator+(obj2);
    //Complex obj3 = obj1+obj2; above statement and this statment both are right.

    obj3.show_data(); 
    return 0;
}