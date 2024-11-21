
#include<bits/stdc++.h>
using namespace std;

class graph{
    public:
        unordered_map<int,list<int>> adj; //we can create graph using unordered map (adjacency list). 
        //or using vector of vector.(adjacency matrix.)
        
        //2nd way..
        vector<vector<int>>adjTwo;

        graph():adjTwo(5,vector<int>(5,0)){

        }


    // void addEdges(int u, int v, int direction){
    //     adj[u].push_back(v);

    //     if(direction == 0)
    //         adj[v].push_back(u);
    // }

    
    //2nd way to create graph using adjacency matrix.
    void addEdges(int u, int v, int direction){
        adjTwo[u][v] = 1;

        if(direction == 0)
            adjTwo[v][u] = 1;
    }

    void printAdjacencyList(){
        for(auto i:adj){
            cout<<i.first<<" -> ";
            for(auto j:i.second){
                cout<<j<<" ";
            }cout<<endl;
        }
    }

 
    void printAdjacencyMatrix(){
        for(auto i:adjTwo){
            for(auto j:i){
                cout<<j<<" ";
            }cout<<endl;
        }
    }
};

int main(){
    graph g;

    g.addEdges(1,3,0);
    g.addEdges(2,3,0);
    g.addEdges(4,1,0);
    g.addEdges(2,1,0);
    g.addEdges(3,4,0);

    g.printAdjacencyMatrix();

    return 0;
}