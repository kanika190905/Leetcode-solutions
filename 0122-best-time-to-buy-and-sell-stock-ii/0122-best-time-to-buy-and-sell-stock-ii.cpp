class Solution {
public:
    int profit=0;
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size()+1,vector<int>(2,0));
        for(int i=prices.size()-1;i>=0;i--){
            for(int j=0;j<2;j++){
              if(j){
                dp[i][j]=max(-prices[i]+dp[i+1][0],dp[i+1][1]);
              }  
              else{
                dp[i][j]=max(prices[i]+dp[i+1][1],dp[i+1][0]);
              }
            }
        }
        return dp[0][1];
    }
};