

//Approach 1: TC-O(logn) SC-O(1)
class Solution {
  public:
    int upperBound(vector<int>& arr, int target) {
        // code here
          
    int low=0, high=arr.size()-1, ans=arr.size();
    
    while(low<=high){
        int mid = low+(high-low)/2;
        
        if(target < arr[mid]){ //here only small change, remove equal to sign and look for 
            // greater element if it's equal to target. so go to else part.
            ans=mid;
            high=mid-1;
        }
        else
            low = mid+1;
    }
    
    return ans;
    }
};



//Approach 2: using uppar bound built in method. TC-O(logn) SC-O(1)
class Solution {
  public:
    int upperBound(vector<int>& arr, int target) {
        // code here
        int ind = upper_bound(arr.begin(), arr.end(), target) - arr.begin();
        
        return ind;
    }
};
