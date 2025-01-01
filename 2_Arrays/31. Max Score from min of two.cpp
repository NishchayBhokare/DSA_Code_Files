//GFG
// Maximum Score from Subarray Minimums
//Approach: TC-O(N) SC-O(1)
//I have spend lot much time. after that. i understood...we have to find maximum pair of adjacent values.
int pairWithMaxSum(vector<int> &arr) {
    
    int n=arr.size(),maxSum=0, sum=0;
    
    for(int i=1; i<n; i++){
        sum=arr[i-1] + arr[i]; //taking sum for current element and previous element. for every index from 1 to n.
        
        maxSum=max(sum,maxSum); //take max sum.
    }
    
    return maxSum;
}