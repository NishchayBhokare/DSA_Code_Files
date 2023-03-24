//Remove all adjacent elements in string.
//on leetcode.
#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

//Most optimized in place solution TC-O(n) SC-O(1).
//Approach 1:-
 string removeDuplicates(string s) {
        int len = s.length(); //first calculating length of string.
        for(int i=0; i<(len-1); i){ //looping till len-1 cause not need to check for last element.
            if(s[i] == s[i+1]){ //if adjacent element is similar then enter in loop.
                s.erase(i,2); //erase those adjacent elements
               len = len - 2; //reduce length by 2.
                if(i > 0) i--; //if i greater than 0, then move to previous index for further check cause we delete both the elements so we need to move previous index by 1.
            }
            else i++; //if not same just increment i.
        }

        return s;   //return our ans.  
    }


//Approach 2: using extra string. TC-O(n) SC-O(n)
string removeDuplicates(string s) {
        string ans="";
        int i=0;
        for( int i=0; i < s.length(); i++){
           if(ans.length()>0 and s[i] == ans[ans.length()-1]){ //checking if current element is equals to element at last index in ans string, if it is same then pop out that element from ans string because both are adjacent duplicate element.
               ans.pop_back();
           }
           else{ //if not same then just push that unique element in ans vector.
               ans+=s[i];
           }
        }
       
        return ans;
    }    

//Approach 3:Using stack extra space. TC-O(n) SC-O(n). 
    string removeDuplicates(string s) {
      stack<char> st; //creating stack.
      for(int i=0; i<s.length(); i++){

         if(st.empty()) st.push(s[i]);  //if stack is empty then push that ith element in stack and move to next itreation.    
         else if(st.top() != s[i]) st.push(s[i]); //if top most element is not equal to s[i] then push s[i] in stack.
          else{
              st.pop(); //if top most element is same then pop that top most element from stack.
          }

      }

        s=""; //Initialising string s, so that we not need to get another extra space.
        while(!st.empty()){ 
            s.push_back(st.top()); //pushing one by one element from stack to string.
            st.pop(); //poping out element from stack.
        }
        
      reverse(s.begin(),s.end()); //reversing our answer cause stack is lifo and we want characters from first to last, which is bottom in stack so that's why reverse string s.
      return s;  //return our answer.
    }

    