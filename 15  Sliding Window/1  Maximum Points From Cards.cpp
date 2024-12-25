//Code studio.
// Maximum Points From Cards

//basically we have to find the maximum points we can collect either from front or from back.

//TC-O(N) SC-O(1).
int maxPoints(vector<int>&arr , int k){
    
    int n=arr.size();
    if(k>n) return 0;

    int left=0, right=n-1, Lsum=0, Rsum=0, maxSum=0;

    while(left<k){ //first take k elements from front and store it in leftsum.
        Lsum+=arr[left++];
    }

    maxSum = Lsum; 
    left--; //update maxsum with lsum also decrement left because left will be out of window size. 

    while(left >= 0){ //now loop till left is greater than or equal to zero.

        //substraction from front.
        Lsum = Lsum - arr[left];

        //addition from back.
        Rsum = Rsum + arr[right];

        //decrement both.
        left--;
        right--;

        int Tsum = Lsum + Rsum; //take sum of both

        maxSum = max(maxSum, Tsum); //calculate maxsum and update accroding to it.
    }

    return maxSum;
}