#include<iostream>
using namespace std;

//Approach 1: Using loops
// int main()
// {
// string str="Nishchay";
// for(int i=0, j=(str.length()-1); i<j; i++,j--){
// swap(str[i],str[j]);
// }
// cout<<str<<endl;
// return 1;
// }

string strReverse(string str,int i,int j){
    //Base case
    if(i > j) return str;

    //Processing
    swap(str[i],str[j]);

    //Recursion function
    return strReverse(str,i+1,j-1);
}

//Approach 2B : Using recursion and pass by reference
void strReverse2(string &str,int i,int j){
    //Base case
    if(i > j) return;

    //Processing
    swap(str[i],str[j]);

    //Recursion function
    strReverse2(str,i+1,j-1);
}

//Approach 2C : Using recursion and only one variable i.
void strReverse3(string &str,int i){
    //Base case
    if( i == (str.length()/2)) return;

    //Processing
    swap(str[i],str[str.length()-i-1]);

    //Recursion function
    strReverse3(str,i+1);
}

int main(){
    string str="Nishchay";
    // string rev=strReverse(str,0,str.length()-1);
    // cout<<rev<<endl;
    // strReverse2(str,0,str.length()-1);
    strReverse3(str,0);
    cout<<str<<endl;
    return 0;
}