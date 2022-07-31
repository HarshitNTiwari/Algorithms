#include <iostream>
#include <vector>

// Detect cycle in an undirected graph - DFS solution


// Recursive DFS function to return if the Graph has a cycle
void DFSrec(std::vector<std::vector<int>>& adj, int s, std::vector<bool>& visited, int parent){
	// here 'parent' is the parent node of 's', that is recursive call for 's' was made from 'parent'
	visited[s] = true;
	for(int v : adj[s]){
		if(visited[v] == false){
			if(DFSrec(adj, v, visited, s))//the adjacent node 'v' is passed as source for next call and current node 's' is passed as the parent
				return true;
		}
		else if(v!=parent)  //i.e. the adjacent node has been visited already and is not parent.
			return true;
	}
	return false;
}	


void DFS(std::vector<std::vector<int>>& adj, int V){
	std::vector<bool> visited(V, false);
	for(int i=0; i<V; i++){
		if(visited[i] == false){
			if(DFSrec(adj, i, visited, -1)) //parent of the initial node is made as -1
				return true;
		}
	}
	return false;
}


void addEdge(std::vector<std::vector<int>>& adj, int u, int v){
	adj[u].push_back(v);
	adj[v].push_back(u);
}

int main(){
	int V = 4;

	//array of vectors:
	std::vector<std::vector<int>> adj(V, std::vector<int>());

	addEdge(adj, 0, 1);
	addEdge(adj, 0, 2);
	addEdge(adj, 1, 2);
	addEdge(adj, 1, 3);

	std::cout<<DFS(adj, V);

	return 0;
}