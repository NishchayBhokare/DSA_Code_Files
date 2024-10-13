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
    //Approach 1: Using stack Tc-O(n) SC-O(n). (on leetcode)
      string reverseWords(string s) {
       string word = "";
       stack<string>st;
       for(int i = 0; i<s.size(); i++){
        if(isalnum(s[i])) word.push_back(s[i]); //if element is alpha numer push into the word string
        else{
            if(word.length() > 0){ //else if word is complete then push it into stack.
                st.push(word);
                word = "";
            }
        }
       }
       if(word.length() > 0) st.push(word); //push last word also.
        s = "";
        while(!st.empty()){ 
            s+= st.top()+' '; //add space after each word.
            st.pop();
        }
        s.pop_back();

        return s;
    }

    //Apporach 2: Most optimised Leetcode solution. TC-O(N) SC-O(1);
    //logic is we're removing space by replacing alphanumeric letters on that index.
    //and at last resize size of the string.
    string reverseWords(string s) {
       reverse(s.begin(),s.end()); //first reverse the string.
       int L=0,R=0,i=0,n=s.size();
       while(i < n){
            while(i<n && !isalnum(s[i])) i++; //skip spaces

            if(i == n) break; //if length equals to n while skipping spaces that means no need to do further steps.
            while(i<n && isalnum(s[i])) s[R++] = s[i++];  //if i element is alphanumeric then add it to the Right position and increment both.

            reverse(s.begin()+L,s.begin()+R); //now reverse that particular word
            //L points to start of the word and R points to end of word+1.
    
           if(R < n) s[R++]=' '; //handling condition if R goes out of bond. //after word end..add space and increment R
            L=R; //update L for to start with new word.
       }
       if(!isalnum(s[R-1])) s.resize(R-1); //as if we add R < n due to which two cases are possible...we added space to last element or won't. if we added space then resize till R-1th number
       else s.resize(R); //else resize till R.
       return s; //return our ans.
    }

    //Approach 3 : without taking extra spaces. TC-O(N) SC-O(1)
     string reverseWords(string s) {
       
        cout<<str<<endl;
       int i = 0,j=s.length()-1,k=0,n=s.length();

        //removing starting and ending spaces.
        while(i<n && !isalnum(s[i]) ) i++;
        while(j>=0 && !isalnum(s[j]) ) j--;

        if(j < (n-1)) s.erase(j+1); //removing ending spaces. remove from j+1 st index till the end.
        if(i > 0) s.erase(0,i); //removing starting spaces. i denotes number of elements to delete.

        //removing spaces present between words.
        i=0;
        while(i<s.length()){
            if(isalnum(s[i])) i++; //if alpha numeric increment i.
            else{ //else
                j=i; //point j to ith index.
                while(j<s.length() && !isalnum(s[j])) j++; //then increment j till j equals to space element.
                s.erase(i,(j-i-1)); //now erase spaces which starts from ith index and (j-i-1) number of spaces should delete. -1 because we want one space to keep between word.
                i++; //now because i curently points to space and due to erase other extra spaces.. next element will be alpha numeric.
            }
        }

        //now reverse each word from string.
        i=0,j=0;
       while(k<n){
        if(isalnum(s[k])) k++; //to reach till end of current word increment k.
        else{
            j = k-1; //now point j to k-1.
            reverse(s.begin()+i,s.begin()+j+1);//now reverse current word.
            i=k+1; //now move on to next word.
            k++; //and also move k to next word to check length of word.
        }
       }

        j=k; //we might miss last word so point j now j equals to n.
       reverse(s.begin()+i,s.begin()+j); //reverse last word.

       reverse(s.begin(),s.end()); //finally reverse string.
       return s; //return our ans.
    }
  
