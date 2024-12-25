//GFG.

//Approach 1: using range based parition. TC-O(N) SC-O(1)
//Logic is we're using two varaibles to make range. and again find maximum possible distance jump from this left to right 
//range. then update left to next of right for next range.
//and update right also to maxijump index. if we' re not able to reach till the end then left will be greter than right.
//so added that condition. 
int minJumps(vector<int>& arr) {
    
    int n=arr.size();
    int left = 0, right = 0, jump=0;
    
    while(left <= right && right < n-1){
        
        int maxJump = 0;
        for(int i=left; i<=right; i++){
            
            maxJump = max(maxJump, i+arr[i]);
        }
        
        left = right+1;
        right = maxJump;
        jump++;
    }
    
    if(left <= right)
        return jump;
    
    return -1;
}


//Approach 2: using queue. by storing ranges. TC-O(N) SC-O(N)
int minJumps(vector<int>& arr) {
    
    int n=arr.size();
    queue<pair<int,int>>q;
    q.push({0,0});
    
    for(int i=0; i<n; i++){
        
        while(!q.empty() && q.front().first < i){ //if current index is greater than range present in queue.front then pop it.
            q.pop();
        }
        
        if(q.empty()) return -1; //if we' re not able to rach this index i. then there will be q is empty. as there will not be pair for this condition.
        
        auto pr = q.front();
        
        if(pr.first >= n-1) return pr.second; //if reach till the end return jump coount.
        
        if(i+arr[i] > pr.first){ //if we found more long distance.then only add in queue.
            q.push({i+arr[i], pr.second+1});
        }
    }
    return -1;
}


//Approach 3: using recurison TC-O(exponentatial) SC-O(N). trying out all possible jump from current index.
int solve(int i,int jumpCnt, vector<int> &arr, int &n){
    
  if(i >= n-1) return jumpCnt;

  int minJumpCnt = INT_MAX;
  for(int j=arr[i]; j>= 1; j--){
        
      int jump = i+j;
        
      int cnt = solve(jump,jumpCnt+1, arr, n);
      minJumpCnt = min(cnt,minJumpCnt);
  }
  return minJumpCnt;
}

int minJumps(vector<int>& arr) {
    int n=arr.size();
    int ans = solve(0,0,arr,n);
    if(ans == INT_MAX) return -1;
    return ans;
}


//Approach 4: using dp. TC-O(N2) SC-O(N)
int solve(int i,int jumpCnt, vector<int> &arr, int &n){
    
  if(i >= n-1) return jumpCnt;

  int minJumpCnt = INT_MAX;
  for(int j=arr[i]; j>= 1; j--){
        
      int jump = i+j;
        
      int cnt = solve(jump,jumpCnt+1, arr, n);
      minJumpCnt = min(cnt,minJumpCnt);
  }
  return minJumpCnt;
}

int minJumps(vector<int>& arr) {
    int n=arr.size();
    int ans = solve(0,0,arr,n);
    if(ans == INT_MAX) return -1;
    return ans;
}
