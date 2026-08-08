class Solution {
public:

    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int x:nums){
            sum+=x;
        }
        if(sum%2!=0) return false;
        vector<vector<bool>> dp(nums.size(),vector<bool>(sum/2+1,0));
        for(int i=0;i<nums.size();i++){
            dp[i][0]=true;
        }
        if(nums.back() <= sum/2)
    dp[nums.size()-1][nums.back()] = true;
        for(int i=nums.size()-2;i>=0;i--){
            for(int target=1;target<=sum/2;target++){
                int notTake=dp[i+1][target];
                int take=false;
        if(nums[i]<=target)
            take=dp[i+1][target-nums[i]];
             dp[i][target]=take|notTake;
            }
        }
        return dp[0][sum/2];

    }
};