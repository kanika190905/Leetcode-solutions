class Solution {
public:
    int helper(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp){
        int n=grid.size();
        int m=grid[0].size();
        if(i>=n || j>=m) return 1e9;
        if(i==n-1 &&j==m-1) return grid[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int right=helper(i,j+1,grid,dp);
        int left=helper(i+1,j,grid,dp);
        return dp[i][j]=min(right,left)+grid[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
        return helper(0,0,grid,dp);
    }
};