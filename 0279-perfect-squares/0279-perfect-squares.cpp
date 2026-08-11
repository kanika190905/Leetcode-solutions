class Solution {
public:
    int solve(int i,int n,vector<int>& nums,vector<vector<int>>& dp){
        if(n==0) return 0;
        if(i<0) return INT_MAX;
        if(dp[n][i]!=-1) return dp[n][i];
        int notTake=solve(i-1,n,nums,dp);
        int take=INT_MAX;
        if(nums[i]<=n){
            take=1+solve(i,n-nums[i],nums,dp);
        }
        return dp[n][i]=min(take,notTake);
    }
    int numSquares(int n) {
        vector<int> nums;
        for(int i=1;i*i<=n;i++){
            int sq=i*i;
            nums.push_back(sq);
        }
        int s=nums.size()-1;
        vector<vector<int>> dp(n+1,vector<int>(s+1,-1));
        return solve(s,n,nums,dp);
    }
};