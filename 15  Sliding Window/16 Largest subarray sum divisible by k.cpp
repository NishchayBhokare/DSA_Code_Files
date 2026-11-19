//Approach 1: Optimised approach. TC-O(N) SC-O(min(N,k))

class Solution {
public:
    int longestSubarrayDivK(vector<int>& arr, int k) {

        unordered_map<int, int> mp;

        int prefixSum = 0;
        int ans = 0;

        // Prefix sum 0 exists before the array starts.
        mp[0] = -1;

        for (int i = 0; i < arr.size(); i++) {

            prefixSum += arr[i];

            // Handle negative modulo.
            int rem = ((prefixSum % k) + k) % k;

            if (mp.find(rem) != mp.end()) {

                // Same remainder means sum is divisible by k.
                ans = max(ans, i - mp[rem]);

            } else {

                // Store only the first occurrence.
                mp[rem] = i;
            }
        }

        return ans;
    }
};
//dry run
arr = [2, 7, 6, 1, 4, 5]
k = 3


Index	Element	Prefixsum	Remainder	Longest length
-1	       —	   0	        0	            0
0	       2	   2	        2	            0
1	       7	   9	        0	            2
2	       6	   15        	0            	3
3	       1	   16        	1            	0
4	       4	   20        	2            	4
5	       5	   25        	1            	4


Final answer: 4

The longest subarray is [7, 6, 1, 4], whose sum is 18.


//Approach 2: Naive approach.
//TC-O(N2) SC-O(1)
class Solution {
  public:
    int longestSubarrayDivK(vector<int>& arr, int k) {
        // code here
        
        int maxLen=0; 
        
        for(int i=0; i<arr.size(); i++){
            int sum = 0;
            
            for(int j=i; j<arr.size(); j++){
                
                sum+= arr[j];
                
                if(sum%k == 0) maxLen = max(maxLen, j-i+1);
            }
        }
        
        
        return maxLen;
    }
};