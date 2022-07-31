/*
Author: Harshit Tiwari
Date: 29-06-2022
https://leetcode.com/problems/number-of-islands/
*/

// BFS Solution

class Solution {
    void BFS(vector<vector<char>>& grid, int i, int j){
        int row = grid.size();
        int col = grid[0].size();
        
        //utility arrays for traversing the adjacent nodes
        vector<int> rowNbr = {1,-1, 0, 0};
        vector<int> colNbr = {0, 0, 1, -1};
        
        queue<pair<int, int>> q;

        //Pushing source node in the queue
        q.push(make_pair(i,j));
        grid[i][j] = '0';
        
        while(!q.empty()){
            int k = q.front().first;
            int l = q.front().second;
            q.pop();
            //traversing the adjacent nodes for a particular node
            for(int t=0; t<4; t++){ 

            	//checking if the node lies within the range of the matrix
                if((k+rowNbr[t])<0 || (l+colNbr[t])<0 || (k+rowNbr[t])>(row-1) || (l+colNbr[t])>(col-1))
                    continue;

                if(grid[k+rowNbr[t]][l+colNbr[t]] == '1'){
                    q.push(make_pair(k+rowNbr[t], l+colNbr[t]));
                    grid[k+rowNbr[t]][l+colNbr[t]] = '0';
                }
            }
        }
        
        return;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int count = 0;
        
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j] == '1'){
                	// doing BFS by considering this as source node
                    BFS(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
};