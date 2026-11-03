//Disjoint set are the set..in which we can get ulitmate parent and makeunion by rank..
//basically this disjoint set can be used to  find MST. 

//TC- O(E * (4 * alpha)). there is huge mathematics for it. But yes alpha value is very 
// less so overall TC is O(E). E is number of edges, if we traverse over the edges. 
//otherwise TC will be O(1) if we are calling just one or two times for make union.

#include<bits/stdc++.h>
using namespace std;

//Implemnetion of Disjoint Set.
class disJointSet{
	public:
	vector<int>parent;
	vector<int>rank;
	vector<int>size; //we can use size also.

	disJointSet(int n){ //size
		parent.resize(n+1);
		for(int i = 0; i<=n; i++) //if you do n+1 it will work for both..0 based indexing and 1 based indexing.
			parent[i] = i;

		rank.resize(n+1,0);
		size.resize(n+1,1);
	}

	int findParent(int node){
		if(parent[node] == node)
			return node;
			
		parent[node] = findParent(parent[node]);
		
		return parent[node];
	}

	void makeUnionByRank(int u, int v){
		int uP = findParent(u);
		int vP = findParent(v);
		
		if(uP == vP)
			return; //if parent is same..then no need to go ahead..just reaturn.

		if(rank[uP] == rank[vP]){
			parent[vP]  = uP;
			
			rank[uP]++;
		}
		else if(rank[uP] > rank[vP])
			parent[vP] = uP;
			
		else
			parent[uP] = vP;
	}

	void makeUnionBySize(int u, int v){
		int uP = findParent(u);
		int vP = findParent(v);
		
		if(uP == vP)
			return; //if parent is same..then no need to go ahead..just reaturn.

		if(size[uP] <= size[vP]){ //if less than equal to then assign up to vp. and even if same..then also we can do like this.
			parent[uP]  = vP;
			size[vP] += size[uP];
		}
		else{ //if up is greater then assign vp to up.
			parent[vP]  = uP;
			size[uP] += size[vP];
		}
	}
};


int main(){
    disJointSet ds(7);
    
    // ds.makeUnionByRank(1,2);
    // ds.makeUnionByRank(2,3);
    // ds.makeUnionByRank(4,5);
    // ds.makeUnionByRank(6,7);
    // ds.makeUnionByRank(5,6);

    // if(ds.findParent(3) == ds.findParent(7)){
    //     cout<<"same";
    // }
    // else cout<<"not same"<<endl;

    // ds.makeUnionByRank(3,7);

	// if(ds.findParent(3) == ds.findParent(7)){
    //     cout<<"same";
    // }
    // else cout<<"not same";


	//Using size.
	ds.makeUnionBySize(1,2);
    ds.makeUnionBySize(2,3);
    ds.makeUnionBySize(4,5);
    ds.makeUnionBySize(6,7);
    ds.makeUnionBySize(5,6);

    if(ds.findParent(3) == ds.findParent(7)){
        cout<<"same";
    }
    else cout<<"not same"<<endl;

    ds.makeUnionBySize(3,7);

	if(ds.findParent(3) == ds.findParent(7)){
        cout<<"same";
    }
    else cout<<"not same";
}