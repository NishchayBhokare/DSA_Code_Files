#include<iostream>
using namespace std;
int main(){
    int a=2; int b=3;
    cout<<"(a & b) "<<(a & b)<<endl; // bitwise and operator when both bit 1 then 1 otherwise 0.  here ans is 2 
    cout<<"(a | b) "<<(a | b)<<endl; // bitwise or operator when any of the bit is 1 then 1 otherwise 0.  here ans is  3
    cout<<"(a ^ b) "<<(a ^ b)<<endl; // bitwise xor operator when one of the bit is 1 then 1 otherwise 0.  here ans is 1 
    cout<<"a~ "<<(~a)<<endl<<endl;         // bitwise not operator it will make 1 to 0 and 0 to 1. here ans is -3 


    //left shift and right shift operator.
    cout<<(17 >> 1)<<endl; //right shift operator so one time division 17/2 = 8.
    cout<<(17 >> 2)<<endl; //right shift operator so two times division 17/2 = 8, 8/2= 4 so ans is 4.
    cout<<(19 << 1)<<endl; //left shift operator so one time multiplication 19 * 2=38. this shortcut technique mostly helful for small number
    cout<<(21 << 2)<<endl; //left shift operator so two time multiplication 21 * 2=42, 42*2=84. so ans is 84.

    //The left shift shortcut technique won't work when 2nd bit from start is 1 and if we do left shif for 1 time then most significant bit will be 1. so while printing no. cause of most significant bit is 1 so printed no. will be in negative.
}