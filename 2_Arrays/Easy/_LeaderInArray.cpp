class Solution {
  public:
    vector<int> leaders(vector<int>& arr) {
        // code here
        int bigLeader = arr[arr.size()-1];
        
        vector<int>ans;
        ans.push_back(arr[arr.size()-1]);
        
        for(int i=arr.size()-2; i>=0; i--){
            
            if(arr[i] >= bigLeader){
                ans.push_back(arr[i]);
                bigLeader = arr[i];
            }
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};