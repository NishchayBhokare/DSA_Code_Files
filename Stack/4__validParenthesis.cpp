//Example to check given parenthesis is valid or not.
//gfg
#include<string>
#include<stack>
using namespace std;

//TC-O(N) SC-O(N)
bool ispar(string str)
{
    stack<char>s; //create stack.
    for(int i=0; i<str.length(); i++){ //looping over given string.
        
        char ch=str[i]; //storing character in ch.
        
        if ((ch == '(') or (ch == '[') or (ch == '{')) { //if character is any of the opening bracket, then push in stack.
            s.push(ch);
        }
        else if(!s.empty()){ //else first check whether alredy stack empty or not.
        //if not then enter in block.
          
            char ch2=s.top(); //storing top element of stack into ch2 varible.and checking wheter both contains same opening and closing bracket or not.
            if( (ch == ')' and  ch2=='(') || (ch == ']' and ch2=='[') ||  
            (ch == '}' and ch2 == '{') ){ 
                s.pop();
            }
            else{ //if not then return false.
            return false;
            }
        }
        
        else  //if empty then return false.
            return false;
    }
    
    if(s.empty()) return true; //finally after all iterations if stack is empty then return true, otherwise false.
    return false;
}


 