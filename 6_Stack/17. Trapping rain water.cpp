//GFG.
//Trapping rain water- we have to count..max water we can store.
 //Approach 1: Using left and right pointer. TC-O(N) SC-O(1)

 //to store water...two of the condition should satisfied.
 //1) leftMax > Left < Right.  or 2) L > Right < RightMax. //if satiesfies this condition then only we can store.
int maxWater(vector<int> &arr) {

    int n=arr.size();

    int left=0, right=n-1, totalWater=0;
    int preMax=0, suffMax=0;
    
    while(left < right){
        
        if(arr[left] <= arr[right]){ //we are processing lesser element first..so that we can store maximum water.
            
            if(preMax > arr[left]) //someone is greater in left side..than current element so we can store water. becuase.that preMax is lesser than suffMax.
                totalWater += preMax - arr[left];
            
            else preMax = arr[left]; //if not greater..then current element will be max. so update preMax.
            
            left++;
        }
        
        else{
            
            if(suffMax > arr[right]) //same for right..checking is somone is greater in right for current eleemnt.
                totalWater += suffMax - arr[right];
            
            else suffMax = arr[right];
            
            right--;
        }
    }
    
    return totalWater;
}



 // Approach 2. By storing prefix max and suffix max. TC-O(3N) SC-O(2N)
 //for every building...tap water it can store will be min of (max element from left, max element from right) minus 
 //current element. suppose left is leftMax is 2 and rightmax is 5. but current element is 0. then we can store only 2-0 water. i.e 2.
int maxWater(vector<int> &arr) {

    int n=arr.size();
    vector<int>preMax(n,0);
    preMax[0] = arr[0];
    
    for(int i=1; i<n; i++)
        preMax[i] = max(arr[i], preMax[i-1]); //prepare prefix max. checking current element with preFix.
    
    
    vector<int>suffMax(n,0);
    suffMax[n-1] = arr[n-1]; //just check from back.
    
    for(int i=n-2; i>=0; i--)
        suffMax[i] = max(arr[i], suffMax[i+1]); //same.
        
    
    int totalWater = 0;
    
    for(int i=0; i<n; i++){
        //if current building is less than prefix max and suffix max then we can surely store water.
        if(preMax[i]>arr[i] && arr[i] < suffMax[i]) //now check..condition are satiesfiing or not.
            totalWater += min(preMax[i], suffMax[i]) - arr[i];
    }
    
    
    return totalWater; 
}


//Approach 3: TC-O(2N) SC-O(N).
//On the go..calculating prefixSum. and remaning are same. only.
int maxWater(vector<int> &arr) {

    int n=arr.size();

    vector<int>suffMax(n,0);
    suffMax[n-1] = arr[n-1];
    
    for(int i=n-2; i>=0; i--)
        suffMax[i] = max(arr[i], suffMax[i+1]);
        
    
    int totalWater = 0, preMax=0;
    
    for(int i=0; i<n; i++){
        
        preMax = max(preMax,arr[i]); //instead of array just memorizing prefix max.
        
        if(arr[i] < preMax && arr[i] < suffMax[i])
            totalWater += min(preMax, suffMax[i]) - arr[i];
    }
    
    
    return totalWater;
}