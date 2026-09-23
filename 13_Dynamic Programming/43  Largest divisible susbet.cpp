//GFG.

//Approach 1: more optimised. instead storing answer in vector of vector int.
//it's better to sort the given array in descending order so that we will get greater elements first.
//TC-O(N2)
vector<int> largestDivisibleSubset(vector<int>& arr) {
    
    int n = arr.size();
    sort(arr.begin(), arr.end(), greater<int>()); //Sort the array in descending order to get lexicographically largest
//     // answer
    
    vector<int>parent(n,-1);
    vector<int>cntArr(n,1);
    
    int maxIndLen = 0;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            
            if((arr[j] % arr[i] == 0) && (cntArr[j]+1 > cntArr[i])){ //slight change is..now we're dividing to jth element by ith eleemnt.
                
                cntArr[i] = cntArr[j] + 1;
                parent[i] = j;
            }
        }
        
        //storing index of head of max lenth of subset. we can do this..in seperate loop too.
        if(cntArr[i] > cntArr[maxIndLen])
            maxIndLen = i;
    }
    
    vector<int>ans;
    int ind=maxIndLen;
    
    while(ind != -1){
        
        ans.push_back(arr[ind]);
        ind = parent[ind];
    }
    
    return ans;
}