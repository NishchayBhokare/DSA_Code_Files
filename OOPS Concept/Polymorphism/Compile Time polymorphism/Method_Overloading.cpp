//Compile time polymorphism is also known as static polymorphism. This type of polymorphism can be achieved through function overloading or operator overloading.
#include<iostream>
using namespace std;

int add(int a,int b,int c){
    return (a+b+c);
}

int add(int a,int b,double c){ //concept of method overloading i.e same name of function but different parametes.
    return (a+b+c);
} 

int add(int a, int b){ //concept of method overloading i.e same name of function but different number of parametes.
    return (a+b);
}

int main(){
    int a=3,b=2,c=1;
    double k=5;
    cout<<add(a,b,c)<<endl;
    cout<<add(a,b)<<endl;
    cout<<add(a,b,k)<<endl; //Method overloading 
    return 0;
}