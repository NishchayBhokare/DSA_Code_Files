
//Approach 1: optimised approach TC-O(N) SC-O(1)
class Solution {
  public:
    bool findPattern(string& s) {

        int n = s.length(), i=0, cnt = 0;
        
        if (n % 2 == 1) return false; //to get string valid, it must of even size.
        
        while(i<n){
            
            while(i<n and s[i]=='x'){
                cnt++;
                i++;
            }
            
            while(i<n and s[i]=='y'){
                cnt--;
                i++;
            }
            
            if(cnt !=0 ) return false;
        }
        
        if(cnt==0) return true;
        
        return false;
    }
};

//Approach 2: almost similar. TC-O(N) SC-O(1)
class Solution {
  public:
    bool findPattern(string& s) {

        int cnt = 0;
        char last;
        for(auto ch:s){
            
            if(ch == 'x' and last == 'y' and cnt!=0) return false;
            
            if(ch == 'x')
                cnt++;
            else
                cnt--;
            
            last = ch;
        }
        
        if(cnt==0) return true;
        
        return false;
    }
};