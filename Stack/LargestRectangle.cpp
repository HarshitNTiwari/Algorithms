/*
Author: Harshit Tiwari
Date: 05-11-2022
https://leetcode.com/problems/largest-rectangle-in-histogram/
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int ans = 0;
        heights.push_back(0);
        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[i] <= heights[st.top()]) {
                int top = st.top();
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                ans = max(ans, (width) * heights[top]);
            }
            st.push(i);
        }
        return ans;
    }
};