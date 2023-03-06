//Example to reverse string using stack.
//GFG
#include<stack>
using namespace std;
//Given input is character array and its length. TC-O(N) SC-O(N)
//Analogy: when you insert elements in stack, then once we started popping out element we will get in reverse order.
char* reverse(char *s, int len)
{
    //code here
    stack<char>st; //creating  stack 

    for(int i=0; i<len; i++){ //inserting all characters in stack.
        st.push(s[i]);
    }

    int i=0;
    while(!st.empty()){ //looping till stack is not empty
       s[i]=st.top(); //one by one taking top most element and inserting in given character array.
        st.pop(); //and popping element.
        i++;
    }

    return s; //return reverse string.
}