#include <iostream>
#include <vector> 

void addEdge(std::vector<std::vector<int>>& adj, int u, int v);
void printGraph(std::vector<std::vector<int>>& adj, int V);


int main(){
	int V = 4;   //No. of vertices

	//array of vectors:
	std::vector<std::vector<int>> adj(V, std::vector<int>());

	addEdge(adj, 0, 1);
	addEdge(adj, 0, 2);
	addEdge(adj, 1, 2);
	addEdge(adj, 1, 3);
	
	printGraph(adj, V);

	return 0;
}

// Function to add edges between vertices of undirected graph
void addEdge(std::vector<std::vector<int>>& adj, int u, int v){
	adj[u].push_back(v);
	adj[v].push_back(u);
}

// Function to print the adjacency list
void printGraph(std::vector<std::vector<int>>& adj, int V){
	for(int i=0; i<V; i++){
		for(int x: adj[i])
			cstd::out<<x<<" ";
		std::cout<<endl;	
	}
}