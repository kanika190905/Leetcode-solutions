class Solution {
public:

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    vector<vector<long long>> dp(obstacleGrid.size(),vector<long long>(obstacleGrid[0].size(),0));
    int m=obstacleGrid.size();
    int n=obstacleGrid[0].size();
    if(obstacleGrid[m-1][n-1] == 1)
    return 0;
        dp[m-1][n-1]=1;
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i == m-1 && j == n-1)
            continue;
            if(obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                    continue;
                }
                long long right=0,down=0;
              if(i+1<m )
              right=dp[i+1][j];
              if(j+1<n )
               down=dp[i][j+1];
              dp[i][j]=right+down;  
            }
        }
     return dp[0][0];
     
    }
};