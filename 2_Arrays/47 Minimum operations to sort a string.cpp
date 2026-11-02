

//Approach: prepare conditions and observe the pattern.
class Solution {
public:
    int minOperations(string s) {
        
        int n = s.length();
        
        char mini='z', maxi='a';

        for(int i=0; i<s.length(); i++){

            mini = min(mini,s[i]);
            maxi = max(maxi,s[i]);
        }

        //if sorted return 0.
        if(ranges::is_sorted(s)) return 0;

        if(n==2) return -1;

        if(mini==s[0] or maxi==s[n-1]) return 1; //if any of them which is minimum or maximum present at their right position
        //return 1.

        for(int i=1; i<n-1; i++){ //check whether any of them, present in middle of the array, if yes return 2.
            if(s[i] == mini or s[i] == maxi) return 2;
        }

        // if(s[0]==maxi and s[n-1]==mini) //not required, but written for your better understanding.
            return 3;
    }
};