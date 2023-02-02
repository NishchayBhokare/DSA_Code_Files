#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void Extract(string str){
    string ans = "";
    vector <int> vect;
    for(int i=0; i<str.length(); i++){
        //when ith element is alphabets
        if((str[i] >= 'A' and str[i] <= 'Z') or (str[i] >= 'a' and str[i] <= 'z')){
            ans +=str[i];
        }
    }
    for(int i=0; i<str.length(); i++){
        //when ith element is alphabets
        if((str[i] >= '0' and str[i] <= '9')){
            int num = (str[i] - '0') + 0; 
            vect.push_back(num);
        }
    }
    cout<<ans<<endl;
    for(int i=0; i<vect.size(); i++) cout<<vect[i]<<" ";
}

int main(){
    string str= "AB112dK5Z";
    Extract(str);
    return 0;
}