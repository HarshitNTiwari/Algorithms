/*
Author: Harshit Tiwari
Date: 31-06-2022
https://leetcode.com/problems/longest-cycle-in-a-graph/
*/


class Solution {
    int DFS(vector<int>& edges, int s, vector<bool>& visited, vector<int>& recStack){
        visited[s] = true;
        recStack.push_back(s);
        
        int v = edges[s];
        if(v!=-1 && visited[v] == false){
            return DFS(edges, v, visited, recStack);
        }
        else if(find(recStack.begin(), recStack.end(), v) != recStack.end()){ //if the element is present in the current recursion stack
            int index = find(recStack.begin(), recStack.end(), v) - recStack.begin(); //finding the position of the element in the recursion stack
            return recStack.size() - index ;
        }  
        return -1;
    }
public:
    int longestCycle(vector<int>& edges) {
        int V = edges.size();
        vector<bool> visited(V, false);
        
        int count = -1;
        for(int i=0; i<V; i++){
            vector<int> recStack; //to store elements in the current recursion stack
            if(visited[i] == false){
                count = max(count, DFS(edges, i, visited, recStack));
            }
        }
        return count;
    }
};