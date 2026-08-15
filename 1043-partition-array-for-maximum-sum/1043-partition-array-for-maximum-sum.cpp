class Solution {
public:
    int solve(int i,int k,vector<int>& nums,vector<int>& dp){
        if(i==nums.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int maxi=0;
        int ans=0;
        for(int j=i;j<min(i+k,(int)nums.size());j++){
            maxi=max(maxi,nums[j]);
            int curr_sum=(j-i+1)*maxi +solve(j+1,k,nums,dp);
            ans=max(ans,curr_sum);
        }
        return dp[i]=ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size(),-1);
        return solve(0,k,arr,dp);
    }
};