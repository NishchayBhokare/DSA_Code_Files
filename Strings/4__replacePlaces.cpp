//Replace places with "@40".
//on coding ninjas,GFG.
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


// Approach 2 - Using extra string. TC-O(n) SC-O(n).
string replaceSpaces(string &s){
    string temp=""; //extra stirng
    for(int i=0; i<s.length(); i++){
        if(s[i] == ' ') temp += "@40";     //if we encounter space just add "@40".
        else temp.push_back(s[i]); //else whatever alphabet we are getting just add it to the temp.
    }
    return temp; //return temp.
}


//GFG version - Remove only spaces.
//Approach 1 - Most optimised approach. 
//Analogy: keeping itr variable on position where jth element should be at itr position after ignoring space.
//i.e if jth element equals to space then increment jth variable only and when jth is not sapce element then assign jth element to itr element which is its correct position after ignoring space.
//finally return only substring from 0 to itr-1 position.
string modify (string s)
    {
        int itr=0,j=0;
        while(j < s.length()){
            if(s[j] != ' ') s[itr++]=s[j]; 
            j++;
        }
        return s.substr(0,itr);
    }

//Approach 2 - if space is present then mark it as null so that it will not get print.
    string modify (string s)
    {
        for(int i=0; i<s.length(); i++){
             if(s[i]==' ')
            s[i]=NULL;
        }
        return s;
    }

//Approach 3 - Using extra string, i.e except space, insert all elements in ans string.
 string modify (string s)
    {
        string ans="";
        for(int i=0; i<s.length(); i++){
            if(s[i]!=' ') ans+=s[i]; //if not equal to space then only insert in ans string.
        }
        return ans;
    }
