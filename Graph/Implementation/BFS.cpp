#include <iostream>
#include <vector>
#include <queue>


/*
Given an undirected and connected graph and a source vertex 's', print BFS from the given source.

TC: O(|V|+|E|)

*/

void BFS (std::vector<std::vector<int>> adj, int V, int s){

	std::vector<bool> visited(V, false);  //visited array to track if a vertex has been added to the queue - initialsed with false
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

	int s = 0;  //source node
	BFS(adj, V, s);

	return 0;
}