/*
Author: Harshit Tiwari
Date: 31-06-2022
https://leetcode.com/problems/count-number-of-nice-subarrays/
*/

// This is solved using sliding window technique

class Solution {
    // function to calculate the no. of subarrays with number of odd nos. <=k
    int solve(vector<int>& nums, int k){

        int i=0, j=0; int odd =0; int ans =0;
        //'odd' to count the number of odd numbers in the current window and 'ans' to store final ans
        while(j < nums.size()){
            if(nums[j]%2!=0){
                odd++;
            }
            while(odd>k){  //while the number of odd nos. in the current window is more than k
                if(nums[i]%2!=0){
                    odd--;     
                }
                i++;   //reduce the window size
            }
            ans += j - i + 1; //counting and adding the no. of 'all' the subarrays in between j and i
            j++;
        }

        return ans;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        // Solve(nums, k) : returns the number of subarrays with 'atmost' k odd nos. 
        return (solve(nums, k) - solve(nums, k-1));
        // The above expression will give us the no. of subarrays with 'exactly' k odd nos.
    }
};