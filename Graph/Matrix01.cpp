/*
Author: Harshit Tiwari
Date: 29-06-2022
https://leetcode.com/problems/01-matrix/
*/

//This problem is solved using Mutlisource BFS

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        queue<pair<int, int>> q;
        vector<vector<int>> ans(m, vector<int>(n, -1));

        // consider all the 0s as source nodes.
        //So as per multisource bfs, we'll first push all the 0s to the queue
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] == 0){
                    ans[i][j] = 0;
                    q.push(make_pair(i, j));
                }
            }
        }

        vector<int> rowNbr = {1, -1, 0, 0};
        vector<int> colNbr = {0, 0, 1, -1};

        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            for(int k =0; k<4; k++){
                if((i+rowNbr[k])<0 || (j+colNbr[k])<0 || (i+rowNbr[k])>(m-1) || (j+colNbr[k])>(n-1))
                    continue;

                if(ans[i+rowNbr[k]][j+colNbr[k]] == -1){
                    ans[i+rowNbr[k]][j+colNbr[k]] = ans[i][j] + 1;
                    q.push(make_pair(i+rowNbr[k], j+colNbr[k]));
                }
            }
        }

        return ans;
    }
};