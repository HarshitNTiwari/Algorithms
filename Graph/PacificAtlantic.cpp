/*
Author: Harshit Tiwari
Date: 04-08-2022
https://leetcode.com/problems/pacific-atlantic-water-flow/
*/


class Solution {
    void DFS(vector<vector<int>>& heights, int i, int j, vector<vector<bool>>& visited){
        int m = heights.size();
        int n = heights[0].size();
        
        if(visited[i][j]) //if already true, return
            return;
        
        vector<int> rowNbr = {1, -1, 0, 0};
        vector<int> colNbr = {0, 0, 1, -1};
        
        visited[i][j] = true; //marking the current cell as visited for that particular ocean
       
        //traversing four-directionally
        for(int k=0; k<4; k++){
            if((i+rowNbr[k])<0 || (j+colNbr[k])<0 || (i+rowNbr[k])>(m-1) || (j+colNbr[k])>(n-1))
                continue;
            //since we're going from cells near to ocean to cells farther from ocean, we see if the adjacent cell is 'greater than or equal to' current cell
            else if(heights[i+rowNbr[k]][j+colNbr[k]] >= heights[i][j]){
                DFS(heights, i+rowNbr[k], j+colNbr[k], visited);
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        
        vector<vector<int>> ans;
        
        vector<vector<bool>> visitPacific(m, vector<bool>(n, false));
        vector<vector<bool>> visitAtlantic(m, vector<bool>(n, false));
        
        for(int j=0; j<n; j++){
            DFS(heights, 0, j, visitPacific); //DFS for 1st row; cells directly connected to pacific
            DFS(heights, m-1, j, visitAtlantic); //DFS for last row; cells directly connected to atlantic
        }
        
        for(int i=0; i<m; i++){
            DFS(heights, i, 0, visitPacific); //DFS for 1st column; cells directly connected to pacific
            DFS(heights, i, n-1, visitAtlantic); //DFS for last column; cells directly connected to atlantic
        }
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(visitPacific[i][j] && visitAtlantic[i][j]){ //if that cell can visit both the ocean
                    ans.push_back({i, j});  //pushing the coordinates in the answer
                }
            }
        }
        return ans;
    }
};