// Example for search element in rotated sorted array.
// link-
    // https://practice.geeksforgeeks.org/problems/search-in-a-rotated-array4618/1/
    
int search(int A[], int l, int h, int key){
        // l: The starting index
        // h: The ending index, you have to search the key in this range
        while(l<=h){ //looping till the l is less than or equal to the h.
            if(A[l]!=key){ // if current elm. not equal to key then move "l";
                l++;
            }
            if(A[h]!=key){// if current elm. not equal to key then move "h";
                h--;
            }
             if(A[l]==key){//if current elm equal to key then return index of that key.
                return l;  //returning index here
            }
             if(A[h]==key){//if current elm equal to key then return index of that key.
                return h;  //returning index here
            }
        }
        return -1; //if element is not present then we will return -1.
        
        //complete the function here
    }
    


    
    //This is another approach. in O(logn) complexity.
    
//     int search(int A[], int l, int h, int key)
//    {
//        // l: The starting index
//        // h: The ending index, you have to search the key in this range
//        // Complete this function
//        if(l<=h){
//            int mid=(l+h)/2;
//            if(A[mid]==key) return mid;
           
//            if(A[mid]>=A[l]){
//                if(key<=A[mid] && key>=A[l])
//                    return search(A,l,mid-1,key);
//                else
//                    return search(A,mid+1,h,key);
//            }
//            else{
//                if(key>=A[mid] && key<=A[h])
//                    return search(A,mid+1,h,key);
//                else
//                    return search(A,l,mid-1,key);
//            }
//        }
       
//        return -1;
//    } 