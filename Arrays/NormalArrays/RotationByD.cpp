 // Example for finding duplicate elements and return it.
// link-
    // https://practice.geeksforgeeks.org/problems/rotate-array-by-n-elements-1587115621/1#
 
 void rotateArr(int arr[], int d, int n){ // Time complexity is O(n) & space complexity is O(n);
    int temp[d];
    d=d%n;     // to handle d>n situation i.e if d=77 and n=44 then d%n=33. so we have to rotate array by 33.

    int i=0;   // i pointing to starting postion in arr array.
    for(i;i<d;i++){
        temp[i]=arr[i]; // storing elements which are before 'd' to new array.
    }

    int j=d; //j will point to the first element which are going to shfiting.
    for(i=0;i<(n-d);i++){ //shifting remaining elements to starting of an array.(overwriting)
        arr[i]=arr[j];
        j++;
    }

     j=0; // here j is pointing to the starting position in temporary array.
    for(i;i<n;i++){ //Adding stored element to the main array at the end.
    // here i value is (n-d).
        arr[i]=temp[j];
        j++;
    }
}

 void rotateArr(int a[], int d, int n){ // Time complexity is O(n) & space complexity is O(1);
        d%=n;
        //First reversing d elements from starting index up to the d-1 that is a+d.
        reverse(a, a+d);

        //Then reversing the last n-d elements.
        reverse(a+d, a+n);

        //Finally, reversing the whole array.
        reverse(a, a+n);
        
    }