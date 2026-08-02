class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1,vector<int>(nums.size()+1,0));
        for(int idx=nums.size()-1;idx>=0;idx--){
            for(int prev_idx=idx-1;prev_idx>=-1;prev_idx--){
                
                int take=INT_MIN;
                 if(prev_idx==-1 || nums[prev_idx]<nums[idx]){
                    take=1+dp[idx+1][idx+1];
                }
                int notTake=dp[idx+1][prev_idx+1];
                dp[idx][prev_idx+1]=max(take,notTake);
            }
        }
        return dp[0][0];
    }
};