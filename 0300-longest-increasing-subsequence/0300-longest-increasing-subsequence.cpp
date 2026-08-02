class Solution {
public:
    int helper(int idx,int prev_idx,vector<int>& nums,vector<vector<int>> & dp){
        if(idx>=nums.size()){
            return 0;
        }
        if( dp[idx][prev_idx+1]!=-1){
            return dp[idx][prev_idx+1];
        }
        int take=INT_MIN;
        if(prev_idx==-1 || nums[prev_idx]<nums[idx]){
            take=1+helper(idx+1,idx,nums,dp);
        }
        int notTake=helper(idx+1,prev_idx,nums,dp);
        return dp[idx][prev_idx+1]=max(take,notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size(),-1));
        return helper(0,-1,nums,dp);
    }
};