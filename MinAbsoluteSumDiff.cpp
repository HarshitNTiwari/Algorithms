#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2);
int bSearch(vector<int> nums, int x);
int main(){
    vector<int> nums1;
    vector<int> nums2;
    int n; cin>>n;
    for(int i=0; i<n; i++){
        int k; cin>>k;
        nums1.push_back(k);
    }
    for(int i=0; i<n; i++){
        int k; cin>>k;
        nums2.push_back(k);
    }
    cout<< minAbsoluteSumDiff(nums1, nums2)<<endl;
}
int bSearch(vector<int> nums, int x){
    sort(nums.begin(),nums.end());
    int low=0; int high=nums.size()-1;
    int g=0;
    while(low<=high){
        int mid=(low+high)/2;
        if(nums[mid]==x)
            return nums[mid];
        else if(nums[mid]>x)
            high=mid-1;
        else
            low=mid+1;
        g=mid;
    }
    return nums[g];
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