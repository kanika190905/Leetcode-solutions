class Solution {
public:
    int profit=0;
    int f(int i,bool buy,int cap,vector<int>& prices,vector<vector<vector<int>>>& dp){
         if(cap==0) return 0;
        if(i==prices.size()){
            return 0;
        }
        if(dp[i][buy][cap]!=-1) return dp[i][buy][cap];
        if(buy){
            return dp[i][buy][cap]= max(-prices[i]+f(i+1,0,cap,prices,dp),f(i+1,1,cap,prices,dp));
        }
        else{
            return  dp[i][buy][cap]= max(prices[i]+f(i+1,1,cap-1,prices,dp),f(i+1,0,cap,prices,dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(2,vector<int>(3,-1)));
        return f(0,1,2,prices,dp);
    }
};