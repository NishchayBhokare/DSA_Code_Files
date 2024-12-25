//GFG.


//Approach 1: using simple TC- O(2N) SC-O(N).
//by creating left and right pointer loop over the array if elemnt is first time visiting..then take it into
//sub array update theri sum.
//if element is repeating..then shrink left by 1 before that..assign s[left] in map as 0. i.e we have not visited. yet.
int longestSubstrDistinctChars(string& s) {
    
    unordered_map<char,int>ump;
    
    int left=0, right=0, maxLen=0, n=s.length();
    
    while(right<n){
        
        if(!ump[s[right]]){
            
            maxLen = max(maxLen, right-left+1);
            ump[s[right]] = 1;
            right++;
        }
        else{
            
            ump[s[left]] = 0;
            left++;
        }
    }
    
    return maxLen;
}


//Approach 2: Optimised approach TC- O(N) SC-O(N).
//here we have optimised..insdtead of shifting left by 1 place.
//we are doing left+1 on repeating charaters. and shifting left to repeating characters' index +1.
int longestSubstrDistinctChars(string& s) {
    
    unordered_map<char,int>ump;
    
    int left=0, right=0, maxLen=0, n=s.length();
    
    while(right<n){
        
        if(ump.find(s[right]) == ump.end() || ump[s[right]] < left){ //if we first time visiting string or we have visited the current character but..it's not in scope of length
        //of substring. then also entery in this block.
            
            maxLen = max(maxLen, right-left+1); //tak max length
            ump[s[right]] = right; //update this current element index to right.
            right++; //increment right 
        }
        else{
            
            left = ump[s[right]] + 1; //shifting to repeating characters next index.
        }
    }
    
    return maxLen;
}