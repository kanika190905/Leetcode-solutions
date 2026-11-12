class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans=1,l=1,l2=1;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]){
                l++;
                ans=max(l,ans);
            }
            else{
                l=1;
            }
        }
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]<nums[i+1]){
                l2++;
                ans=max(l2,ans);
            }
            else{
                l2=1;
            }
        }
        return ans;
    }
};