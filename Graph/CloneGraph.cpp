/*
Author: Harshit Tiwari
Date: 01-07-2022
https://leetcode.com/problems/clone-graph/
*/


/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    Node* DFS(Node* snode, unordered_map<Node*, Node*>& mp){
        
        //creating the copy of the current source node
        Node* newNode = new Node(snode->val);
        mp[snode] = newNode;  //marking the current source node as cloned by storing the copied node as value corresponding to the source node 
        
        vector<Node*> neighbours;
        
        //copying the adjacent nodes from the neighbors list of source node into the neighbours list of copied node
        int n = snode->neighbors.size();
        for(int i=0; i<n; i++){
            if(mp.find(snode->neighbors[i]) != mp.end()) //i.e. this adjacent node has been already been cloned, so no need to clone again
                neighbours.push_back(mp[snode->neighbors[i]]); //simply store the already cloned value into neighbours list
            else
                neighbours.push_back(DFS(snode->neighbors[i], mp)); //make a recursive call to clone the adjacent node, then store into the neighbours list
        }
        newNode->neighbors = neighbours;
        return newNode;
    }
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> mp; //map to store if a node has already been copied
        
        // if 1st node is NULL, i.e. empty graph
        if(node==NULL)
            return NULL;
        
        Node* newNode = new Node(node->val);
        if(node->neighbors.size()==0) //if there's just one 1 node i.e. it has no neighbors
            return newNode;
        
        return DFS(node, mp);
    }
};