
//Approach 1: Optimised approach. TC-O(logn) SC-O(1).
class Solution {
  public:
    int minTime(int n, int s1, int s2) {
        // code here
         
        int low=0, high = n*min(s1,s2);
        
        int ans = 0;
        while(low<=high){
            
            int midTime = low+(high-low)/2;
            int doc = n;
            doc = doc - (midTime/s1);
            doc = doc - (midTime/s2);
            
            if(doc<=0) {
                ans = midTime;
                high = midTime-1;
            }
            else low = midTime+1;
        }
        
        return ans;
    }
};


//Appraoch 2: Brute force approach. Check for every time from 1 to n.
//TC - O(N) SC-O(1)
class Solution {
  public:
  //n=1,s1=1.
    int minTime(int n, int s1, int s2) {
        // code here
        
        int t=1;
        while(n>0){
            
            if(t%s1 == 0) n--;
            if(t%s2 == 0) n--;
            t++;
        }
        
        return t-1;
    }
};