/*
Author: Harshit Tiwari
Date: 04-08-2022
https://leetcode.com/problems/surrounded-regions/
*/


class Solution {
    void DFS(vector<vector<char>>& board, int i, int j){
        int m = board.size();
        int n = board[0].size();
        
        if(board[i][j] == 'X')
            return;
        
        vector<int> rowNbr = {1, -1, 0, 0};
        vector<int> colNbr = {0, 0, 1, -1};
        
        board[i][j] = '/'; //any cell reachable from a boundary cell is marked as not flippable.
        
        //traversing the adjacent cells
        for(int k=0; k<4; k++){
            if((i+rowNbr[k])<0 || (j+colNbr[k])<0 || (i+rowNbr[k])>(m-1) || (j+colNbr[k])>(n-1))
                continue;
            if(board[i+rowNbr[k]][j+colNbr[k]] == 'O'){
                DFS(board, i+rowNbr[k], j+colNbr[k]);
            }
        }
        return;
    }
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        for(int j=0; j<n; j++){
            DFS(board, 0, j); //DFS for 1st row cells
            DFS(board, m-1, j); //DFS for last row cells
        }
        
        for(int i=0; i<m; i++){
            DFS(board, i, 0); //DFS for 1st column cells
            DFS(board, i, n-1);//DFS for last column cells
        }
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == 'O') //'O's which were not reachable from boundary cells flipped to 'X'
                    board[i][j] = 'X';
                if(board[i][j] == '/') //not flippable cells marked as 'O' again
                    board[i][j] = 'O';
            }
        }
        
        return;
    }
};