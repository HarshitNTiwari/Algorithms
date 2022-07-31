/*
Author: Harshit Tiwari
Date: 31-06-2022
https://leetcode.com/problems/find-closest-node-to-given-two-nodes/
*/


class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int V = edges.size();
		
		// array to store distances of all the nodes from node1
        vector<int> dist1(V, INT_MAX);
		
		//doing regular BFS considering node1 as the source
        queue<int> q;
        q.push(node1);
        dist1[node1] = 0;
        
        while(!q.empty()){
            int u = q.front();
            q.pop();
            
            int v = edges[u];
            if(v!=-1 && dist1[v] == INT_MAX){
                dist1[v] = dist1[u]+1;
                q.push(v);
            }
        }
		
		// array to store distances of all the nodes from node2
        vector<int> dist2(V, INT_MAX);
		
		//array to store final distances i.e. max of the two distances
        vector<int> res(V, INT_MAX);
        
		//doing regular BFS considering node2 as the source
        queue<int> q1;
        q1.push(node2);
        dist2[node2] = 0;
        res[node2] = max(dist1[node2], dist2[node2]);
        
        while(!q1.empty()){
            int u = q1.front();
            q1.pop();
            int v= edges[u];
            if(v!=-1 && dist2[v] == INT_MAX){
                dist2[v] = dist2[u]+1;
                q1.push(v);
                res[v] = max(dist1[v], dist2[v]);
            }
        }
        
		//checking if the answer is possible or not
		int flag=0;
        for(int i=0; i<res.size(); i++){
            if(res[i]!=INT_MAX)
                flag =1;
        }
        if(flag==0) //i.e. all the distances are infinite, so return -1
            return -1;
		
		//finding the node with the minimum distance
		int ans=0; 
        for(int i=1; i<res.size(); i++){
            if(res[i]<res[ans])
                ans = i;
        }
        return ans;
    }
};