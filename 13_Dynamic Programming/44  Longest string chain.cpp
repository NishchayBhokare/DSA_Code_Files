//GFG.

//Approach 1: N2*L(length of string is L)..similar approach like LIS. just shuttle changes.
//checkispossible function get's introduce which checks..jth string can be converted to ith or not. 
bool cmp(string &s1, string &s2){
    return s1.length() < s2.length();
}

class Solution {
  public:
    int checkIsPossible(string &s1, string &s2){
        
        int n=s1.length(), m=s2.length(); //s1 is greater than s2 in length.
        if(n != m+1) return 0; //if m+1 is not get's equals to n that menas..its' not possible.
        int i=0, j=0;
        while(i<n){ //looop till i<n index of s1.
            
            if(j<m && s1[i]==s2[j]){
                i++;
                j++;
            }
            else
                i++;
        }
        
        if(i==n && j==m) return 1; //at the end..only check..if both are at the end of string or not.
        //because..if at the end..they both are not on the end of array then return 0. no match.
        return 0;
    }

    int longestChain(int n, vector<string>& words) {
        
        sort(words.begin(), words.end(), cmp); //sorting the array based on lenght of strings. in ascending order.
        
        vector<int>cntArr(n,1);
        int ans = 1;
        for(int i=1; i<n; i++){
            
            for(int j=0; j<i; j++){
                
                if(checkIsPossible(words[i], words[j]) && cntArr[j]+1 > cntArr[i]){
                    
                    cntArr[i] = cntArr[j]+1;
                }
            }
            ans = max(ans,cntArr[i]);
        }
        
        return ans;
    }
};