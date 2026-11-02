


//Approach: Optimised Approach TC-O(N+R) SC-O(N)
// For the subset to have MEX i:

// Every value 0, 1, ..., i - 1 must occur at least once.
// Value i must not occur.
// Every value greater than i can either be selected or not selected.
// If mp[x] is the frequency of value x, then:

// For every value (j < i), there are (2 ^ mp[j] - 1) ways to select its occurrences, because at least one must be selected.
// For value i, there is exactly one way to select none of its occurrences.
// For all values greater than i, there are [2 ^ (n - seen - mp[i])] ways to choose their occurrences, where seen is the number of array elements with values smaller than i.
// Therefore, the number of subsets with MEX exactly i is

// (2^freq[0] - 1) * (2^freq[1] - 1) * ... * (2^freq[i - 1] - 1) * 2^(number of elements whose value is greater than i)
// We need to sum this quantity for every MEX i in the range [l, r]. We can maintain the product incrementally as i increases, avoiding the need to recalculate it from scratch for every MEX.

#define mod 1000000007
class Solution {
  public:
    int cntSubsets(vector<int> &arr, int l, int r) {
        // code here
        int n = arr.size();
        vector<long long>freq(n+1,0);
        vector<long long>power2(n+1,1);

        for(auto x:arr) freq[x]++;

        for(int i=1; i<=n; i++) power2[i] = (power2[i-1] * 2)%mod;

        long long ans = 0, seenElem=0, minWays=1;

        for(int i=0; i<=r; i++){

            seenElem += freq[i];

            if(i >= l and i <= r){

                ans = (ans+(minWays * power2[n-seenElem])%mod)%mod;
                //ans = ans+Min ways to get at least one len digit from left * power of remaining elements in right.
            }

            minWays = minWays * (power2[freq[i]] - 1 + mod)%mod; 
            //calculating minways to take current number's freq combinations, it will help to 
            //calculate answer for value lies between l to r as we want for every l to r, how many minways possible
            //from left side till current index.
        }

        return ans;
    }
};