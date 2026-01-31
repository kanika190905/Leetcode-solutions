class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxi=-1;
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi,i+nums[i]);
            if(nums[i]==0 && maxi==i) break;
        }
        return maxi>=nums.size()-1;
    }
};