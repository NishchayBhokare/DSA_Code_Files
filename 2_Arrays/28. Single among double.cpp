//GFG.
//find element who occurs one time.
//Approach 1: Most optimised Approach Using binary search. TC-O(logn) SC-O(1)
int search(int n, int arr[]) {

    int low=0,high=n-1, mid;
    
    while(low <= high){
        
        int mid = low + (high-low)/2;
        
        if(mid>0 && mid<n-1 && (arr[mid]==arr[mid-1] || arr[mid]==arr[mid+1])){ //this condition is true
        //when element is double.
            
            if(mid%2 == 0){ //for even number..normally similar elemet should present to next of it's index.
                
                if(arr[mid] != arr[mid+1]) //if next is not same..then there is gadbad in left part.
                    high=mid-1; //so go left part.
                else
                    low=mid+1; //else right part.
            }
            else{
                //for odd same element should present at previous index.
                if(arr[mid] != arr[mid-1])
                    high=mid-1;
                else
                    low=mid+1;
            }
        } 
        else //else element is not double. then return mid value.
            return arr[mid];
    }

}


//Approach 2: TC-O(N) SC-O(1)
int search(int n, int arr[]) {
    int num=0;

    for(int i=0; i<n; i++)
        num = num ^ arr[i]; //xor will cancel outs all pairs.
    
    return num;
}

//Approach 2: TC-O(N) SC-O(N)
int search(int n, int arr[]) {

    for(int i=0; i<n-1; i+=2){
        
        if(arr[i] != arr[i+1])
            return arr[i];
    }
    
    return arr[n-1]; //if reach till here..then last elemnt will be single element.
}


  