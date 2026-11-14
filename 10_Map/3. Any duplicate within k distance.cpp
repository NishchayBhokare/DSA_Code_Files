class Solution {
  public:
    bool checkWithinK(vector<int>& arr, int k) {
        // code here
        unordered_map<int,int>numPos;
        
        for(int i=0; i<arr.size(); i++){

            if(numPos.find(arr[i]) != numPos.end()){ //if same element already present.
                
                int currPos = i;
                int lastPos = numPos[arr[i]];
                
                if(currPos - lastPos <= k) return true; //check both indexes are in the range. 
            }
            
            numPos[arr[i]] = i;
        }
        
        return false; //if no then return false.
    }
};