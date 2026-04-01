class Solution {
public:
    int helper(int i,vector<int>& coins, int amount,vector<vector<int>>& dp){
        if(amount==0){
            return 0;
        }
        if(i<0){
            return 1e9;
        }
        if(dp[i][amount]!=-1) return dp[i][amount];
        int take=INT_MAX;
        if(coins[i]<=amount)
         take=1+helper(i,coins,amount-coins[i],dp);
        int notTake=helper(i-1,coins,amount,dp);
        return dp[i][amount]=min(take,notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        if(helper(coins.size()-1,coins,amount,dp)==1e9){
           return -1;
        }
        else return helper(coins.size()-1,coins,amount,dp);

    }
};