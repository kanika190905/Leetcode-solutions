class Solution {
public:
int cnt=0;
    int helper(int i,vector<int>& coins, int amount,vector<vector<int>>& dp){
        if(amount==0){
            return 1;
        }
        if(i<0){
            return 0;
        }
        if(dp[i][amount]!=-1) return dp[i][amount];
        int take=0;
        if(coins[i]<=amount)
         take=helper(i,coins,amount-coins[i],dp);
        int notTake=helper(i-1,coins,amount,dp);
        return dp[i][amount]=take+notTake;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
       return helper(coins.size()-1,coins,amount,dp);
        
    }
};