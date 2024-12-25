//GFG.
// Assign Cookies
//first sort both the arrays..ans use two pointer appraoch. if current cookies can be assignable then assign it
//and icnrement count of both i and j. if not assignable then increment count of j only.
int maxChildren(vector<int> &greed, vector<int> &cookie) {
    
    int n=greed.size(), m=cookie.size();
    
    sort(greed.begin(), greed.end());
    sort(cookie.begin(), cookie.end());
    
    int i=0, j=0, cnt=0;
    while(i<n && j<m){
        
        if(cookie[j] >= greed[i]){
            cnt++;
            i++; 
        }
        
        j++;
    }
    
    return cnt;
}