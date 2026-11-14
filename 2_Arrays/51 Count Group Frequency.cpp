

//Approach 1: Optimised Approach. TC-O(N) SC-O(26).
class Solution {
  public:
    int getCount(string &s, int k) {
        // code here
        unordered_map<char,int>charFreq;
        
        for(int i=0; i<s.length(); i++){
            
            if(i!=0 and s[i] == s[i-1]) continue;
            
            charFreq[s[i]]++;
        }
        
        int ans=0;
        for(auto pr:charFreq){
            if(pr.second == k) ans++;
        }
        
        return ans;
    }
};

//Approach 2: Brute force approach.
// For each distinct character, traverse the string and count the groups it forms. A group starts when 
// the character matches the selected character.