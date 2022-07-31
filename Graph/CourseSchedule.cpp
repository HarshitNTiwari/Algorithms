/*
Author: Harshit Tiwari
Date: 30-06-2022
https://leetcode.com/problems/course-schedule/
*/

//This problem is solved using cycle detection using topological sorting


class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

    	// Storing the number of courses each course is dependent on
        vector<int> indegree(numCourses, 0);
        for(int i=0; i<prerequisites.size(); i++){
            indegree[prerequisites[i][0]]++;
        }
        
        // Storing all the courses which are dependent on a particular course in a map
        unordered_map<int, vector<int>> preq;
        for(int i=0; i<prerequisites.size(); i++){
            if(preq.find(prerequisites[i][1]) == preq.end())
                preq[prerequisites[i][1]] = vector<int>();
            preq[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        // Doing BFS based topological sorting
        queue<int> q;
        for(int i =0; i<numCourses; i++)
            if(indegree[i] == 0)
                q.push(i);
        
        int count = 0;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int v : preq[u]){
                indegree[v]--;
                if(indegree[v] == 0)
                    q.push(v); 
            }
            count++;
        }

        return (count==numCourses);
    }
};