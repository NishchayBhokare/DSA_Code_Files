//GFG.

//Similar approach like previous problem n meeting in the room.
//sort by ending time. so that earliest ending interval will be at front.
//and same thing. assing last finish time as first pair's ending time.
//then loop over and calcualte answer.
bool cmp( vector<int> &a, vector<int> &b){
    return a[1] < b[1];
}

class Solution {
  public:
    int minRemoval(vector<vector<int>> &arr) {

        sort(arr.begin(), arr.end(), cmp);
        
        int lastFinishT = arr[0][1];
        int n=arr.size(), cnt = 0;
        
        for(int i=1; i<n; i++){
            
            int start = arr[i][0];
            
            if(start >= lastFinishT){ //if start time is greater than or equal to last finish time.
                
                lastFinishT = arr[i][1]; //update last finish time.
            }
            else //overlapping condition.
                cnt++; //increment count.
        }
        
        
        return cnt;
    }
};