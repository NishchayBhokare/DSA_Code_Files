//GFG. 
//check if array is sorted or not.

//Approach 1: TC-O(N) SC-O(1)
bool arraySortedOrNot(vector<int>& arr) {

    int n=arr.size();
    
    for(int i=0; i<n-1; i++){
        
        if(arr[i] > arr[i+1]) //just check..current element is greater than next or not...if yes..then array is not
        //sorted
        return false;
    }
    
    return true;
}