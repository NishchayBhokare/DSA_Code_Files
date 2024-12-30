//GFG.

//Approach 1: Iterative approach.
bool sentencePalindrome(string &s) {
    
    int left=0, right=s.length()-1;
    
    while(left < right){
        
        if(!isalnum(s[left]))
            left++;
        
        else if(!isalnum(s[right]))
            right--;
            
        else{
            
            if(tolower(s[left]) != tolower(s[right]))
                return false;
            
            left++;
            right--;
        }
    }
    
    return true;
}


//Approach 2: Recursive approach.
bool solve(int left, int right, string &s){
    
    if(left >= right) return true;
    
    if(!isalnum(s[left]))
        left++;
    
    else if(!isalnum(s[right]))
        right--;
        
    else{
        
        if(tolower(s[left]) != tolower(s[right]))
            return false;
        
        left++;
        right--;
    }
    
    return solve(left, right, s);
}

bool sentencePalindrome(string &s) {
    
    int left=0, right=s.length()-1;
    
    return solve(left, right, s);
}