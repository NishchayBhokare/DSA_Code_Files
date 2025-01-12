//Expression contains redundant bracket or not
//GFG
//see approach 2 for better understanding.

//Approach 1 Without using stack..but not much readable. TC-O(N) SC-O(1)
int checkRedundancy(string s) {
    stack<char>charSt;
    
    int i=0, opening=0;
    while(i<s.length()){
        
        if(s[i] == '('){ //if found opening bracket then increment its count.
            opening++;
            i++;
        }
            
        else if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/'){ //if found operator.
            
            if(opening>0) opening--; //then decrement count by 1
            
            while(i<s.length() && s[i]!='(' && s[i] != ')') //and loop till current character is operator.
                i++; //once we found opening or closing bracket then break from loop.

            //why opening bracket to break. Because we have to increment count for opening bracket. that's why we're looping out so that we can
            //increment this opening count in next iteration.

            //and why closing bracket. because after closing bracket..there might be possibilities of operator.
            //for those operator we have to decrement opening. so. for eg. ((a+b+c)+d).so here
            //after first closing bracket..there are operators. which are for first opening bracket.
            //if we removed middle valid part. then eg will be (+d) i.e (1+d).
        }

        else //if we not found operator. we found closing bracket then increment count.
        //don't decrement opening..because..we only decrement opening...when we found operator.
            i++;
    }

    if(opening==0)
        return false;
        
    return true;
}



//Approach 2 TC-O(N) SC-O(N)
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
               st.pop();
               if(top == '+' or  top == '-' or  top=='*'  or  top == '/') redundant=false;
           }
           st.pop(); // removing that opening bracket
           if(redundant) return true;
        }
    }

    return false;
}


//Approach 3: similar like above but not that much efficient..look and code vise.
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
