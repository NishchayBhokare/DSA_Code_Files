//gfg
//Key observation:
    // I was unable to get optimized solution using unrodered set. I didn't come up with below observation.

    // - Think about using an unordered_set.
    // "Which numbers should I start counting a consecutive sequence from?"

    // - You should not start counting from every number. Instead, only start counting from a number if it is the first number of a sequence.

    // - How can you determine that?
    // Check whether: num - 1, exists in the unordered_set.

    // If num - 1 exists, then num is in the middle of a sequence → don't start from it.
    // If num - 1 does not exist, then num is the start of a sequence → now keep checking num + 1, num + 2, ...

    // That's the key observation that makes the algorithm optimal.

//Approach 1: TC-O(N+N) i.e O(N) SC-O(N)
//Most optimised approach using unordered set.
class Solution {
  public:
    int longestConsecutive(vector<int>& arr) {
        unordered_set<int>ust;
        
        for(auto i:arr) ust.insert(i);
        
        int maxLen = 1;

        for(auto i:arr){
            
            if(ust.find(i-1) == ust.end()){ //check if number if first element of sequence or it's in mid of seq.
                int firstNum = i; //if it's first then add in firstNum var.
                int len=1;
                
                while(ust.find(firstNum+1) != ust.end()){ //now look for next set of sequence.
                    len++;
                    maxLen = max(maxLen, len);
                    
                    firstNum+=1;
                }
            }
        }
        
        
        return maxLen;
    }
};


//Approach 2: Sorting technique. TC-O(NLogn) SC-O(1)
class Solution {
  public:
    int longestConsecutive(vector<int>& arr) {
        // code here
        sort(arr.begin(), arr.end());
        
        int maxLen = 1, len=1;
        
        for(int i=1; i<arr.size(); i++){
            
            if(arr[i] == arr[i-1]) continue;
            
            if(arr[i] == (arr[i-1] + 1)){
                len++;
                maxLen = max(maxLen,len);
            }
            else
                len = 1;
        }
        
        return maxLen;
    }
};

//Approach 3: Brute Force approach. TC-O(N2) SC-O(1)
class Solution {
private:
    // Helper function to perform linear search
    bool linearSearch(vector<int>& a, int num) {
        int n = a.size(); 
        // Traverse through the array 
        for (int i = 0; i < n; i++) {
            if (a[i] == num)
                return true;
        }
        return false;
    }

    int longestConsecutive(vector<int>& nums) {
        // If the array is empty
        if (nums.size() == 0) {
            return 0;
        }
        int n = nums.size();
        // Initialize the longest sequence length
        int longest = 1; 

        // Iterate through each element in the array
        for (int i = 0; i < n; i++) {
            // Current element
            int x = nums[i]; 
            // Count of the current sequence
            int cnt = 1; 

            // Search for consecutive numbers
            while (linearSearch(nums, x + 1) == true) {
                // Move to the next number in the sequence
                x += 1; 
                // Increment the count of the sequence
                cnt += 1; 
            }

            // Update the longest sequence length found so far
            longest = max(longest, cnt);
        }
        return longest;
    }

};

//Approach 4: TC-O(N+MaxNum) SC-O(MaxNum)
class Solution {
  public:
    int longestConsecutive(vector<int>& arr) {
        int maxNum = *max_element(arr.begin(), arr.end());
        
        vector<int>ans(maxNum+1,0);
        
        for(auto i:arr){
            ans[i]=1;
        }
        
        
        int maxLen=0, len=0;
        
        for(int i=0; i<ans.size(); i++){
            
            if(ans[i] == 1){
                len++;
                maxLen = max(maxLen, len);
            }
            else
                len=0;     
        }
        
        return maxLen;
    }
};
    