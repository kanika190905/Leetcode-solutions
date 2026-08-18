class Solution {
public:
    int solve(int l,int r,vector<int> &nums,vector<vector<int>> &dp){
        if(l == r) return 0;
        int total=0,ans=INT_MIN;
        if(dp[l][r]!=-1) return dp[l][r];
        for(int i=l;i<=r;i++){
            total+=nums[i];
        }
        int left=0;

        for(int i=l;i<r;i++){
            left+=nums[i];
           int right=total-left;
           if(left>right){
            ans=max(ans,right+solve(i+1,r,nums,dp));
           }
           else if(right>left){
            ans=max(ans,left+solve(l,i,nums,dp));
           }
           else{
            ans=max({ans,left+solve(l,i,nums,dp),right+solve(i+1,r,nums,dp)});
           }
        }
        return dp[l][r]=ans;
    }
    int stoneGameV(vector<int>& stoneValue) {
        vector<vector<int>> dp(stoneValue.size(),vector<int>(stoneValue.size(),-1));
        return solve(0,stoneValue.size()-1,stoneValue,dp);
    }
};