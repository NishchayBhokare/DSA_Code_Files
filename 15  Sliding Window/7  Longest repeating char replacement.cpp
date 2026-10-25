//GFG.
//Longest repeating character replacement.

//Approach 1: Most optimised Approach TC-O(N) SC-O(3).
//Most IMP: If you understand current window length - maximum number of character frquency in that window
//this substracted value will be the number of characters required to change to make subarray valid. 
//and if required characters are greatre than k, then just shrink the window and check in next window.



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
        
        if((currLen - maxFreq) > k){ //if we substract maxFreq of character present in window from current lenght of window
            //we will get number characters required to replace, and if that is graeter than k, then window is not valild
            //so shrink it.
            //Also, we don't need to do while loop because always we want answer gerater than current max len.
            
            charFreq[s[leftInd]]--;
            
            if(charFreq[s[leftInd]] == 0) //This is optional, you can do it, or let it be
                charFreq.erase(s[leftInd]);
            
            // maxFreq = getMaxFreq(charFreq); //if you observe..we do not need to minimise maxfrequency value. because
//to get substring valid in future we want..future maxFreq greater than current maxFreq. 
//because, we're looking for maximum substring length, and to get new max sub length, new window must have greater
// than current maxFreq value.
    
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