//Example for returning count of pairs whose sum equals to s.
//GFG

//Approach 1: One traversal approach. TC-O(N) SC(N);
int getPairsCount(int arr[], int n, int k) {
    unordered_map<int,int>m;
    int c=0;
    for(int i=0;i<n;i++){
        c+=m[k-arr[i]]; //for every ith element checking how many elements are there from 0 to i-1 where current element make sum with them and increment count by number of elements present previously with which current element make pair sum.
        m[arr[i]]++; //incrementing frequency of current element.
    }
    return c; //return count.
}


//Approach 2:TC-O(N) SC-O(N)
int getPairsCount(int arr[], int n, int k) {
        int count = 0;
       unordered_map<int, int> freq;
       
       for(int i = 0 ;i<n;i++){
           freq[arr[i]]++; //incrementing frequency for ith element in map
       }
       
       for(int i = 0;i<n;i++){
           int needToPairSum = k-arr[i];  // calculate need to make ith element as k
           if(freq.find(needToPairSum) != freq.end()){// if required element is present in map
               count += freq[needToPairSum]; //then increment count by frequency of required element
           }
           
            if(needToPairSum == arr[i]){ //Condition when,ith element making pair with itself so in this condition reduce count by 1 becuase element can't make pair with itself
                count--; //decrement count by 1
            }
       }
       
    return count/2; //like if a doing pair with b, then we're also doing pair of b with a but we want only one pair if a and b making pair so return count divide by 2.
    }