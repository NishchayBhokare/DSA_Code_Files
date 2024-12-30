//GFG and code studio.

//Below approach is for gfg solution which contains both positive and negative elements.

//Approach : Most optimised Approach. TC-O(N) SC-O(N) if collision is there then TC will be O(N2) and if you use ordered map then O(Nlogn)
int lenOfLongestSubarr(vector<int>& arr, int k) {
    
    int n=arr.size(), maxLen=0, sum=0;
    unordered_map<int,int>mapping;

    for(int i=0; i<n; i++){

    sum+=arr[i]; //take current eleement and add it to the sum.

    if(sum == k){ //now check whether current sum equals to k or not.
        maxLen = max(maxLen,i+1); //if yes then take lenght as current index+1. because of zero based indexing.
    } 

        //now chcek, is ther pair of value = sum-k is present or not. if present.
        //then surely there will be subarray from next index of this sum-k pair.
        //suppose sum is 9 and k is 4. now we will check 9-4=5. so is there
        //any pair of value 5 or not. if yes. then we can surely say. from
        //that index+1 till current index we have subarray with sum 4. 
        //because 5+4 = 9. so next index + current index will be size of this valid subarray.
    if(mapping.find(sum-k) != mapping.end()){
        int len = i - mapping[sum-k]; //lenght will be i- (sum-k)pair value index. that will convert into lenght from next index to 
        //current index.
        maxLen = max(maxLen, len); //now take max length.
    }

    if(mapping.find(sum) == mapping.end()){ //if  already there is pair of sum is present
    //then don't update their pair index. because we want maximum subarray. this will happen when array has 0 elemens. like 2 0 0 4. k=4
        mapping[sum]=i;
    }
    }

    return maxLen;
}

//We can do like this too.
int lenOfLongestSubarr(vector<int>& a, int k) {
    int n=a.size(), pSum=0, maxLen=0;
    unordered_map<int,int>ump;
    ump[0]=-1;
    
    for(int i=0; i<n; i++){
        pSum += a[i];
        if(ump.find(pSum) == ump.end() ) ump[pSum]=i;
        
        if(ump.find(pSum-k) != ump.end()){
            
            int ind = ump[pSum-k];
            maxLen = max(maxLen, i-ind);
        }
    }
        
    return maxLen;
}



//Below solution is most optimised only for positive elemnents. above solution will work for positive elements.
//but we can optimise it using below solution. because elemnts are only positive numebs so.
//Approach : using two pointer approach. TC-O(2N) SC-O(1).
//This solution is called as two pointer approach or sliding window technique.
int longestSubarrayWithSumK(vector<int> a, long long k) {
    
    long long maxLen=0, left=0, right=0, n=a.size();
    long long sum=0;
    while(right<n){

        sum+=a[right];

        while(left<=right && sum > k){ //loop till  curernt sum excedded from k.
            sum-=a[left];
            left++;
        }

        if(sum == k) { //if sum equals then take lenght.
            maxLen = max(maxLen, right-left+1);
        }

        right++;
    }

    return (int)maxLen;
}