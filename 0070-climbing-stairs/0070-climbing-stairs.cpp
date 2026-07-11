class Solution {
public:
    int noOfWays(int i,int n,vector<vector<int>>& dp){
        if(n==0){
            return 1;
        }
        if(n<0) return 0;
        if(dp[i][n]!=-1) return dp[i][n];
        int take1=noOfWays(i+1,n-1,dp);
        int take2=noOfWays(i+2,n-2,dp);
        return dp[i][n]=take1+take2;
    }
    int climbStairs(int n) {
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return noOfWays(0,n,dp);
    }
};