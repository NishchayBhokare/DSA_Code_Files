//Code studio.

//Approach 1: Optimised approach TC-O(N) SC-O(1)
//We can solve this question by taking another vector to store elemnts. but it will take SC-O(N)
vector<int> rotateArray(vector<int>& arr, int n) {
    
    int i=0, val=arr[0]; //store first elemetn in variable.

    for(i; i<n-1; i++){
        arr[i]=arr[i+1]; //then assign i+1 element in ith position.
    }

    arr[i] = val; //at the end push first element at last.

    return arr;
}