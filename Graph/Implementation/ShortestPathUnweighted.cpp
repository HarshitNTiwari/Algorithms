#include <iostream>
#include <vector>

// BFS solution to the shortest path in an unweighted graph:
// Given an unweighted graph and a source node s, find the distance of each node from s.

vector<int> shortestPath(std::vector<std::vector<int>>& adj, int s, int V){
	std::vector<int> dist(V, -1); //dist array to store the distances

	std::queue<int> q;
	q.push(s);
	dist[s] = 0;  //distance of source from itself is 0

	while(!q.empty()){
		int u = q.front();
		q.pop();

		for(int v : adj[u]){
			if(dist[v] == -1){
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
	}

	return dist;
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

	int s = 0;
	std::cout<<shortestPath(adj, s, V);

	return 0;
}