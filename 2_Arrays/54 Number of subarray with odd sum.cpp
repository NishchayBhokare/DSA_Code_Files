//Approach 1: Optimised approach. TC-O(N) SC-O(1)
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        
        int evenCnt = 1, oddCnt = 0, sum=0, ans=0, mod = 1e9+7;

        for(int i=0; i<arr.size(); i++){
            sum+=arr[i]; 

            if(sum%2==0){ //odd + even = odd.
                ans= (ans+oddCnt)%mod;
                evenCnt++;
            }
            else{ //even + odd = odd
                ans= (ans+evenCnt)%mod;
                oddCnt++;
            }
        }

        return ans;
    }
};