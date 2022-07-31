/*
Author: Harshit Tiwari
Date: 31-06-2022
https://leetcode.com/problems/maximum-number-of-groups-entering-a-competition/
*/


class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int count = 0;
        int n = grades.size();
        for(int i=1; i<=n; i++){
            if(n-i > i || n-i == 0){
                count++;
                n-=i;
            }
            else if(n-i<=i){
                count++;
                break;
            }
        }
        return count;
    }
};