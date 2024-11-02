//Example to check given string is palindrome or not.
//simple version is on gfg and variation is on coding ninjas.
#include<iostream>
using namespace std;

//Simple version of palindrome string to check when given string is full of characters.
// Tc - O(n) SC is constant.
int isPalindrome(string s)
	{
	    int i=0, j =s.size()-1;
	    while(i < j){
	        if(s[i] != s[j]) return false; //checking if not equal then simply return false.
	        i++; j--; //else increment i and decrement j.
	    }
	    return true;
	}



//This is variation in simple version. i.e when given string can contain alphabets, numbers and spacial characters.
char lowerCase (char ch){
    if(ch >='A' && ch <='Z'){
        ch = ch - 'A' + 'a';
    }
    return ch;
}

bool checkPalindrome(string s)
{
 
    int i=0;
    int j=s.size()-1;
    while(i <= j){

      if(isalnum(s[i]) == 0) i++; //checking whether current character is alph numberic or not. if not then just move to next character.

      else if(isalnum(s[j]) == 0) j--; //checking whether current character is alph numberic or not. if not then just move to next character.

      else if(lowerCase(s[i]) != lowerCase(s[j]) ) { //if we reach till here that means charcter is alphaNumeric.
      //so if ith element not equals to jth element that means string is not palindrome so return false.
          return false;
      }

      else{ //if same then just increment i and decrement j.
          i++; j--;
      } 

    }
    return true; //finally return true.



{
        if((s[i] < 'a' || s[i] > 'z') && (s[i] < 'A' || s[i] > 'Z') && (s[i] < '0' || s[i] > '9' )){
            //checking if ith element is not in range of a to z and A to Z and 0 to 9, if not in range then increment i.
            i++;
        }  //You can use this instead of isalnum built in function.
        
      else if((s[j] < 'a' || s[j] > 'z') && (s[j] < 'A' || s[j] > 'Z') && (s[j] < '0' || s[j] > '9' )){
            j--;
      } 
        
}


//Regular version.
//gfg check palindrome -> using recurison.
int checkUsingRecursion(string &str,int start,int end){
	    if(start >= end) return 1;
	    
	    if(str[start] != str[end]) return 0;
	    
	    checkUsingRecursion(str,start+1,end-1);
	}
	
	int isPalindrome(string S)
	{
	    // Your code goes here
	    return checkUsingRecursion(S,0,S.length()-1);
	}

}