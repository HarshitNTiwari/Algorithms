/*
Author: Harshit Tiwari
Date: 31-06-2022
https://leetcode.com/problems/word-search/
*/


// NOTE: THIS SOLUTION WILL NOT GET ACCEPTED - Although this DFS logic is completely fine, extra search pruning is required to remove TLE.
// The time optimised accepted solution is in : Graph/WordSearch_Soln2.cpp


class Solution {
    bool DFS(vector<vector<char>>& board, string word, vector<vector<bool>>& visited, int si, int sj, int k){
        int m = board.size();
        int n= board[0].size();
        
        vector<int> rowNbr = {1, -1, 0, 0};
        vector<int> colNbr = {0, 0, 1, -1};
        
        if(!visited[si][sj] && board[si][sj] == word[k]){
            visited[si][sj] = true; //marking the current character visited
            if(k==word.size()-1)
                return true;
            bool ans = false;
            // traversing adjacent cells four-directionally
            for(int t=0; t<4; t++){
                if((si+rowNbr[t])<0 || (sj+colNbr[t])<0 || (si+rowNbr[t])>(m-1) || (sj+colNbr[t])>(n-1))
                    continue;
                ans = ans || DFS(board, word, visited, si+rowNbr[t], sj+colNbr[t], k+1);
            }
            visited[si][sj] = false; //resetting the current cell as not visited
            return ans;
        }
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n= board[0].size();
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                vector<vector<bool>> visited(m, vector<bool>(n, false));
                if(DFS(board, word, visited, i, j, 0))
                    return true;
            }
        }
        return false;
    }
};