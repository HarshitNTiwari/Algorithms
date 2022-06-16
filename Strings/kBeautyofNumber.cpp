/*
Author: Harshit Tiwari
Date: 15-06-2022
https://leetcode.com/problems/find-the-k-beauty-of-a-number/
*/

// This is solved using sliding window technique.

class Solution {
public:
    int divisorSubstrings(int num, int k) {
        int ans = 0;
        int i = 0; int j = k;
        string str;
        string numstr = to_string(num); //converting the num to a string
        for (int i = 0; i < k; i++) {
            char c = numstr[i];
            str.push_back(c);  //creating a string of length of 'k' from num
        }
        int x = stoi(str);
        if (num % x == 0)
            ans++;
        while (j < numstr.size()) {
            str.erase(0, 1);  //removing 1st element from string of length 'k'
            char c = numstr[j];
            str.push_back(c);  //appending next element
            x = stoi(str);
            if (x != 0 && num % x == 0)
                ans++;
            j++;
        }
        return ans;
    }
};