class Solution {
public:
    int solve(int n,vector<int>& dp){
        if(n==0){
            return 0;
        }
        if((n&(n-1))==0) return 1;
        if(dp[n]!=-1) return dp[n];
        int low=1;
        while(low*2<n){
            low*=2;
        }
        int high=low*2;
        return dp[n]=1+min(solve(n-low,dp),solve(high-n,dp));
    }
    int minOperations(int n) {
        vector<int> dp(n + 1, -1);
        return solve(n,dp);
    }
};