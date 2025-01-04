//GFG.


//Approach 1: TC-O(N) SC-O(N)
//Approach is similar like question 21. in which we were count subaryy with given sum.
//here we're counting subarray with xor.

long subarrayXor(vector<int> &arr, int k) {

    long long n=arr.size(),cnt=0, preXor=0;

    unordered_map<int,int>ump;
    ump[0]=1; //initilise map with 0 and its frequency 1.

    for(int i=0; i<n; i++){
        
        preXor = preXor ^ arr[i]; //store prefix xor.
        
        int removalFreq = preXor ^ k; //take xor. for removal freq. so that after removing those elements we will get xor equals to k.
        
        if(ump.find(removalFreq) != ump.end()) //if removalFreq is exist then 
            cnt += ump[removalFreq]; //then take count of ways. and frequency such that subarray can found.
        
        
        ump[preXor]++; //also increment frequency of preXor.
    }

return cnt;
}


//Brute force Approach. TC-O(N2) SC-O(1)
long subarrayXor(vector<int> &arr, int k) {

    long long n=arr.size(),cnt=0;
    
    for(int i=0; i<n; i++){
        long long Xor = 0;
        for(int j=i; j<n; j++){
            Xor = Xor ^ arr[j];
            
            if(Xor == k)
                cnt++;
        }
    }
    
    return cnt;
}
