#include <iostream>
#include <vector>

// Detect cycle in a Directed graph - DFS solution


// Recursive DFS function to return if the Graph has a cycle
void DFSrec(std::vector<std::vector<int>>& adj, int s, std::vector<bool>& visited, std::vector<bool>& recStack){
	visited[s] = true;
	recStack[s] = true;

	for(int v: adj[s]){
		if(visited[v] == false){
			if(DFSrec(adj, v, visited, recStack))
				return true;
		}
		else if(recStack[v]) //if the adjacent node is present in the current call stack, then it is an ancestor
			return true;
	}
	recStack[s] = false;
	return false;
}

void DFS(std::vector<std::vector<int>>& adj, int V){
	std::vector<bool> visited(V, false);
	std::vector<bool> recStack(V, false);

	for(int i=0; i<V; i++){
		if(visited[i] == false)
			if(DFSrec(adj, i, visited, recStack))
				return true;
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