class Solution {
public:
    int profit=0;
    int f(int i,bool buy,vector<int>& prices,vector<vector<int>>& dp){
        if(i==prices.size()){
            return 0;
        }
        if(dp[i][buy]!=-1) return dp[i][buy];
        if(buy){
            return dp[i][buy]= max(-prices[i]+f(i+1,0,prices,dp),f(i+1,1,prices,dp));
        }
        else{
            return  dp[i][buy]= max(prices[i]+f(i+1,1,prices,dp),f(i+1,0,prices,dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return f(0,1,prices,dp);
    }
};