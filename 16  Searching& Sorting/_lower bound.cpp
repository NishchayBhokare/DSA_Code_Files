//GFG

//Appraoch 1: Using binary search. TC-O(logn) SC-O(1)
int lowerBound(vector<int>& arr, int target) {
    // code here
    
    int low=0, high=arr.size()-1, ans=arr.size();
    
    while(low<=high){
        int mid = low+(high-low)/2;
        
        if(target <= arr[mid]){ // if we get greater answer then store it for now and look for smaller answer.
            ans=mid;
            high=mid-1;
        }
        else if(target > arr[mid])
            low = mid+1;
    }
    
    return ans;
}


//Approach 2: Using lower bound built in method.
int lowerBound(vector<int>& arr, int target) {

    int ind = upper_bound(arr.begin(), arr.end(), target) - arr.begin(); // to get index.

    // int num = *upper_bound(arr.begin(), arr.end(), target) // to get value inside that iterator.
    
    return ind;
}