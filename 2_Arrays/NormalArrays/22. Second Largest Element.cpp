//GFG-Find second largest element.
//Approach 1: Most optimised Approach. TC-O(N) SC-O(1)
int getSecondLargest(vector<int> &arr) {
    
    int first = -1, second = -1; //using two variables.
    
    for(auto i:arr){
        
        if(i > first){ //if i element is greater than first.
            second = first; //then update second to first
            first = i; //and first to current element
        }
        
        else if(i > second && i < first) //also check..if i element is greater than second or not.
        //and strictly less than first or not. because we don't want to have equal element with first max.
            second = i; //if condition satiesfies. then update second.
    }
    
    return second;
}