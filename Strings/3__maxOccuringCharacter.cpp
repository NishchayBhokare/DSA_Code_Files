//Example to find maximum occuring character in string.
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//Tc-O(n) SC is constant.
char getMaxOccuringChar(string s)
    {
       vector<int> v(26,0); //creating vector of size 26 cause there are only 26 letters in alphbets.
       for(int i=0; i<s.length(); i++){ //looping over string
           v[s[i] - 'a']++; //Analogy is we are mapping 0 to a and 25 to z so, if s[i] is c then c-a will be 2 so we will increment by 1 to 2nd index cause 2 is mapped with c.
       }
       
       int maxCount=0;//maxCount refers to count of that character. it nothing but maxi
       int index=0; //index will points to index of maxCount that will convert into alphabet
       for(int i=0; i<v.size(); i++){
          if(v[i] > maxCount){ //if current count is greater than maxCount
              maxCount = v[i]; //then update maxCount 
              index = i; //and store i which is index of maxCount.
          }
       }
       
       return ('a' + index); //return character a + index so if index is 2 then 'a' + 2 is 'c' 
    }