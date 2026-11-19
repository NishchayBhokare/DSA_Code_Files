
//Approach 1: TC-O(N) SC-O(1)
class Solution {
  public:
    int minFlips(string &s) {
        
        int cnt1=0, cnt2=0;
        
        //there ar eonly two patterns possible
        //010101
        //101010
        for(int i=0; i<s.length(); i++){
            
            //checking for first pattern
            if(s[i] != (i%2==0? '0' : '1')) cnt1++;
            
            // checking for second.
            if(s[i] != (i%2==0? '1' : '0')) cnt2++;
        }
  
        return min(cnt1,cnt2);
    }
};