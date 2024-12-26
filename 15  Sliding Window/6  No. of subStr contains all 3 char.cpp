//GFG.
//Number of substring containing all three characters. (count substring).

//Approach 1: Most optimised approach. TC-O(N) SC-O(1).
//Logic is we're starting from index 0 to n-1. and we are checking on current character index. how many valid substrings 
//can be possible. we're checking this by taking min index of all three characters.
//once we got min index. then count of substrings' which are ends at current index will be 
// 1 + minIndex. (1 is for current valid substring. and + minindex for the substrings which are forming before this current substring.)
int countSubstring(string s) {
    
    int n=s.length(), subStrCnt=0, index=0;
    
    unordered_map<char,int>charInd;
    
    for(char ch='a'; ch<='c'; ch++) //creation of unordered map of size three which includes character to int mapping.
        charInd[ch] = -1; //all three characters index are marked as -1.
    
    while(index < n){
        
        charInd[s[index]] = index; //update character index for every character when we reach on this statement.
        
        int minStartIndSubStr = min({charInd['a'], charInd['b'], charInd['c']});
        //now take min index among all three.
        
        subStrCnt += 1 + minStartIndSubStr; //increment count of valid substring 
        
        index++;
    }
    
    
    return subStrCnt;
}


//Approach 2: TC-O(2N) SC-O(1).
int countSubstring(string s) {
    
    int n=s.length(), cnt=0;
    int left = 0, right = 0;
    
    unordered_map<char,int>ump;
    
    while(right < n){ //looping till right less than n.
        
        ump[s[right]]++; //incrment frequency of s[right] character in map.
        
        while(ump.size() == 3){ //if size equals to three that means we got valid substring.
            
            cnt += (n-right); //if u observe..we have to take all substring counts which are started on index left. so those substrings will be n-right
            ump[s[left]]--; //once we take all substring for current left index. then decrement frequency of this character in map.
            
            if(ump[s[left]] == 0) ump.erase(s[left]); //if frequency is 0 then erase it. 
            left++; // increment left.
        }
        
        right++;
    }
    
    
    return cnt;
}