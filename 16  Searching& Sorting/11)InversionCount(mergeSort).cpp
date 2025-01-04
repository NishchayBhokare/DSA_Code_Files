
//count= count + len1-index1;

//Approach 1: Brute Force approach. TC-O(n2) SC-O(1)
   long long int inversionCount(long long arr[], long long n)
    {
        // Your Code Here
        long long count =0;
        for(long long i=0; i<(n-1); i++){ //starting from 0 to n-1.
            for(long long j=i+1; j<n; j++){ //starting from i to n.
                if(arr[i] > arr[j]) count++;
            }
        }
        return count;
    }


//Approach 2: Most optimised solution using merge sort.
    long long count=0; //count of inversion
    void mergeBothArrays(long long *arr2,long long start,long long mid, long long end){

    
    long long len1 = (mid-start+1); //calculating length of first array
    long long len2 = (end-mid); //calculating length of second array

    long long *firstArr = new long long[len1];  //creating array for first sub array
    long long *secondArr = new long long[len2]; //for second sub array

    long long mainArrIndex = start; //Index of for given array is pointing to start.
    for(int i=0; i<len1; i++){ 
        firstArr[i] = arr2[mainArrIndex++]; //adding elements in first subarray
    }
    
    mainArrIndex = mid+1;
    for(long long i=0; i<len2; i++){
        secondArr[i] = arr2[mainArrIndex++]; // adding elements in second subarray
    }

    //Now Merging two sorted array i.e firstArr and secondArr
    long long index1=0, index2=0;
    mainArrIndex=start;
    while(index1 < len1 && index2 < len2){ //looping till both indexes are less than its array length
        
        if(firstArr[index1] <= secondArr[index2]) arr2[mainArrIndex++] = firstArr[index1++];
        else{
         arr2[mainArrIndex++] = secondArr[index2++];
      
         count += len1-index1; //so basically if element at index1 is greater than element at index 2 
        //  then definitely index1+1, index1+2 will also greater than element at index2 cause both subarray is sorted. 
        // so relation will be length of first sub array minus index1 will be the inversion count for element at index 2.
        }    

    }

    //If any of the sub array contains elements then add those elements to main array
    while(index1 < len1) arr2[mainArrIndex++] = firstArr[index1++];

    while(index2 < len2) arr2[mainArrIndex++] = secondArr[index2++];

    delete []firstArr; //at the end delete those temporaray first and second subarray.
    delete []secondArr;
}

void mergeSort(long long *arr,long long start, long long end){
    //Base case
    if(start >= end) return;

    long long mid = start + (end - start)/2;
    
    //Go to the left part for sorting
    mergeSort(arr,start,mid);

    //Got to the right part for sorting
    mergeSort(arr,mid+1,end);

    //Now,merge both partitioned array 
    mergeBothArrays(arr,start,mid,end);
}

//Main calling function.
    long long int inversionCount(long long arr[], long long N)
    {
       mergeSort(arr,0,N-1);
       return count;
    }