
//GFG solution using Dijkstra algorithm. 
Algorithm for finding distance from 0 (src) to nth(dest) node
//Apporach 1: optimised apporach..for more explanation..refer 11th question.
 vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
	unordered_map<int,list<pair<int,int>> > adj;
	
	for(int i = 0; i<m; i++){ //creation of adjacency list.
		int u = edges[i][0];
		int v = edges[i][1];
		int w = edges[i][2];
		
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
	
	vector<int> parent(n+1, -1); //as source node starts from 1. so size will be n+1.
	vector<int>distance(n+1,INT_MAX);
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> >pq;
	//creation min heap
	
	int source = 1;
	pq.push({0,source});
	distance[source] = 0;
	
	while(!pq.empty()){
		auto node = pq.top();
		pq.pop();
		
		int nodeVal = node.second;
		int nodeDist = node.first;
		
		for(auto neighbor:adj[nodeVal]){
			int nNode = neighbor.first;
			int nDst = neighbor.second;
			
			int totalDst = nodeDist + nDst;
			
			if(totalDst < distance[nNode]){ //if current distance is minimum than existant..then update. and push in queue
				distance[nNode] = totalDst;
				parent[nNode] = nodeVal;
				
				pq.push({totalDst, nNode});
			}
		}
	}
	
	vector<int>path;
	if(distance[n] == INT_MAX)
		return {-1};
	
	path.push_back(distance[n]); //first need to store distnace to reach that path.
	path.push_back(n); //then need to store destination node.
	
	int currNode = n;
	while(currNode != 1){ //doing memorization..backtraking. to get path.
		currNode = parent[currNode];
		path.push_back(currNode);
	}
	
	
	return path;
}





//Code studio

//question is find shortest path between one node to another node.
//Approach 2: use BFS traversal..as it traverse level wise..so it will help in finding shortest path.
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




















