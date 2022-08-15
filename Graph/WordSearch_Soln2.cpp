/*
Author: Harshit Tiwari
Date: 31-06-2022
https://leetcode.com/problems/word-search/
*/

/* NOTE:
The correct but TLE solution is given in : Graph/WordSearch_Soln1.cpp
The differences in this solution from the Soln_1 to do search pruning are follows, and 'all' of these changes are required to remove TLE:
1.) before initial DFS call is made, we check board[i][j] == word[0]
2.) Most imp: Instead of maintaining visited matrix, we change the current visited character in the 'board' matrix itself and then reset it back after DFS is done. This reduces SC as well.
3.) For traversing the adjacent cells four-directionally, instead of using for-loop make DFS calls individually for the four cells.
4.) Instead of calculating values of 'm' and 'n' inside each DFS call, write board.size() and board[0].size()! Something as trivial as this was also a cause of TLE.

Note that none of these changes cause any logical change to the solution. The core technique i.e. DFS remains same in both the solutions.
*/


class Solution {
    bool DFS(vector<vector<char>>& board, string& word, int si, int sj, int k){
        
        if(k == word.size())
            return true;
        
        if(si<0 || sj<0 || si>(board.size()-1) || sj>(board[0].size()-1) || board[si][sj] != word[k])
            return false;
        
        board[si][sj] = '*';  //marking the current character visited
            
        bool ans = DFS(board, word, si+1, sj, k+1) || DFS(board, word, si-1, sj, k+1) || DFS(board, word, si, sj+1, k+1) || DFS(board, word, si, sj-1, k+1);

        board[si][sj] = word[k]; //resetting the cell with the same character as before
        
        return ans;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n= board[0].size();
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == word[0] && DFS(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }
};