//Leetcode.

//TC-O(N) SC-O(1)
//Consider dividing group into 2 size substring. This will always give minimum count.

// key observation: any even-length sequence can be split into pairs of two characters. This is the 
// smallest valid even sequence we can have. If we can organize the entire string into pairs where 
// both characters are the same — either both '0's or both '1's — we'll end up with a beautiful 
// string.
class Solution {
public:
    int minChanges(string s) {
        
        int cnt = 0;

        for(int i=0; i<s.length(); i+=2){

            if(s[i] != s[i+1]) cnt++;
        }

        return cnt;
    }
};