///Minimum insertion required to make parenthesis valid.
//Leetcode.
 
//Approach 1: Most optimised Approach. TC-O(N)
int minAddToMakeValid(string s) {
        
    int ans = 0, op=0; //instead of stack. we're using variable of opening bracket instead of stack.
    for(auto ch:s){

        if(ch == '('){ //if opening bracket found. increment count of opening bracket.
            op++;
        } 
        else{ //if closing bracket found.

            if(op==0)  //if opening bracket count is zero..then we need to insert one opening bracket 
            //for current closing bracket. so increment ansCnt.
                ans++;
            
            else //else decerment opening count.
                op--;
        }
    }

    ans+=op; //at the end..check if opening bracket count present or not.
    //if present. then those number of closing bracket we required to insert.

    return ans;
}



//Approach 2: Using stack. TC-O(N) SC-(N)
int minAddToMakeValid(string s) {
    
    int ans = 0;
    stack<char>st;
    for(auto ch:s){

        if(ch == '('){
            st.push(ch);
        } 
        else{

            if(st.empty()) 
                ans++;
            
            else
                st.pop();
        }
    }

    ans+=st.size();

    return ans;
}

