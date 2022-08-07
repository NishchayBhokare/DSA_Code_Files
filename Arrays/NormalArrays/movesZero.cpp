// Example for finding duplicate elements and return it.
// link-
    // https://practice.geeksforgeeks.org/problems/move-all-zeroes-to-end-of-array0751/1

void pushZerosToEnd(int arr[], int n) { // Time complexity is O(n)
	  int p=0,q=0;
	   while(q<n){
	      if(arr[q]!=0){ //if other than 0 then swap current element i.e (p) with non-zero element i.e (q).
 	          swap(arr[p],arr[q]);
	          q++;p++; //if not zero then move both variables
	      }
	      else{
	          q++; // if zero then move only q variable and keep p variable on zero element so that further we can swap p with q.
	      }
	   }
	}

    //below solved using for loop
    //    int p=0,q;
	//    for(q=0;q<n;q++){
	//         if(arr[q]!=0){
	//            swap(arr[p],arr[q]);
	//            p++;
	//        }
	//    }