class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum%2!=0) return false;
        vector<vector<bool>> dp(nums.size(),vector<bool>((sum/2)+1,0));
        for(int i=0;i<nums.size();i++){
            dp[i][0]=true;
        }
       if(nums[0] <= sum/2)
            dp[0][nums[0]] = true;
        for(int ind=1;ind<nums.size();ind++){
            for(int target=1;target<=sum/2;target++){
                bool notTake=dp[ind-1][target];
                bool take=false;
                if(nums[ind]<=target){
                take=dp[ind-1][target-nums[ind]];
            }
            dp[ind][target]=take|notTake;
            }
        }
        return dp[nums.size()-1][sum/2];
    }
};