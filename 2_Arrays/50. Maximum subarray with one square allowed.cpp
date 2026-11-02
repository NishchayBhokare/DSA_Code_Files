
//Approach 1: Optimised approach TC-O(N) SC-O(1)
//maintaining two states.
// The idea is to maintain two maximum subarray sums: one without squaring any element and 
// another after squaring exactly one element.
class Solution {
  public:
    int maximumSubarray(vector<int>& arr) {
        // code here
        
        int noSquare=0, square=0, ans=0;
        
        for(int i=0; i<arr.size(); i++){
            
            int curr = arr[i], currProd = arr[i] * arr[i];
            
            int newNoSquare = max(curr, noSquare+curr); //max(start from current, add curr in prevNoSqr sum)
            int newSquare = max({currProd, square+curr, noSquare+currProd});
            //max(start from current prod, add curr in prev sqr sum, add current prod in noSquare )
            
            noSquare = newNoSquare;
            square = newSquare;
            
            ans = max({noSquare,square,ans});
        }
        
        return ans;
    }
};  


//Approach 2: The idea is to consider each element as the squared element and combine 
// the best subarray sum on its left and right.

class Solution {
  public:
    int maximumSubarray(vector<int>& arr) {
        // code here
        
        int n = arr.size();
        vector<int>leftSum(n,0);
        vector<int>rightSum(n,0);
        
        int sum=0;
        for(int i=1; i<n; i++){
            sum+=arr[i-1];
            
            if(sum < 0) sum=0;
            
            leftSum[i]=sum;
        }
        
        sum=0;
        for(int i=n-2; i>=0; i--){
            sum+=arr[i+1];
            
            if(sum<0) sum=0;
            
            rightSum[i]=sum;
        }
        
        
        int maxSum=0;
        for(int i=0; i<n; i++){
            maxSum = max(maxSum, arr[i]*arr[i] + leftSum[i] + rightSum[i]);
        }
        
        return maxSum;
    }
};  




//Approach 3: Try all subarrays. TC-O(N4) SC-O(1

int maximumSubarray(vector<int> &arr)
{
    int n = arr.size();
    int res = INT_MIN;

    // Consider every possible starting index.
    for (int i = 0; i < n; i++)
    {

        // Consider every possible ending index.
        for (int j = i; j < n; j++)
        {

            // Try squaring every element of the subarray.
            for (int k = i; k <= j; k++)
            {
                int sum = 0;

                // Calculate the sum after squaring arr[k].
                for (int x = i; x <= j; x++)
                {
                    if (x == k)
                        sum += arr[x] * arr[x];
                    else
                        sum += arr[x];
                }

                // Update the maximum sum.
                res = max(res, sum);
            }
        }
    }

    return res;
}
) 