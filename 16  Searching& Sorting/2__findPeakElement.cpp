//Leetcode
//Example for find the peak element.
//peak element is a element whose left and right neighbour is smaller than it.


// Approach 1: Using binary search. Tc-O(logn) SC-O(1).
int findPeakElement(vector<int>& nums) {
    int n=nums.size();

    if(n==1 || nums[0] > nums[1]) return 0; //if size is 1 or first number is peak. then return 0.
    if(nums[n-1] > nums[n-2]) return n-1; //if last element is peak return it's index.

    int low=1, high=n-2, mid=0; //start from index 1 and high from n-2.

    while(low <= high){
        
        mid=low+(high-low)/2;

        //if current element is greater than previous element and next element then its peak element.
        if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1])
            break;

        if(nums[mid] < nums[mid+1]){ //mid is in increasing curve. so surely pick will be in right part.
            low = mid+1;
        }
        else //mid is in decreasing curve. then surely pick will be in left part.
            high=mid-1;
    }
    

    return mid;
}


//Approach 2: Using linear solution. TC-O(N) SC-O(1)
int findPeakElement(vector<int>& nums) {
        int n=nums.size();

        if(n==1) return 0;

        if(nums[0] > nums[1]) return 0;
        if(nums[n-1] > nums[n-2]) return n-1;

        for(int i=1; i<n-1; i++){
            if(nums[i] > nums[i-1] && nums[i] > nums[i+1]) //once this condition satisfied. then return from here only.
                return i;
        }
        return -1; //this condition will never satisfied. because at least one element will be peak in array.
    }


  
