class Solution {
public:
     const int mod=1e9+7;
    int solve(int i,int steps,int cur,int len,vector<vector<int>>& dp){
        if(cur==steps && i==0){
            return 1;
        }
        else if(cur==steps){
            return 0;
        }
        if(dp[i][cur]!=-1) return dp[i][cur];
        int right=0,left=0;
        if(i+1<len)
        right=solve(i+1,steps,cur+1,len,dp);

        if(i-1>=0)
        left=solve(i-1,steps,cur+1,len,dp);

        int stay=solve(i,steps,cur+1,len,dp);
        return dp[i][cur]=(1LL *right+left+stay)%mod;
    }
    int numWays(int steps, int arrLen) {
        int n = min(arrLen, steps + 1);
        vector<vector<int>> dp(n,vector<int>(steps+1,-1));
        return solve(0,steps,0,arrLen,dp);
    }
};