#include <iostream>
#include <vector>
#include <queue>


/*
Print BFS of a possibly disconnected graph with no source given

TC: O(|V|+|E|)
*/

void BFS (std::vector<std::vector<int>>& adj, int s, std::vector<bool>& visted){

	std::queue<int> q; 

	q.push(s);   //enqueue the source vertex
	visited[s] = true; //marking the source vertex as visted

	while(!q.empty()){
		int u = q.front();
		q.pop();
		std::cout<<u<<" ";

		for(int v: adj[u]){  //traversing the adjacency list of vertex u
			if(visited[v]==false){
				q.push(v);
				visited[v] = true;
			}
		}
	}

}

void BFSdis (std::vector<std::vector<int>>& adj, int V){

	std::vector<bool> visited(V, false);  //visited array to track if a vertex has been added to the queue - initialsed with false

	for(int i=0; i<V; i++)
		if(visited[V]==false)
			BFS(adj, i, visited);   //if the current vertex isn't already visited, consider it as source and print its BFS
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

	BFSdis(adj, V);

	return 0;
}