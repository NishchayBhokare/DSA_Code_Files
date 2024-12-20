//GFG.

//Approach:1 similar approach we have done in previous question.
//just first sort the array..and create parent array and countarray which stores max length.
//if previous element is divisible for current elemnet then check for previous elemnet's countLenght of divisible elements
//if it's greater than current element then update current maxlength count. and parent length array.
 vector<int> largestDivisibleSubset(vector<int>& arr) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    
    vector<int>parent(n,-1);
    vector<int>cntArr(n,1);
    
    int maxIndLen = 0;
    
    for(int i=0; i<n; i++){
        for(int j=i-1; j>=0; j--){ //we're starting from i-1 index to 0. because we want
        //greater element to insert. lexicographically greatest array
            
            if((arr[i] % arr[j] == 0) && (cntArr[j]+1 > cntArr[i])){
                
                cntArr[i] = cntArr[j] + 1;
                parent[i] = j;
            }
        }
        
        //storing index of head of max lenth of subset. we can do this..in seperate loop too.
        if(cntArr[i] > cntArr[maxIndLen])
            maxIndLen = i;
    }
    
    
    //doing this extra overhead..because we want lexicographically greatest array
    vector<vector<int>>ans;
    for(int i=0; i<n; i++){
        //so for every subset of maximum length..check..and store in ans vector. and after that sort
        //vector and return last subset.
        if(cntArr[i] == cntArr[maxIndLen]){
            int ind=i;
    
            vector<int>temp;
            
            while(ind != -1){
                
                temp.push_back(arr[ind]);
                ind = parent[ind];
            }     
            
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
        }
    }
    
    sort(ans.begin(), ans.end());

    return ans[ans.size()-1];
}


//Approach 2: more optimised. instead storing answer in vector of vector int.
//it's better to sort the given array in descending order so that we will get greater elements first.
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