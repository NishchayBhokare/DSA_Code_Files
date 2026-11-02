
//Question simply boils down to calculate sum of maxium subarray of length totalTime.
// The idea is to reuse the sum from the previous subarray instead of calculating it again.

// Calculate the sum of the first k locations.
// Slide the window by removing arr[i - k] and adding arr[i].
// Update the maximum sum after each shift.
// Return the maximum sum.
// Consider an example, arr = [2, 1, 3, 5, 0, 1, 4] and totalTime = 3.

// Initially, k = 3 and the first window is [2, 1, 3].
// Its sum is 6, so maxSum = 6.
// Slide the window: remove 2, add 5 -> [1, 3, 5], sum = 9.
// Update maxSum = 9.
// Slide the window: remove 1, add 0 -> [3, 5, 0], sum = 8.
// Slide the window: remove 3, add 1 -> [5, 0, 1], sum = 6.
// Slide the window: remove 5, add 4 -> [0, 1, 4], sum = 5.
// The maximum sum is 9.

//TC-O(N) SC-O(1)
class Solution {
  public:
    int maxPackages(vector<int>& arr, int totalTime) {
        // code here
        
        int n=arr.size(),totalPack = 0;
        
        for(int i=0; i<min(n,totalTime); i++){ 
            totalPack+=arr[i];
        }
        
        int currPack=totalPack;
        
        for(int ind=totalTime; ind<n; ind++){
            
            currPack -= arr[ind-totalTime];
            currPack += arr[ind];
            
            totalPack = max(currPack, totalPack);
        }
        
        return totalPack;
    }
};


//Approach 2: Naive approach TC-O(N*totalTime) SC-O(1)
// The idea is to consider every possible starting location and calculate the packages delivered by visiting the next totalTime locations.

// Start from each possible location i.
// Calculate the sum of the next totalTime elements.
// Update the maximum package count in a variable sum.
// Return the maximum sum found.

int maxPackages(vector<int> &arr, int totalTime)
{
    int n = arr.size();
    int k = min(totalTime, n);
    int ans = 0;

    // Try every possible starting location.
    for (int i = 0; i + k <= n; i++)
    {
        int sum = 0;

        // Calculate packages delivered in this window.
        for (int j = i; j < i + k; j++)
        {
            sum += arr[j];
        }

        ans = max(ans, sum);
    }

    return ans;
}
