#include<iostream>
using namespace std;

void powerSet(string str,int i,string curr){
    if(i==str.length()){
         cout<<curr<<",";
         return;
    }
    else
    {
        powerSet(str,i+1,curr+str[i]);
        powerSet(str,i+1,curr);
    }

}

int main(){
    string str="ab",curr="";
    int i=0;
    powerSet(str,i,curr);
    return 0;
}