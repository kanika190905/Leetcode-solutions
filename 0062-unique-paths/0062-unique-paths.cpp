class Solution {
public:
   
   int helper(int i,int j,int m,int n,vector<vector<int>>& dp){
        if(i<0 || j<0 || i>=m|| j>=n) return 0;
        if(i==m-1 && j==n-1){
           
            return 1;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int right=helper(i+1,j,m,n,dp);
        int down=helper(i,j+1,m,n,dp);
        return dp[i][j]=right+down;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,0));
        dp[m-1][n-1]=1;
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i == m-1 && j == n-1)
            continue;
                int right=0,down=0;
              if(i+1<m)
              right=dp[i+1][j];
              if(j+1<n)
               down=dp[i][j+1];
              dp[i][j]=right+down;  
            }
        }
     return dp[0][0];
     
    }
};