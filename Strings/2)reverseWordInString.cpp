//Example to reverse word in string.
//on gfg and leetcode.

#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
 

 //Using stack Tc-O(n) SC-O(n). (on gfg)
 string reverseWords(string s) 
    { 
       
       stack <string> st; //creating stack.cause we will insert whole word in stack starting from left to right. and after at the end we will pop out word one by one.
       string temp = "";
       string ans="";
       for(int i=0; i<s.length(); i++){ //looping from 0 to less than length.
           if(s[i] != '.') temp += s[i]; //if we get alphabet, then add in temp string
           else{
             st.push(temp);  //when we get dot then, add that temp which contain word to stack.
             temp=""; //and reinitialise temp to empty string.
           }
       }
       ans += temp; //inserting last element in ans directly cause we are looping from 0 to less than size.
       while(!st.empty()){ //now looping till stack not get empty.
           ans += '.' + st.top(); //first add dot and then add top most word in string.
           st.pop(); //pop out that word.
       }
       return ans; //return our ans.
    } 


    //slight change for example at leetcode.
    //Using stack Tc-O(n) SC-O(n). (on leetcode)
      string reverseWords(string s) {
       stack <string> st;
       string temp = "";
       string ans="";
         if(s =="" || s==" ") return "";
       for(int i=0; i<s.length(); i++){
          if(s[i] == ' ' && temp.length()>0){ //if we encounter space then check whether temp length greater than 0 or not.
             st.push(temp); 
             temp="";
           }
           else if(s[i] != ' ') temp += s[i]; //if s[i] is not space then only add in temp.
       }
       if(temp.length()>0) st.push(temp); //instead adding temp to ans directly for last element, push that temp in stack, beacuse to deal with ending extra space in given string.
       ans+=st.top();
       st.pop();
       while(!st.empty()){
           ans+=' '+st.top();
           st.pop();
       }
       return ans;
    }