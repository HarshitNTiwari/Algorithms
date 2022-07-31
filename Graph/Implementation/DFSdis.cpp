#include <iostream>
#include <vector>

/*
Print DFS of a possibly disconnected graph with no source given

*/

void DFSrec (std::vector<std::vector<int>> adj, int s, std::vector<int> visited){

	visited[s] = true;
	std::cout<<s<<" ";
	for(int u: adj[s])
		if(visited[u]==false)
			DFSrec(adj, u, visited);
}

void DFS (std::vector<std::vector<int>> adj, int V, int s){

	std::vector<int> visited(V, false);
	for (int i = 0; i < V; ++i)
		if(visited[i]==false)
			DFSrec(adj, s, visited);
}


void addEdge(std::vector<std::vector<int>>& adj, int u, int v){
	adj[u].push_back(v);
	adj[v].push_back(u);
}

int main(){
	int V = 4;  //No. of vertices

	//array of vectors to represent the adjacency list:
	std::vector<std::vector<int>> adj(V, std::vector<int>());

	addEdge(adj, 0, 1);
	addEdge(adj, 0, 2);
	addEdge(adj, 1, 2);
	addEdge(adj, 1, 3);

	int s = 0;  //source node
	DFS(adj, V, s);

	return 0;
}