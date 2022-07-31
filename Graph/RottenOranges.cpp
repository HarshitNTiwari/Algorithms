/*
Author: Harshit Tiwari
Date: 30-06-2022
https://leetcode.com/problems/rotting-oranges/
*/

//This problem is solved using Mutlisource BFS
//Here oranges which are rotten initially are considered as sources


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> time(m, vector<int>(n, -1));
        queue<pair<int, int>> q;

        // Pushing all the rotten oranges to the queue first
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2){
                    q.push(make_pair(i,j));
                    time[i][j] = 0;
                }
            }
        }
        
        vector<int> rowNbr = {1, -1, 0, 0};
        vector<int> colNbr = {0, 0, 1, -1};
        
        int minTime = 0;
        while(!q.empty()){
        	// Taking out a rotten orange from the queue
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            
            // Traversing the adjacents of a rotten orange
            for(int k=0; k<4; k++){
            	// if the considered node is out of bounds
                if((i+rowNbr[k])<0 || (j+colNbr[k])<0 || (i+rowNbr[k])>(m-1) || (j+colNbr[k])>(n-1))
                    continue;
                if(time[i+rowNbr[k]][j+colNbr[k]] == -1 && grid[i+rowNbr[k]][j+colNbr[k]]==1){
                    grid[i+rowNbr[k]][j+colNbr[k]] = 2;  //turning the fresh orange to rotten
                    time[i+rowNbr[k]][j+colNbr[k]] = time[i][j] + 1;  //storing the time for this orange to get rotten
                    minTime = max(minTime, time[i+rowNbr[k]][j+colNbr[k]]); //updating the answer time
                    q.push(make_pair(i+rowNbr[k], j+colNbr[k]));  //pushing the rotten orange to queue
                }
            }
        }
        
        // checking if any orange still remains fresh 
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1)
                    return -1;
            }
        } 
        
        return minTime;
    }
};