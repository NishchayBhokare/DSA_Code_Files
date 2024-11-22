//Code studio
//we need to solve gfg solution also..so check on it too.

//Approach 1: use BFS traversal..as it traverse level wise..so it will help in finding shortest path.
//now while doing bfs..create parent map..which maps..current node to its parent.
//once bfs is over...now make current node to destination node..and backtrack vai loop
//till current node not equal to soruce node.
#include <bits/stdc++.h>
vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){

	unordered_map<int,list<int>> adj;

	for(int i = 0; i<edges.size(); i++){ //creating adjacency list.
		int u = edges[i].first;
		int v = edges[i].second;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	unordered_map<int,int>parent;
	unordered_map<int,bool>visited;
	vector<int>ans;
	queue<int>q;

	q.push(s);
	visited[s]=true;
	parent[s]=-1;

	while(!q.empty()){
		int node = q.front();
		q.pop();

		for(auto neighbor:adj[node]){
			if(!visited[neighbor]){

				q.push(neighbor);
				parent[neighbor] = node; //creating node to parent mapping.
				visited[neighbor] = true;
			}
		}
	}


	int currentNode = t; //point current node to dest. node.
	ans.push_back(currentNode); //push destination node in answer.

	while(currentNode != s){ //loop till source node.
		currentNode = parent[currentNode]; //get parent node for current node.
		ans.push_back(currentNode); //push updated current node in answer.
	}

	reverse(ans.begin(),ans.end()); //as we moving from destination to source..and pushing in answer
    //we need to reverse answer vector before returning it.

	return ans;
}

















