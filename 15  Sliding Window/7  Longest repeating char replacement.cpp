//GFG.
//Longest repeating character replacement.

//Approach 1: Most optimised Approach TC-O(N) SC-O(3).
//Everything is similar like previous questions. only catch is.
//to check whether replacement can happen withing k changes or not. for this we have one formula

//maxFrequency of any character in map - current length of substring. if it's greater than k.
//then current substring is not valid. so shrink left by 1.
int characterReplacement(string& s, int k) {

    int len=s.length(), maxSubStrLen = 0, maxFreq=0;
    
    unordered_map<char,int>charFreq;
    
    int leftInd = 0, rightInd = 0;
    
    while(rightInd < len){

        charFreq[s[rightInd]]++;
        
        maxFreq = max(maxFreq, charFreq[s[rightInd]]);
        
        int currLen = rightInd-leftInd+1;
        
        if((currLen - maxFreq) > k){ //we don't need to do while loop because always we want answer gerater than current max len.
            
            charFreq[s[leftInd]]--;
            
            if(charFreq[s[leftInd]] == 0)
                charFreq.erase(s[leftInd]);
            
            // maxFreq = getMaxFreq(charFreq); //if you observe..we do not need to minimise maxfrequency value. because
//to get substring valid in future we want..maxfreq greater than current freq. because on every iteration lenght of substring is increasing.
    
            leftInd++;
        }
        
        maxSubStrLen = max(maxSubStrLen, rightInd-leftInd+1);
        
        rightInd++;
    }
    
    return maxSubStrLen;
}



//Approach 2: TC-O(2N * 3) SC-O(3)
int getMaxFreq(unordered_map<char,int>&charFreq){
    int maxFreq = 0;
    
    for(auto &charFreqPair:charFreq){
        maxFreq = max(maxFreq, charFreqPair.second);
    }
    return maxFreq;
}

int characterReplacement(string& s, int k) {

    int len=s.length(), maxSubStrLen = 0, maxFreq=0;
    
    unordered_map<char,int>charFreq;
    
    int leftInd = 0, rightInd = 0;
    
    while(rightInd < len){

        charFreq[s[rightInd]]++;
        
        maxFreq = max(maxFreq, charFreq[s[rightInd]]);
        
        int currLen = rightInd-leftInd+1;
        
        while((currLen - maxFreq) > k){
            
            charFreq[s[leftInd]]--;
            
            if(charFreq[s[leftInd]] == 0)
                charFreq.erase(s[leftInd]);
            
            maxFreq = getMaxFreq(charFreq); //calculating updated maximum frequency.
            leftInd++;
            
            currLen = rightInd-leftInd+1;
        }
        
        maxSubStrLen = max(maxSubStrLen, rightInd-leftInd+1);
        
        rightInd++;
    }
    
    return maxSubStrLen;
}


//Approach 3: TC-O(N2) SC-O(1).
//two approaches.

//We are checking for every forming of substring how many characters need to change. if it's greater than k then just 
//break or update max len.
int characterReplacement(string& s, int k) {

    int len=s.length(), maxSubStrCnt = 0, replaceCnt = 0;
    
    for(int i=0; i<len; i++){
        
        char ch = s[i];
        replaceCnt = 0;
        
        for(int j=i; j<len; j++){
            
            if(ch != s[j])
                replaceCnt++;
            
            if(replaceCnt > k) 
                break;
            
            int currSubStrLen = j-i+1;
            
            maxSubStrCnt = max(maxSubStrCnt, currSubStrLen);
        }
    }
    
    return maxSubStrCnt;
}

//below approach follow first two approaches optimization logic.
int characterReplacement(string& s, int k) {

    int len=s.length(), maxSubStrLen = 0;
    
    for(int i=0; i<len; i++){
        
        unordered_map<char,int>charFreq;
        int maxFreq=0;
        
        for(int j=i; j<len; j++){
            
            charFreq[s[j]]++;
            
            maxFreq = max(maxFreq, charFreq[s[j]]);
            
            int currLen = j-i+1;
            
            int replaceCnt = currLen - maxFreq;
            
            if(replaceCnt <= k)
                maxSubStrLen = max(maxSubStrLen, currLen);
            
            else break;
        }
    }
    
    return maxSubStrLen;
}