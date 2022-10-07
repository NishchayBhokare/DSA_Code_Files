//Replace places with "@40".
//on coding ninjas.
#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

//Most optimized in place solution TC-O(n) SC-O(1).
//Analogy- First count total no. of places then loop from back and according to position, shift elements.
string replaceSpaces(string &s){
    int spaces =0; //Initially count of spaces is zero.
    for(int i=0; i<s.length(); i++){
        if(s[i] == ' ') spaces++; //if we found any spaces just increment count;
    }
    
    int position = spaces * 2; //now we have to add three elements so additionally we required 2 more space cause 1 space is already there in between words. so position is nothing but at what position we need to shift element so that we can add "@40"
    int i= (s.length()-1); //looping from back.
    s.resize(s.length() + position); //resizing length of string to current length + position.
    
    for(; i>=0; i--){
        if(s[i] != ' ') s[i+position] = s[i]; //if we get aphabet then just shift to i+position index.
        else{ //when we encounter space it's time to add "@40" so, at i+pos there will be last element i.e 0 and i+pos-2 index @ will present.
            s[i+position] ='0'; s[i+position-1] ='4'; s[i+position-2] = '@';
            position = position - 2; //decrementing position by 2 for further checks.
        } 
    }
    return s; //return s.
}


//using extra string. TC-O(n) SC-O(n).
string replaceSpaces(string &s){
    string temp=""; //extra stirng
    for(int i=0; i<s.length(); i++){
        if(s[i] == ' ') temp += "@40";     //if we encounter space just add "@40".
        else temp.push_back(s[i]); //else whatever alphabet we are getting just add it to the temp.
    }
    return temp; //return temp.
}
