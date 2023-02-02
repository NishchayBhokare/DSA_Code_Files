#include<iostream>
using namespace std;

bool checkPalindrome(string str){
    int i=0,j=str.size()-1;
    while( i<j ){
        if(str[i++]!=str[j--]) return false;
    }
    return true;
}

int main(){
    string str="baacab";
    if(checkPalindrome(str)){
        cout<<"Given string is palindrome"<<endl;
    }
    else{ 
        cout<<"Given string is not palindrome"<<endl;
    }
}