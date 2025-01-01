//Leetcode -> Max Consecutive Ones.
int findMaxConsecutiveOnes(vector<int>& nums) {
    int maxLen = 0, len=0;

    for(auto i: nums){

        if(i==1)
            len++;
        else{
            maxLen = max(maxLen, len);
            len=0;
        }
    }

    //also checking for last len.
    maxLen = max(maxLen,len);
    return maxLen;
}