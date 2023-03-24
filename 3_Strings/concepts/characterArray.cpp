
#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>

#include<bits/stdc++.h>
using namespace std;

int lengthOfChar(char ch[]){
    int i=0,count=0;
    while(ch[i] != '\0'){
        count++;
        i++;
    }
    return count;
    // cout<<"Length of character array is "<<count;
}

void reverseChar(char ch[]){
    int size = lengthOfChar(ch);
    int j=size-1;
    int i=0;
    while(i<j){
        swap(ch[i++],ch[j--]);
    }
    // cout<<ch;
}

void toLowerCase(char ch[]){

for(int i=0; i<10; i++){
    if(ch[i] >='A' && ch[i] <='Z'){
        ch[i] = ch[i] - 'A' + 'a';
    }
 }
}
void toUpperCase(char ch[]){
for(int i=0; i<10; i++){
    if(ch[i] >='a' && ch[i] <='z'){
        ch[i] = ch[i] - 'a' + 'A';
    }
}
}
int arr[9];

void funct(string s1,char ch[],int arr[]){
 arr[0]=1;
 s1[0] = 'k';
 ch[0] = 'k';
//  cout<<s1<<" "<<ch<<endl;
cout<<s1<<endl;
}
int main(){
    string s1="fekssdkfjksdf dkfsdfl";
    string s2="for Geeks";
    cout<<s1.compare(s2);
    return 0;
}