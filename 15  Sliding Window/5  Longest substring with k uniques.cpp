//GFG.
//Approach is similar like previous question.
//just instead of less than 2 or greater than 2. here we have greater than k or equals to k.
//Approach 1: Most optimised TC-O(N) SC-O(k)
int longestKSubstr(string &s, int k) {
        
    int maxLen = -1, n=s.length();
    int left = 0, right = 0;
    unordered_map<char,int>ump;
    
    while(right < n){
        
        ump[s[right]]++;
        
        if(ump.size() > k){
            
            ump[s[left]]--;
            
            if(ump[s[left]] == 0)
                ump.erase(s[left]);
                
            left++;
        }
        
        
        if(ump.size() == k)
            maxLen = max(maxLen, right-left+1);
        
        right++;
    }

    return maxLen;
}   


//Approach 2: TC-O(2N) SC-O(K)
 int longestKSubstr(string &s, int k) {
    
    int maxLen = -1, n=s.length();
    int left = 0, right = 0;
    unordered_map<char,int>ump;
    
    while(right < n){
        
        ump[s[right]]++;
        
        while(ump.size() > k){
            
            ump[s[left]]--;
            
            if(ump[s[left]] == 0)
                ump.erase(s[left]);
                
            left++;
        }
        
        
        if(ump.size() == k) 
            maxLen = max(maxLen, right-left+1);
        
        right++;
    }

    return maxLen;
}


//Approach 3: TC-O(N2) SC-O(1)
int longestKSubstr(string &s, int k) {
    
    int maxLen = -1, n=s.length();
    
    for(int i=0; i<n; i++){
        
        unordered_map<char,int>ump;
        
        for(int j=i; j<n; j++){
            
            ump[s[j]]++;
            
            if(ump.size() == k)
                maxLen = max(maxLen, j-i+1);
            
            
            if(ump.size() > k) break;
        }
        
    }
    
    return maxLen;
}