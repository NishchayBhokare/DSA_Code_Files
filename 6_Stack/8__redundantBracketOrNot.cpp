//Expression contains redundant bracket or not
//GFG

//Approach TC-O(N) SC-O(N)
 int checkRedundancy(string s) {
        // code here
    stack<char>st;
    for(int i=0; i<s.length(); i++){
        if(s[i] == '(' or s[i] == '+' or  s[i] == '-' or  s[i]=='*'  or  s[i] == '/'){
            st.push(s[i]);
        }
        if(s[i] == ')'){
           bool redundant=true;
           while(st.top() != '('){ //checking till opening bracket not encounter, is there operator or not between opening and closing bracket, if operator is encounter then mark redundant as false
               char top=st.top();
               if(top == '+' or  top == '-' or  top=='*'  or  top == '/') redundant=false;
               st.pop();
           }
           st.pop(); // removing that opening bracket
           if(redundant) return true;
        }
    }

    return false;
}


//Approach 2: similar like above but not that much efficient..look and code vise.
bool findRedundantBrackets(string &s)
{   
    stack<char>st;
    for(int i = 0; i<s.size(); i++){
        if(s[i] == '(' || s[i] == '+' || s[i] == '-' || 
            s[i] == '*' || s[i] == '/'){
                st.push(s[i]);
        }
        else if(s[i] == ')'){
            bool flag = false;
            while(!st.empty() && ((st.top() == '+') ||( st.top() == '-') ||
                (st.top() == '*') || (st.top() == '/'))){
                    flag = true;
                    st.pop();
            }
            
            if(flag) st.pop(); //if we get inside the function then this is valid..so do pop for opening bracket.
        }
    }

    while(!st.empty() &&( (st.top() == '+') ||( st.top() == '-') ||
        (st.top() == '*') || (st.top() == '/'))){
            st.pop();
    }

    if(st.size()>0) return true;
    return false;
}
