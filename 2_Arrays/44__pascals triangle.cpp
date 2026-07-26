//Leetcode.

//Approach: My approach. easy to understand.
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});

        for(int row=2; row<=numRows; row++){

            vector<int>temp;

            //starting element: push 1.
            temp.push_back(1);

            //middle elements.
            vector<int>prev = ans.back();

            for(int i=1; i<prev.size(); i++)
                temp.push_back(prev[i-1] + prev[i]);
            
            //ending element: push 1.
            temp.push_back(1);


            ans.push_back(temp);
        }

        return ans;
    }
};


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