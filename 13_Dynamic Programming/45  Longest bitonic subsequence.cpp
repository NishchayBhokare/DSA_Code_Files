//GFG.

int LongestBitonicSequence(int n, vector<int> &nums) {
        //storing Longest increasing subsequence.
        vector<int> incLen(n,1);
        for(int i=0; i<n; i++){
            
            for(int j=0; j<i; j++){
                
                if(nums[i] > nums[j] && incLen[j]+1 > incLen[i]){
                    
                    incLen[i] = incLen[j]+1;
                }

            }
        }

        
        //storing Longest decreasing subsequence.
        vector<int> decLen(n,1);
        for(int i=n-1; i>=0; i--){
            
            for(int j=n-1; j>i; j--){
                if(nums[i] > nums[j] && decLen[j]+1 > decLen[i]){
                    
                    decLen[i] = decLen[j]+1;
                }
            }
        }
        
        
        //final answer.
        int ans=0;
        
        for(int i=0; i<n-1; i++){
            if(incLen[i] != 1 && decLen[i] != 1){ //this is just additional case..to eliminate by taking strictly increasing/decreasing subsequence
            //as bitonic subsequence.
            
                int curr = incLen[i] + decLen[i] - 1;
                ans = max(ans,curr);
            }
        }
        
        return ans;
    }