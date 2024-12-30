//GFG.

//Approach 1: simple approach. without using map.
vector<int> frequencyCount(vector<int>& arr) {
    
    int n=arr.size();
    vector<int>ans(n,0);
    
    for(int i=0; i<n; i++){
        int ind = arr[i]-1; //because of one base indexing.
        
        ans[ind]++;
    }
    
    return ans;
}