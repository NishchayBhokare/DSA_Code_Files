//Leetcode.

//Approach: we have to generate pascales triangle..addition of previous array. 
vector<vector<int>> generate(int numRows) {
    
    vector<vector<int>>ans;
    ans.push_back({1}); //push first array in ans.

    for(int k=1; k<numRows; k++){ //now traverse for next set of rows till numrows.

        vector<int>temp; 

        temp.push_back(1); //insert initial 1.

        int n=ans[k-1].size() - 1; //get size of previous array.

        for(int i=0; i<n; i++){ //loop over that array till second last element.
            
            temp.push_back(ans[k-1][i] + ans[k-1][i+1]); //get sum of previous two element and add it in temp.
        }

        temp.push_back(1); //add last 1.

        ans.push_back(temp); //insert temp in ans vector.
    }

    return ans;
}