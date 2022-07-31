/*
Author: Harshit Tiwari
Date: 28-06-2022
https://leetcode.com/problems/number-of-islands/
*/

//DFS Solution

class Solution {
    void DFS(vector<vector<char>>& grid, int i, int j){
        int row = grid.size();
        int col = grid[0].size();
        
        //checking if the node lies within the range of the matrix
        if(i<0 || j<0 || i>(row-1) || j>(col-1))
            return;
        
        if(grid[i][j] == '1'){
            grid[i][j] = '0';
            DFS(grid, i-1, j);
            DFS(grid, i+1, j);
            DFS(grid, i, j-1);
            DFS(grid, i, j+1);
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
                    grid[i][j] = '0'; 
                    // Doing DFS in all the 4 directions
                    DFS(grid, i-1, j);
                    DFS(grid, i+1, j);
                    DFS(grid, i, j-1);
                    DFS(grid, i, j+1);
                    count++;
                }
            }
        }
        return count;
    }
};