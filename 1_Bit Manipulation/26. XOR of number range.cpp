//GFG.

//Approach 1: Optimised Approach TC-O(1) SC-O(1)
//if you note down xor from 1 to 10, you will see there is repeating pattern after every 4 xor values.
//that pattern will tell you all story.
class Solution {
  public:
    int solve(int n){
        
        if(n%4 == 0) return n;
        
        if(n%4 == 1) return 1;
        
        if(n%4 == 3) return 0;
        
        if(n%4 == 2) return n+1;
    }
  
    int findXOR(int l, int r) {
        
        return solve(l-1) ^ solve(r);
        //to calculate xor from l to r.
        //first calculate, 0 to l-1 and take xor with 0 to r.
        //so from both xor 0 to l-1 will get cancel out and then we will get final answer l to r xor.
    }
};


//Approach 2: Brute force. TC-O(n) SC-O(1)
class Solution {
  public:
    int findXOR(int l, int r) {
        
        int ans = 0;
        
        for(int i=l; i<=r; i++){
            ans ^=i;
        }
        
        return ans;
    }
};