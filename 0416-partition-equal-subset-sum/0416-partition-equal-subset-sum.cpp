class Solution {
public:
    bool helper(int i,vector<int>& nums,int target,vector<vector<int>>& dp){
        if(target==0) return true;
        if(i>=nums.size()) return false;
        if(dp[i][target]!=-1) return dp[i][target];
        int notTake=helper(i+1,nums,target,dp);
        int take=false;
        if(nums[i]<=target){
            take=helper(i+1,nums,target-nums[i],dp);
        }
        return dp[i][target]=take|notTake;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int x:nums){
            sum+=x;
        }
        if(sum%2!=0) return false;
        vector<vector<int>> dp(nums.size(),vector<int>(sum+1,-1));
        return helper(0,nums,sum/2,dp);
    }
};