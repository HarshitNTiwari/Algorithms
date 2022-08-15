/*
Author: Harshit Tiwari
Date: 02-07-2022
https://leetcode.com/problems/max-area-of-island/
*/


class Solution {
    int DFS(vector<vector<int>>& grid, int i, int j){
        int m = grid.size();
        int n = grid[0].size();
        
        vector<int> rowNbr = {1, -1, 0, 0};
        vector<int> colNbr = {0, 0, 1, -1};
        
        int count =1;
        for(int k=0; k<4; k++){
            if((i+rowNbr[k])<0 || (j+colNbr[k])<0 || (i+rowNbr[k])>(m-1) || (j+colNbr[k])>(n-1))
                continue;
            if(grid[i+rowNbr[k]][j+colNbr[k]] == 1){
                grid[i+rowNbr[k]][j+colNbr[k]] = 0;
                count += DFS(grid, i+rowNbr[k], j+colNbr[k]);
            }
        }
        
        return count;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int count = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    grid[i][j] = 0;
                    count = max(count, DFS(grid, i, j));
                }
            }
        }
        return count;
    }
};