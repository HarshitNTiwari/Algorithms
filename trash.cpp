#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2);
int bSearch(vector<int> nums, int x);

int main(){
    vector<int> nums1{53,48,14,71,31,55,6,80,28,19,15,40,7,21,69,15,5,42,86,15,11,54,44,62,9,100,2,26,81,87,87,18,45,29,46,100,20,87,49,86,14,74,74,52,52,60,8,25,21,96,7,90,91,42,32,34,55,20,66,36,64,67,44,51,4,46,25,57,84,23,10,84,99,33,51,28,59,88,50,41,59,69,59,65,78,50,78,50,39,91,44,78,90,83,55,5,74,96,77,46};
    vector<int> nums2{39,49,64,34,80,26,44,3,92,46,27,88,73,55,66,10,4,72,19,37,40,49,40,58,82,32,36,91,62,21,68,65,66,55,44,24,78,56,12,79,38,53,36,90,40,73,92,14,73,89,28,53,52,46,84,47,51,31,53,22,24,14,83,75,97,87,66,42,45,98,29,82,41,36,57,95,100,2,71,34,43,50,66,52,6,43,94,71,93,61,28,84,7,79,23,48,39,27,48,79};

    cout<<minAbsoluteSumDiff(nums1, nums2);
    return 0;
}

int bSearch(vector<int> nums, int x){
    sort(nums.begin(),nums.end());
    if(x < nums[0]) {
        return nums[0];
    }
    if(x > nums[nums.size()-1]) {
        return nums[nums.size()-1];
    }
    int low=0; int high=nums.size()-1;
    int g=0;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]==x)
            return nums[mid];
        else if(nums[mid]>x)
            high=mid-1;
        else{
            int temp=low;
            low=mid+1;
            if(low==high)
                return nums[temp];
        }
        g=mid;
    }
    return (nums[low] - x) < (x - nums[high]) ? nums[low] : nums[high];
}

int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
    int ans=abs(nums1[0]-nums2[0]); 
    int t =0;
    int k= abs(nums1[0]-nums2[0]);
    for(int i=1; i<nums1.size(); i++){
        ans= ans+ abs(nums1[i]-nums2[i]);
        if(abs(nums1[i]-nums2[i])>k){
            k=abs(nums1[i]-nums2[i]);
            t=i;
        }
    }
    
    cout<<"ans: "<<ans<<endl;
    cout<<"nums2[t]: "<<nums2[t]<<endl;
    int m= bSearch(nums1, nums2[t]);
    cout<<"m: "<<m<<endl;
    cout<<"t: "<<t<<endl;

    for(int i=0; i<nums1.size(); i++){
        cout<<nums1[i]<<" ";
    }
    cout << endl;
    for(int i=0; i<nums1.size(); i++){
        cout<<nums2[i]<<" ";
    }

    cout << "nums1[t] = " << nums1[t] << endl;
    cout << "nums2[t] = " << nums2[t] << endl;

    cout<<(abs(nums1[t]-nums2[t]))<<endl;
    return ans= ans-(abs(nums1[t]-nums2[t]))+(abs(m-nums2[t]));
}