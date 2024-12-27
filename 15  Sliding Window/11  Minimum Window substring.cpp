//Leetcode.
//Varaition of this question is there on GFG. which i not understood. so need to work on it near future.

//Approach 1: using optimised Approach. TC-O(N) SC-O(N)
//here we have to understand one thing. we are creating map of s2 length with frequency of every characters.

//now taking left and right pointer. first checking is current character has positive frequency in map or not.
//if yes then these one of the character of substring which we want to find. so increment match cnt.
//also on every time..whatever character we're on. we have to decrement their frequency in map. if it's first time character then map will create it and it's frequency will be -1.

//now check if matchCnt equals to m then surely we have found substring s2 in s1.
//now we want to shrink left so that we will get minimal length as possible.
//if during shrinking by chance if curent character frequency is greater than 0 that means. we have encounter substring character.
//so we should decrement matchcount. because now one character need to match.

//at the end return minlen.
//TC-O(N) SC-O(N)
string minWindow(string s1, string s2) {
    int n=s1.length(), m=s2.length(), minLen=INT_MAX, startInd=-1;
    
    unordered_map<char,int>charFreq;

    for(auto &ch:s2) charFreq[ch]++;

    int left=0, right=0, matchCnt=0;

    while(right < n){

        if(charFreq[s1[right]] > 0)
            matchCnt++;
        
        charFreq[s1[right]]--;

        while(matchCnt == m){
            
            if((right-left+1) < minLen){
                minLen = right-left+1;
                startInd = left;
            }

            //now we have to shrink so that we can get minimal answer.
            charFreq[s1[left]]++;

            if(charFreq[s1[left]] > 0)
                matchCnt--;
            
            left++;
        }

        right++;
    }
    
    if(startInd == -1) return "";
    return s1.substr(startInd,minLen); //(startingindex, no. of lenght of substring)
}



//Approach 2: brute force approach TC-O(N2) SC-O(1)
string minWindow(string s1, string s2) {
    int n=s1.length(), m=s2.length(), minLen=INT_MAX, startInd=-1;
    
    for(int i=0; i<n; i++){
        
        int len=0;
        unordered_map<char,int>charFreq;
        
        for(auto &ch:s2) charFreq[ch]++;
        
        for(int j=i; j<n; j++){
            
            if(charFreq[s1[j]] > 0) len++;
            
            charFreq[s1[j]]--;
            
            if(len == m && (j-i+1) < minLen){
                startInd = i;
                minLen = j-i+1;
                break;
            }
        }
    }
    
    if(startInd == -1) return "";
    return s1.substr(startInd,minLen); //(startingindex, no. of lenght of substring)
}

   