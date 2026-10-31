class Solution {
public:
    const int MOD=1e9+7;
    int solve(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp){
        int m=grid.size(),n=grid[0].size();
        if(i==grid.size()-1 && j==grid[0].size()-1){
            return 1;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        long long ans=0; 
        int x=i+1,y=j;
        bool goingDown = true;
        while(x<m && y<n && grid[x][y]==1){
            if (goingDown) y++;   
            else x++;            
            goingDown = !goingDown; 
        }
        if (x < m && y < n)
            ans = (ans + solve(x, y, grid,dp)) % MOD;
            

        x=i, y=j+1;
        bool goingRight = true;
        while(x<m && y<n && grid[x][y]==1){
            if (goingRight) x++;   
            else y++;              
            goingRight = !goingRight; 
        }
        if (x < m && y < n)
            ans = (ans + solve(x, y, grid,dp)) % MOD;
        return dp[i][j]=ans;
    }
    int uniquePaths(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
        return solve(0,0,grid,dp);
    }
};