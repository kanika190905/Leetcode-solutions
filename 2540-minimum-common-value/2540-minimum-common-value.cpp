class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size(),i=0,j=0;
        while(i<n && j<m){
           if(nums2[j]>nums1[i]){
            i++;
           }
           else if(nums2[j]<nums1[i]){
            j++;
           }
           if(i<n && j<m && nums2[j]==nums1[i]) return nums1[i];
        }
        return -1;
    }
};