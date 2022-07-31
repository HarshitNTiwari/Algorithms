/*
Author: Harshit Tiwari
Date: 29-06-2022
https://leetcode.com/problems/flood-fill/
*/

// BFS Solution

class Solution {
    void BFS(vector<vector<int>>& image, int sr, int sc, int color){
        int row = image.size();
        int col = image[0].size();
        int srcColor = image[sr][sc];
        
        //utility arrays for traversing the adjacent nodes
        vector<int> rowNbr = {1, -1, 0, 0};
        vector<int> colNbr = {0, 0, 1, -1};
        
        queue<pair<int, int>> q;
        q.push(make_pair(sr, sc));
        image[sr][sc] = color;
        
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            //traversing the adjacent nodes for a particular node
            for(int k=0; k<4; k++){

            	//checking if the node lies within the range of the matrix
                if((i+rowNbr[k])<0 || (j+colNbr[k])<0 || (i+rowNbr[k])>(row-1) || (j+colNbr[k])>(col-1))
                    continue;
                if(image[i+rowNbr[k]][j+colNbr[k]] == srcColor){
                    q.push(make_pair(i+rowNbr[k], j+colNbr[k]));
                    image[i+rowNbr[k]][j+colNbr[k]] = color;
                }
            }
        }
        return;
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]!=color){
        	// doing BFS by considering this as source node
            BFS(image, sr, sc, color);
        }
        return image;
    }
};