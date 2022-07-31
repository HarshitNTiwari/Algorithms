/*
Author: Harshit Tiwari
Date: 31-06-2022
https://leetcode.com/problems/count-number-of-nice-subarrays/
*/

// Solved using prefix sum technique

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> prefixOdd;
        
        int odd=0; int ans=0;  //'odd' to count the number of odd numbers till the current index and 'ans' to store final ans
        for(int i=0; i<nums.size(); i++){
        	// prefix[odd] represents the no. of subarrays which have 'odd' no. of odd nos. till their end 
            prefixOdd[odd]++;
            
            if(nums[i]%2!=0){
                odd++;
            }
            
            if(odd>=k){  //when number of odd numbers till the current index becomes >= k
                int x = odd - k;
                //if there's a subarray which has 'odd-k' no. of odd nos, 
                //then the subarray starting from the end of this subarray till the current index will have exactly 'k' odd nos and is counted in the ans
                ans += prefixOdd[x];
            }
        }
        
        return ans;
    }
};