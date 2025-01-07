//GFG.
//we have to return subarray of combination sum equasl to target.

//Approach 1: Using recursion with vector. TC-(2^N) SC-O(N)
 void solve(int ind, vector<int>& cands, int &target, vector<vector<int>> &ans, vector<int>&temp, int &sum, int &n){

        if(ind == n) return;

        if(sum == target){
            ans.push_back(temp);
            return;
        }
        
         //take condition.
        if(sum+cands[ind] <= target){

            sum+=cands[ind];
            temp.push_back(cands[ind]);
            solve(ind, cands, target, ans, temp, sum, n);
            
            //backtrack.
            temp.pop_back();
            sum-=cands[ind];
        }


        //not take condition.
        solve(ind+1, cands, target, ans, temp, sum, n);

    }

    //Deleting duplicates using erase function.
    vector<vector<int> > combinationSum(vector<int> &cands, int target) {

        sort(cands.begin(), cands.end());
        vector<vector<int>> ans;
        vector<int>temp;

        int n=cands.size(), ind=0, sum=0;
        solve(ind, cands, target, ans, temp, sum, n);
        
        sort(ans.begin(), ans.end());
        
        
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
         
        //  or we can use this

        // int i=0;
        // while(i<ans.size()-1){
        //     if(ans[i] == ans[i+1]){
        //         ans.erase(ans.begin()+i); //to erase.
        //     }
        //     else i++;
        // }
        return ans;
    }
    
    
    //or before giving for recursion remove dupliate and give newcands array.
    vector<vector<int> > combinationSum(vector<int> &cands, int target) {

        sort(cands.begin(), cands.end());
        vector<vector<int>> ans;
        vector<int>temp;
        
        vector<int>newCands;

        //Mini Approach 1: use j operator to skip duplicates elemens.
        int i=0;
        while(i<cands.size()){
            int j=i+1;
            while(j<cands.size() && cands[i] == cands[j]) j++;
            
            newCands.push_back(cands[i]);
            i=j;
        }
        

        //Mini Approach 2: before pushing just check. are we alread push that element or not.
        newCands.push_back(cands[0]);
        int i=1;
        while(i<cands.size()){
            
            if(cands[i] != newCands.back()){
                newCands.push_back(cands[i]);
            }
            i++;
        }
    

        int n=newCands.size(), ind=0, sum=0;
        solve(ind, newCands, target, ans, temp, sum, n);
        

        return ans;
    }






    //Approach 2: Using Set. TC-O(2^n) SC-O(n)
        void solve(int ind, vector<int>& cands, int &target, set<vector<int>> &ans, vector<int>&temp, int &sum, int &n){

        if(ind == n) return;

        if(sum == target){
            ans.insert(temp);
            return;
        }


        //not take condition.
        solve(ind+1, cands, target, ans, temp, sum, n);
        
        //take condition.
        if(sum+cands[ind] <= target){

            sum+=cands[ind];
            temp.push_back(cands[ind]);
            solve(ind, cands, target, ans, temp, sum, n);
            
            //backtrack.
            temp.pop_back();
            sum-=cands[ind];
        }

    }

    vector<vector<int> > combinationSum(vector<int> &cands, int target) {

        sort(cands.begin(), cands.end());
        set<vector<int>> ans;
        vector<int>temp;

        int n=cands.size(), ind=0, sum=0;
        solve(ind, cands, target, ans, temp, sum, n);
        
        vector<vector<int>>result;
        for(auto i:ans)
            result.push_back(i);
            
        return result;
    }