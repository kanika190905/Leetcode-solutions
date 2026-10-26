class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
       vector<int> v(1e4+1,0);
       int l=0,r=0;
       int rsum=0;
       int maxi=0;
       while(l<=r && r<nums.size()){
        v[nums[r]]++;
        rsum+=nums[r];
        while(v[nums[r]]>1){
            v[nums[l]]--;
            rsum-=nums[l];
            l++;
        }
        maxi=max(maxi,rsum);
        r++;
       }
       return maxi;
    }
};