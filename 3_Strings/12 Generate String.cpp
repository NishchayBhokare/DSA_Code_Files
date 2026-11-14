

//Approach 1: Optimised approach. Hash map with suffix counter. 
// TC-O(N*M(for internal while loop)) SC-O(N*M)
class Solution {
  public:
    vector<string> generateUsernames(vector<string>& arr) {
        
        vector<string>ans;
        unordered_set<string>used(arr.begin(), arr.end());
        
        unordered_map<string,int>strToFreq;
        
        
        for(int i=0; i<arr.size(); i++){    
            
            if(strToFreq.find(arr[i]) == strToFreq.end()){
                
                strToFreq[arr[i]]=1; //marking 1 because, reserved string already taken.
                //now from next onward's we will incrementing number.
                used.insert(arr[i]);
  
                ans.push_back(arr[i]);
            }
            else{
                
                int suffix=strToFreq[arr[i]];
                string updatedStr = arr[i]+to_string(suffix);
                
                while(used.find(updatedStr) != used.end()){
                    suffix++;
                    updatedStr = arr[i]+to_string(suffix);
                }
                
                used.insert(updatedStr);
                strToFreq[updatedStr] = suffix+1; //for next iteration.
                
                ans.push_back(updatedStr);
            }
        }
        
        return ans;
    }
};