#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int num=123;
    vector<string>vec={"zero","one","two","three","four","five","six"};
    string str=to_string(num);
    int index;
    for(int i=0; i<str.length(); i++){
        index=str[i]-'0';
        cout<<vec[index]<<" ";
    }
    return 0;
}