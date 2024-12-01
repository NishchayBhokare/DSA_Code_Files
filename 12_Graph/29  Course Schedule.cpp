//GFG
//This question is extentsion of previous prerequisite question.

//in last question we were need to return only true or false..that means..task can complete or not..just need to return that in last ques
//but here..we have to returning order also..so just we need to store those orders of task completion in array.
//Approach 1: my solution.
bool solve(int node, vector<vector<int>>&adj, vector<bool>&task, vector<bool>&visited, vector<int>&ansArr){
    visited[node] = true;
    
    for(auto nbr:adj[node]){
        if(!visited[nbr]){
            bool ans = solve(nbr,adj,task,visited,ansArr);
            
            if(ans == false)
            return false; 
        }
        else{
            
            if(task[nbr] == false) //if neihgbour is already visited and also task not completed then return false.
                return false;
        }
    }
    
    task[node] = true; //before returing maek sure to mark it as true.
    ansArr.push_back(node); //push this task node ..which is completed.
    return true;
}

vector<int> findOrder(int N, int m, vector<vector<int>> pre) 
{
    vector<int>ansArr;
    vector<vector<int>>adj(N);
    vector<bool>visited(N,false);
    vector<bool>task(N,false);
    
    for(auto i:pre){
        adj[i[0]].push_back(i[1]);
    }
    
    
    for(int i = 0; i<N; i++){
        
        if(!visited[i]){
            bool ans = solve(i,adj,task,visited,ansArr);
            
            if(ans == false)
            return {}; //if at any point..taks cannot get's complete...then return empty array.
        }
    }

    return ansArr; //return answer.
}