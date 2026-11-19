//Approach 1: Optimised approach TC-O(N) SC-O(1)
class Solution {
  public:
    int smallestSubWithSum(vector<int>& arr, int x) {
        
        int n=arr.size(),l=0, r=0, sum=0, len=INT_MAX;
        
        while(r<n){
            
            sum+=arr[r];
            
            while(sum>x){
                len = min(len, r-l+1);
                sum-=arr[l++];
            }
            
            r++;
        }
        
        return (len==INT_MAX? 0 : len);
    }
};