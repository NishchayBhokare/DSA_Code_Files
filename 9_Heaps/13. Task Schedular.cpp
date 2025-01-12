//GFG.

int leastInterval(int N, int K, vector<char> &tasks) {
    
    unordered_map<char,int>charFreq; //character to frequency mapping eg. A->4, B->2, C->5, A occurs four times
    //B occurs 2 times etc.
    
    int maxFreq=0; //we're finding, maximum occurences or frequency of any character.
    for(auto i:tasks){
        charFreq[i]++;
        
        maxFreq = max(maxFreq,charFreq[i]); //storing maximum frequency of character.
    }
    
    int maxFreqCharCnt=0; //how many characters are there..who have max frequency same to maxFreq.
    for(auto i:charFreq){
        if(i.second == maxFreq) //if characters having frequency as maxFreq then incrmenet character count for that frquency.
            maxFreqCharCnt++;
    }    
    
    int noOfGaps = maxFreq-1; //A_ _A_ _A_ _A so here three gaps are present. 4 A and 3 gaps.
    
    int gapLen = K+1-maxFreqCharCnt; //if maxFreqCharcnt is 2 and maxFreq is 4 eg. AAAABBBB then 
    //for second array will look like AB_AB_AB_AB so, here there is only one character gap len is present in every gap box.
    //so 1 gap is nothing but 2+1-2 i.e 2. 
    
    int availableSlots = noOfGaps * gapLen; //calculating total avaialble slots.
    
    int availableTaks = N - (maxFreq * maxFreqCharCnt); //avaialble tasks will be, first if we substract it from string length and then, 
    // if we multipy these maxFreq and its number of characters who has maxFreq same. then we will get number of avaialble taks.
    
    int idleTime = max(0, availableSlots-availableTaks); //here is the catch. if avaiableslots is smaller than remaning tasks that means.
    //this substraction will goes in -ve. so take max(0, substraction) so that if substraction goes in -ve we will consider idle time as 0.
    //why we're considertin 0, lets check, if array having characters, AAABBBDDEEFF, for this example
    // A having 3 times, B having 3 times, D2, E2, F2. so here avaialble slot will be NoofGaps * gaplen
    //i.e Noofgap = 3-1=2 and gapLen=K+1-maxFreqCharCnt=2+1-2=1. so avaialble tasks will be 2*1=2.
    //now avaialble tasks is 12-(3*2)=6.
    
    //now if we take  availableSlots-availableTaks = 2-6 = -4 then it will goes down in -ve and we will get idle time as 0.
    //because even if there are many elemnts twice..still we can accomate these characters without extra idle time.
    //eg. AAABBBDDEEFF and answer will be-> A D B A E B A E B D E F so here there is no idle time.
    //if avaialbles slots having more and avaialble tasks are lesser then we will get +ve idle time.
    
    int totalTime = N+idleTime; //calculate totlaIdle time N+idle time.
    
    return totalTime;
}