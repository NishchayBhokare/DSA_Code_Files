class Solution {
  public:

  
    int subsequenceSum(string &s) {

        int sum=0, mod = 1e9+7;
        for(int i=0; i<s.length(); i++){ //first calculate sum.
            
            int num = s[i] - '0' + 0;
            sum+=num;
        }
        
        int val = 2;
        for(int i=1; i<s.length(); i++){ //then take sum * pow(2^n-1). we cannot take this directly,
            // becaus of integer overflow, so looping over the array.
            sum = (sum * val)%mod;
        }
        
        return sum;
    }
};