#include<iostream>
#include<bits/stdc++.h>
using namespace std;

char * vowelCons(char * str){
 char *ans;
 for(int i=0; str[i] != '\0'; i++){

    if( str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o'  || str[i] == 'u'){
        str[i] ='V';
    }
    else str[i] = 'C';
 }
  

  
}


int main(){
    char str[] = "whereabouts";
  char * ch=vowelCons(str);
  cout<<ch<<endl;
 return 0;
}