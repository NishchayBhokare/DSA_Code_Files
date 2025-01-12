// Example for search element in rotated array.

//Extended question code studio. if elements have duplicate numbers. then we need to add one more check.
bool search(vector<int>& nums, int target) {
        
        int low=0,high=nums.size()-1;

        while(low <= high){

            int mid = low+(high-low)/2;

            if(nums[mid] == target)
                return true;
            
            if(nums[low]==nums[mid] && nums[high]==nums[mid]){ //This is the additional condition we have applied.
                low++; //skip duplicate elements. //because if elements are duplicate then cannot take decision of incrementing low or high.
                high--;
                continue;
            }
            
            if(nums[mid] <= nums[high]){

                if(target > nums[mid] && target <= nums[high])
                    low = mid+1;
                
                else   
                    high = mid-1;
            }
            else{

                if(target >= nums[low] && target < nums[mid]){
                    high=mid-1;
                }
                else 
                    low = mid+1;
            }
        }


        return false;
    }


//Approach 1 : Most Efficient Approach. Using single pass
//Analogy: if we stand on particualr element, then either left part is sorted or right part is sorted completely.
//so serch according to above information.
int search(int a[], int low, int high, int key){
        
        while(low<=high){ //looping till low less than or equal to high
            int mid = low + (high - low)/2;
            if(a[mid]==key) return mid; //if we found key return index.

                if(a[mid] >= a[low]){ //if condition is true then left side is sorted.
                    if(key < a[mid] && key >= a[low]) high = mid-1; //if key is lesser than mid and greater than or equal to low, that means key will be in left half cause left part is sorted.
                    else low = mid+1; //else search in right part.
                }
                else{ //if condition is true,right side is sorted
                    if(key > a[mid] && key <= a[high]) low = mid+1; //if key grater than mid and less than or equal to high that means, key will be in right part cause right part is sorted.
                    else high = mid - 1; //else search in left part.
                }
        }
        return -1;
    }


//Approach 2: Efficient Approach. Using binary search and pivot index. TC- O(logn) SC- O(1)
//function for calculate index for pivot(we already see this function)
int pivotIndex(int a[], int low, int high){
        while(low<high){
            int mid = low + (high-low)/2;
            if(a[mid] > a[high]) low = mid+1;
            else{  
             high = mid;
            }
        }
        return high;  
    }
    
//function for binary search.    
    int binarySearch(int a[],int low,int high,int key){
        while(low <= high){
            int mid = low + (high - low)/2;
            if(key > a[mid]) low = mid+1;
            else if(key < a[mid]) high = mid-1;
            else return mid;
        }
        return -1;
    }
    
    
//Main function
    int search(int A[], int low, int high, int key){
        
        // eg. 5, 6, 7, 8, 9, 10, 1, 2, 3
        // so we will divide in two arrays, 5 to 10 and 1 to 3. so if element is in range 1 to 3 then do binary search from pivot index to high else low to pivotindex-1.
        //calling pivotIndex function to get index of minimum element in array.
         int pIndex=pivotIndex(A,low,high);

         if(key <= A[high]){ //if key is less than or equal to high, that means definitely key will present in pivot to high range. so do binary search in pivot index to high.
            return binarySearch(A,pIndex,high,key);
         }
         else{
            //else search in pivotindex -1 to low part. i.e low to pivotindex-1.
            return binarySearch(A,low,pIndex-1,key);
         }
    }




//Approach 1: Using linear search TC-O(n) SC-O(1).
     int search(int A[], int low, int high, int key){
        
        for(int i=0; i<=high; i++){
            if(A[i]==key) return i; //if key is meet return its index.
        }
        return -1;
    }