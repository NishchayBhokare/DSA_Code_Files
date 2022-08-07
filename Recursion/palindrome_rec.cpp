#include<iostream>
using namespace std;

bool palindrome(string str,int left,int right){
    if(right<=left){
        return true;
    }

    else if(str[left]!=str[right]){
        return false;
    }
    return palindrome(str,++left,--right);
}

int main(){
    string str="sradars";
    if(palindrome(str,0,str.size()-1)){
        cout<<"Given string is palindrom";
    }
    else{
        cout<<"not palindrome";
    }
    return 0;
}