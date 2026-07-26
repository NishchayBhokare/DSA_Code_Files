//Leetcode.

//Approach 1:Optimised approach
// Time Complexity: O(N*logN) + O(N), we sort the entire array and then merge them in a single pass.
// Space Complexity: ON), additonal space used to store the non-overlapping intervals.

class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {

        sort(arr.begin(), arr.end());
        
        vector<vector<int>> ans;
        
        int start = arr[0][0];
        int end = arr[0][1];

        
        for(int i=1; i<arr.size(); i++){
            
            int s = arr[i][0];
            int e = arr[i][1];
            
            if(s <= end){
                end = max(end, e);
            }
            else{
                
                ans.push_back({start, end});
                start = s;
                end = e;
            }
        }
        
        ans.push_back({start,end});
        
        return ans;
    }
};



//Approach 2: Brute force. checking for every interval. 
// Time Complexity: O(N^2), for every interval we check all future intervals.
// Space Complexity: O(N), additonal space used to store the non-overlapping intervals.

class Solution {
public:
    // Function to merge overlapping intervals using brute force
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        // Sort intervals based on start time
        sort(intervals.begin(), intervals.end());

        // Result array to store merged intervals
        vector<vector<int>> ans;

        // Loop through each interval
        int n = intervals.size();
        for (int i = 0; i < n; ) {

            // Start of current merged interval
            int start = intervals[i][0];
            int end = intervals[i][1];

            // Merge with all overlapping intervals
            int j = i + 1;
            while (j < n && intervals[j][0] <= end) {
                // Update end to the maximum of current end and overlapping interval's end
                end = max(end, intervals[j][1]);
                j++;
            }

            // Add the merged interval to result
            ans.push_back({start, end});

            // Move to the next non-overlapping interval
            i = j;
        }

        return ans;
    }
};
