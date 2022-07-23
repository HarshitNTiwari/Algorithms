/*
Author: Harshit Tiwari
Date: 21-06-2022
https://leetcode.com/problems/first-bad-version/
*/



// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long int ans = 0;
        long long int low = 1, high = n;
        while(low<=high){
            long long int mid = (low+high)/2;
            if(isBadVersion(mid)){
                ans = mid;
                if(mid == 1 || !isBadVersion(mid-1))
                    return ans;
                high = mid-1;
            }
            else
                low = mid+1;
        }
        return ans;
    }
};