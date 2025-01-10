//Leetcode & GFG.

//Approach 1: TC-O(2N) SC-O(N).

vector<int> asteroidCollision(vector<int>& ast) {
    vector<int> ans;
    int n = ast.size();

    for(int i=0; i<n; i++){
        bool isPossibleToAdd = true; 

        if(ans.size()>0 && ans.back() > 0 && ast[i] < 0){ //then possible collision.

            int currAst = abs(ast[i]);
            int lastAst = ans.back();

            while(ans.size()>0 && lastAst>0 && currAst > lastAst){ //if current -ve element's absolute value is greater than last +ve element in vector. then collisiono is possible. 
        
                ans.pop_back(); // as current element is greater so pop out smaller element.
                if(ans.size()>0) lastAst = ans.back();
            }

            if(ans.size()>0 && currAst == lastAst){  //if both same. then burst both.
                ans.pop_back();
                isPossibleToAdd = false;
            }

            //if -ve elemenet's abs is lesser than last +ve element..
            // then that bigger asteroid will exploid this current small asteriod so no need to add this in array.
            else if(ans.size()>0 && currAst < lastAst){
                isPossibleToAdd = false;
            }
        }
        
        if(isPossibleToAdd)
            ans.push_back(ast[i]);
    }

    return ans;
}